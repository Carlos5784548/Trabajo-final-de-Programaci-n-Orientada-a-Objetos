#include "Lista_Grilla.h"
#include "Lista_Clientes.h"
#include <wx/msgdlg.h>
#include "Registro_Cliente_hijo.h"
#include <wx/grid.h>
#include "Modifico_cliente_hija.h"
#include "Ventana_registro_hija.h"
#include "Ventana_Modifico_Cliente.h"
#include "UtilsPagos.h"
#include "Pagos.h"
#include <wx/datetime.h>
#include "Pagos_hijos.h"
#include "HistorialPagos.h"
#include "wxfb_project.h"
#include "Asistencias.h"
#include "Lista_Asistencias.h"
#include "Clientes.h"
#include "Hija_estadisticas.h"
#include "Application.h"
#include "Ventana_Registro_principal.h"
/// para convertir un c-string, o una constante, a wxString
inline wxString c_to_wx(const char *c_str) { return wxString::From8BitData(c_str); }

/// para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) { return wxString::From8BitData(std_str.c_str()); }

/// para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) { return static_cast<const char*>(wx_str.To8BitData()); }




Lista_Grilla::Lista_Grilla(Lista_Clientes* listaClientes, HistorialPagos* historial, Lista_Asistencias* listaAsistencias)
	: Lista_Clientes_Grilla(nullptr),
	m_lista(listaClientes),
	m_historial(historial),
	m_listaAsistencias(listaAsistencias)
{
	int c_pers = m_lista->CantidadDatos();
	m_grilla->AppendRows(c_pers);
	for (int i = 0; i < c_pers; i++) CargarFila(i);
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
}

/**
* Toma los datos de un cliente desde la instancia de Lista_Clientes y los carga en su
* correspondiente fila de la m_grilla. Se usa al cargar por primera vez, al editar,
* o al agregar clientes. La m_grilla ya debe tener lugar, es decir, debe existir el
* renglón (estará vacío o tendrá basura).
* @param i el índice del cliente en el arreglo de la clase Lista_Clientes (en base 0)
**/

void Lista_Grilla::CargarFila(int i) {
	Clientes &p = (*m_lista)[i];
	m_grilla->SetCellValue(i, 0, std_to_wx(p.VerApellido() + ", " + p.VerNombre()));
	m_grilla->SetCellValue(i, 1, std_to_wx(std::to_string(p.Verdni())));
	m_grilla->SetCellValue(i, 2, std_to_wx(p.VerTelefono()));
	m_grilla->SetCellValue(i, 3, std_to_wx(p.VerActividad()));
}





void Lista_Grilla::clickBuscar( wxCommandEvent& event )  {
	// Buscar desde la fila actual
	int fila_actual = m_grilla->GetGridCursorRow();
	if (m_grilla->GetSelectedRows().GetCount() == 0) fila_actual = -1;
	
	int res = m_lista->BuscarApellidoYNombre(wx_to_std(txtBuscar->GetValue()), fila_actual + 1);
	
	// Si no encontró, buscar otra vez desde el principio
	if (res == NO_SE_ENCUENTRA)
		res = m_lista->BuscarApellidoYNombre(wx_to_std(txtBuscar->GetValue()), 0);
	
	if (res == NO_SE_ENCUENTRA) { // Si no hay ninguna coincidencia
		wxMessageBox("No se encontraron coincidencias");
	} else {
		m_grilla->SetGridCursor(res, 0); // Seleccionar
		m_grilla->SelectRow(res); // Seleccionar
	}
}



void Lista_Grilla::OnClickGrilla( wxGridEvent& event )  {

}

Lista_Grilla::~Lista_Grilla() {
	
}

/**
* Cuando se hace click en "Eliminar", primero se pide confirmacion, y en caso
* afirmativo se elimina la persona de la base de datos, y la fila de la tabla.
**/
void Lista_Grilla::Click_eliminar( wxCommandEvent& event )  {
	int fila_actual = m_grilla->GetGridCursorRow();
	int res = wxMessageBox(c_to_wx("¿Eliminar el registro?"),m_grilla->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		m_grilla->DeleteRows(fila_actual,1);
		m_lista->EliminarPersona(fila_actual);
		m_lista->Guardar();
	}
}


void Lista_Grilla::Click_agregar(wxCommandEvent& event) {
	// Crear y mostrar la ventana hija para registrar nuevo cliente
	Ventana_registro_hija nueva_ventana(this, m_lista);
	int cantidad_antes = m_lista->CantidadDatos(); // ?? antes de agregar
	
	if (nueva_ventana.ShowModal() == wxID_OK) {
		int cantidad_despues = m_lista->CantidadDatos(); // ?? después de agregar
		
		if (cantidad_despues > cantidad_antes) {
			// Se agregó correctamente un cliente
			m_grilla->AppendRows(1);
			int pos_nuevo = cantidad_despues - 1;
			CargarFila(pos_nuevo);
			m_grilla->SetGridCursor(pos_nuevo, 0);
			m_grilla->SelectRow(pos_nuevo);
			m_grilla->ClearSelection();
			m_grilla->ForceRefresh();
		} else {
			wxMessageBox("No se agregó ningún cliente nuevo.", "Advertencia", wxICON_WARNING);
		}
	}
}

/**
* Al hacer click en "Editar", se abre de forma modal la ventana para ver y/o
* modificar los datos. En forma modal significa que esta ventana espera a que 
* termine la otra. Cuando termina, el codigo de retorno me indica si la otra 
* ventana modifico o no los datos (el usuario puede hacer click en Agregar o
* en Cancelar) En caso afirmativo, esta ventana debe actualizar la m_grilla.
**/
void Lista_Grilla::Click_Modifica( wxCommandEvent& event )  {
	int fila_actual = m_grilla->GetGridCursorRow();
	if (fila_actual < 0 || fila_actual >= m_lista->CantidadDatos()) {
		wxMessageBox("Seleccione un cliente válido", "Error", wxICON_ERROR);
		return;
	}
	
	Ventana_Modifico_Cliente dlg(this, m_lista, fila_actual);
	if (dlg.ShowModal() == wxID_OK) {
		CargarFila(fila_actual);
		m_grilla->ForceRefresh();
	}
	
}

void Lista_Grilla::RegistrarPago( wxCommandEvent& event )  {
	int fila = m_grilla->GetGridCursorRow();
	
	if (fila < 0 || fila >= m_lista->CantidadDatos()) {
		wxMessageBox("Seleccione un cliente válido.", "Error", wxICON_ERROR);
		return;
	}
	
	// Obtener el cliente seleccionado
	Clientes& cliente = (*m_lista)[fila];
	HistorialPagos historial;
	// Abrir ventana hija de pagos y pasarle el cliente
	Pagos_hijos ventana_pago(this, cliente);
	ventana_pago.ShowModal();
	
	// Luego del cierre, podrías refrescar grillas si hiciste cambios visibles
	m_grilla->ForceRefresh();
}

void Lista_Grilla::VerEstadisticas( wxCommandEvent& event )  {
	if (!Application::esAdmin) {
		wxMessageBox("Acceso restringido. Solo administradores pueden ver estadísticas.", "Acceso denegado", wxICON_ERROR);
		return;
	}
	
	Hija_estadisticas* estadisticas = new Hija_estadisticas(this, m_lista, m_historial, m_listaAsistencias);
	estadisticas->Show();
	;

}

void Lista_Grilla::Asistencia( wxCommandEvent& event )  {
	int fila = m_grilla->GetGridCursorRow();
	
	if (fila < 0 || fila >= m_lista->CantidadDatos()) {
		wxMessageBox("Seleccione un cliente válido.", "Error", wxICON_ERROR);
		return;
	}
	
	// Obtener el cliente seleccionado
	Clientes& clienteActual = (*m_lista)[fila];
	
	int dni = clienteActual.Verdni();
	*m_historial = HistorialPagos("pagos.dat");
	int diasDisponibles = clienteActual.DiasDisponibles(*m_historial, *m_listaAsistencias);
	
	
	
	if (diasDisponibles <= 0) {
		wxMessageBox("Este cliente no tiene días disponibles. Debe abonar para continuar.", "Acceso denegado", wxICON_WARNING);
		return;
	}
	
	// Registrar asistencia
	wxDateTime hoy = wxDateTime::Now();
	std::string fecha = std::string(hoy.FormatISODate().mb_str());
	
	Asistencias nueva(dni, fecha);
	m_listaAsistencias->Agregar(nueva);
	m_listaAsistencias->Guardar();
	wxMessageBox("Asistencia registrada correctamente.\nDías restantes: " + std::to_string(diasDisponibles - 1), "Registro exitoso", wxICON_INFORMATION);
	
	
	
}

void Lista_Grilla::Registar( wxCommandEvent& event )  {
	Ventana_Registro_principal  *win = new Ventana_Registro_principal (NULL);
	win->Show();
}


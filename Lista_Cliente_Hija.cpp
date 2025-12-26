#include "Lista_Cliente_Hija.h"
#include "Clientes.h"
#include <wx/grid.h>
#include <wx/msgdlg.h>
#include "Lista_Clientes.h"
// Convertir std::string a wxString
wxString std_to_wx(const std::string& str) {
	return wxString::FromUTF8(str.c_str());
}

// Convertir wxString a std::string
std::string wx_to_std(const wxString& wxStr) {
	return std::string(wxStr.mb_str());
}
/**
* Inicializa la ventana, asignándole un icono, llenando la m_grilla y definiendo
* las propiedades adicionales de la tabla.
**/
Lista_Cliente_Hija::Lista_Cliente_Hija(Lista_Clientes *listaClientes) : m_lista(listaClientes) {
	// SetIcon(wxIcon(icono_xpm)); // Asignar un ícono si es necesario
	
	int c_pers = m_lista->CantidadDatos(); // Averiguar cuántas filas va a tener la tabla
	m_grilla->AppendRows(c_pers); // Agregar las filas (la tabla inicialmente está vacía)
	for (int i = 0; i < c_pers; i++) CargarFila(i); // Cargar todos los datos
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows); // Hacer que la selección sea por fila, y no por celda
}

/**
* Toma los datos de un cliente desde la instancia de Lista_Clientes y los carga en su
* correspondiente fila de la m_grilla. Se usa al cargar por primera vez, al editar,
* o al agregar clientes. La m_grilla ya debe tener lugar, es decir, debe existir el
* renglón (estará vacío o tendrá basura).
* @param i el índice del cliente en el arreglo de la clase Lista_Clientes (en base 0)
**/
void Lista_Cliente_Hija::CargarFila(int i) {
	Clientes &p = (*m_lista)[i];
	m_grilla->SetCellValue(i, 0, std_to_wx(p.VerApellido() + ", " + p.VerNombre()));
	m_grilla->SetCellValue(i, 1, std_to_wx(p.VerDireccion()));
	m_grilla->SetCellValue(i, 2, std_to_wx(p.VerTelefono()));
	m_grilla->SetCellValue(i, 3, std_to_wx(p.VerEmail()));
}

void Lista_Cliente_Hija::clickBuscar(wxCommandEvent& event) {
	// Buscar desde la fila actual
	int fila_actual = m_grilla->GetGridCursorRow();
	if (m_grilla->GetSelectedRows().GetCount() == 0) fila_actual = -1;
	
	int res = m_lista->BuscarApellidoYNombre(wx_to_std(m_busqueda->GetValue()), fila_actual + 1);
	
	// Si no encontró, buscar otra vez desde el principio
	if (res == NO_SE_ENCUENTRA)
		res = m_lista->BuscarApellidoYNombre(wx_to_std(m_busqueda->GetValue()), 0);
	
	if (res == NO_SE_ENCUENTRA) { // Si no hay ninguna coincidencia
		wxMessageBox("No se encontraron coincidencias");
	} else {
		m_grilla->SetGridCursor(res, 0); // Seleccionar
		m_grilla->SelectRow(res); // Seleccionar
	}
}

Lista_Cliente_Hija::~Lista_Cliente_Hija() {
	// Destructor
}

/**
* Si se hace clic en la cabecera de alguna columna, la tabla se ordena según
* ese dato. Para esto, se le pide a la lista de clientes que ordene, y luego
* se recargan los datos de todas las filas.
**/
void Lista_Cliente_Hija::OnClickGrilla(wxGridEvent& event) {
	int columna = event.GetCol();
	int c_pers = m_lista->CantidadDatos();
	
	switch (columna) { // Ordenar en la lista de clientes
	case 0: m_lista->Ordenar(ORDEN_APELLIDO_Y_NOMBRE); break;
	case 1: m_lista->Ordenar(ORDEN_DIRECCION); break;
	case 2: m_lista->Ordenar(ORDEN_TELEFONO); break;
	case 3: m_lista->Ordenar(ORDEN_EMAIL); break;
	}
	
	for (int i = 0; i < c_pers; i++) CargarFila(i); // Actualizar vista
}


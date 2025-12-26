#include "Ventana_Modifico_Cliente.h"
#include "Lista_Clientes.h"
#include <wx/msgdlg.h>
inline wxString std_to_wx(const std::string &std_str) {
	return wxString::FromUTF8(std_str.c_str());
}
/// para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) { return static_cast<const char*>(wx_str.To8BitData()); }
/*Recibe:
	Un puntero al padre de la ventana (parent).
	Un puntero a la lista de clientes (lista_clientes).
	El índice del cliente a modificar (indice).
	Inicializa:
	Llama al constructor base Ventana_Modifico.
	Guarda la lista y el índice en los atributos m_lista y m_indice.
	Carga los datos del cliente seleccionado en los controles de la ventana para que el usuario los pueda ver y modificar.*/

Ventana_Modifico_Cliente::Ventana_Modifico_Cliente(wxWindow *parent,Lista_Clientes* lista_clientes, int indice) : Ventana_Modifico(parent) , m_lista(lista_clientes), m_indice(indice) {
	Clientes& c = (*m_lista)[m_indice];
	txtNombre->SetValue(std_to_wx(c.VerNombre()));
	txtApellido->SetValue(std_to_wx(c.VerApellido()));
	txtTelefono->SetValue(std_to_wx(c.VerTelefono()));
	txtDirrecion->SetValue(std_to_wx(c.VerDireccion()));
	txtMail->SetValue(std_to_wx(c.VerEmail()));
	txtDni->SetValue(std_to_wx(std::to_string(c.Verdni())));
	Actividad->SetStringSelection(std_to_wx(c.VerActividad()));
}


void Ventana_Modifico_Cliente::cancelar( wxCommandEvent& event )  {
	EndModal(wxID_CANCEL);
}

Ventana_Modifico_Cliente::~Ventana_Modifico_Cliente() {
	
}

void Ventana_Modifico_Cliente::Actulizar( wxCommandEvent& event )  {
	if (!m_lista || m_indice < 0 || m_indice >= m_lista->CantidadDatos()) {
		wxMessageBox("Error interno: índice inválido", "Error", wxICON_ERROR);
		return;
	}
	
	Clientes& c = (*m_lista)[m_indice];
	
	// Asignar datos desde controles (conversión wxString -> std::string)
	c.ModificarNombre(wx_to_std(txtNombre->GetValue()));
	c.ModificarApellido(wx_to_std(txtApellido->GetValue()));
	c.ModificarTelefono(wx_to_std(txtTelefono->GetValue()));
	c.ModificarDireccion(wx_to_std(txtDirrecion->GetValue()));
	c.ModificarEmail(wx_to_std(txtMail->GetValue()));
	c.ModificarActividad(wx_to_std(Actividad->GetStringSelection()));
	
	// Validar y asignar DNI
	long dni;
	if (!txtDni->GetValue().ToLong(&dni)) {
		wxMessageBox("DNI inválido", "Error", wxICON_ERROR);
		return;
	}
	c.ModificarDni(dni);
	
	// Guardar en archivo
	if (!m_lista->Guardar()) {
		wxMessageBox("Error al guardar los datos", "Error", wxICON_ERROR);
		return;
	}
	
	wxMessageBox("Cliente actualizado correctamente", "Información", wxICON_INFORMATION);
	
	EndModal(wxID_OK);  // Cerrar diálogo con éxito
}


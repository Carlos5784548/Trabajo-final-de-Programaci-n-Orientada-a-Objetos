#include "RegistroCliente.h"
#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(RegistroCliente, MyDialog2)
	EVT_BUTTON(wxID_ANY, RegistroCliente::OnRegistrar) // Reemplazá wxID_ANY con el ID real si tenés
	EVT_BUTTON(wxID_CANCEL, RegistroCliente::OnCancelar)
	wxEND_EVENT_TABLE()
	
	// Constructor
	RegistroCliente::RegistroCliente(wxWindow* parent) : MyDialog2(parent) {
	txtNombre = txtNombre; // m_txtNombre viene de wxFormBuilder
	txtApellido =txtApellido;
	txtDni = txtDni;
	txtMail = txtMail;
	txtTelefono = txtTelefono;
	txtDireccion = txtDireccion;
	comboActividad = comboActividad;
} // ? CIERRO el constructor correctamente

// Destructor
RegistroCliente::~RegistroCliente() {
	// No hace falta liberar nada manualmente
}

// Evento: botón Registrar
void RegistroCliente::OnRegistrar(wxCommandEvent& event) {
	wxString nombre = txtNombre->GetValue();
	wxString apellido = txtApellido->GetValue();
	wxString dni = txtDni->GetValue();
	wxString mail = txtMail->GetValue();
	wxString telefono = txtTelefono->GetValue();
	wxString direccion = txtDireccion->GetValue();
	wxString actividad = comboActividad->GetValue();
	
	if (nombre.IsEmpty() || apellido.IsEmpty() || dni.IsEmpty()) {
		wxMessageBox("Por favor complete los campos obligatorios: Nombre, Apellido y DNI.", "Error", wxICON_ERROR);
		return;
	}
	
	wxString mensaje;
	mensaje << "Cliente registrado:\n\n"
		<< "Nombre: " << nombre << "\n"
		<< "Apellido: " << apellido << "\n"
		<< "DNI: " << dni << "\n"
		<< "Email: " << mail << "\n"
		<< "Teléfono: " << telefono << "\n"
		<< "Dirección: " << direccion << "\n"
		<< "Actividad: " << actividad;
	
	wxMessageBox(mensaje, "Registro Exitoso", wxICON_INFORMATION);
	
	EndModal(wxID_OK);
}

// Evento: botón Cancelar
void RegistroCliente::OnCancelar(wxCommandEvent& event) {
	EndModal(wxID_CANCEL);
}

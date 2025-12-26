#include "Registro_Cliente_hijo.h"
#include <wx/msgdlg.h>
#include <string>
#include "Clientes.h"
#include <wx/textctrl.h>
#include <fstream>
#include <iostream>
#include "Registro_Cliente_hijo.h"

wxBEGIN_EVENT_TABLE(Registro_Cliente_hijo, wxDialog)
	EVT_BUTTON(wxID_OK, Registro_Cliente_hijo::OnRegistrar)
	EVT_BUTTON(wxID_CANCEL, Registro_Cliente_hijo::OnCancelar)
	wxEND_EVENT_TABLE()
	
	Registro_Cliente_hijo::Registro_Cliente_hijo(wxWindow* parent) 
	: wxDialog(parent, wxID_ANY, "Agregar Persona", wxDefaultPosition, wxSize(300, 400)) {
	
	wxPanel* panel = new wxPanel(this);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	
	// Crear controles
	txtNombre = new wxTextCtrl(panel, wxID_ANY);
	txtApellido = new wxTextCtrl(panel, wxID_ANY);
	txtDni = new wxTextCtrl(panel, wxID_ANY);
	txtMail = new wxTextCtrl(panel, wxID_ANY);
	txtTelefono = new wxTextCtrl(panel, wxID_ANY);
	txtDireccion = new wxTextCtrl(panel, wxID_ANY);
	
	wxArrayString actividades;
	actividades.Add("Zumba");
	actividades.Add("Pilates");
	actividades.Add("Yoga");
	comboActividad = new wxComboBox(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, actividades);
	
	// Organizar en grid
	wxFlexGridSizer* gridSizer = new wxFlexGridSizer(2, 5, 5);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "NOMBRE"));
	gridSizer->Add(txtNombre, 1, wxEXPAND);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "APELLIDO"));
	gridSizer->Add(txtApellido, 1, wxEXPAND);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "DNI"));
	gridSizer->Add(txtDni, 1, wxEXPAND);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "MAIL"));
	gridSizer->Add(txtMail, 1, wxEXPAND);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "TELEFONO"));
	gridSizer->Add(txtTelefono, 1, wxEXPAND);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "DIRECCION"));
	gridSizer->Add(txtDireccion, 1, wxEXPAND);
	gridSizer->Add(new wxStaticText(panel, wxID_ANY, "ACTIVIDAD"));
	gridSizer->Add(comboActividad, 1, wxEXPAND);
	
	// Botones
	wxStdDialogButtonSizer* btnSizer = new wxStdDialogButtonSizer();
	btnSizer->AddButton(new wxButton(panel, wxID_OK, "Registrar"));
	btnSizer->AddButton(new wxButton(panel, wxID_CANCEL, "Cancelar"));
	btnSizer->Realize();
	
	// Layout principal
	sizer->Add(gridSizer, 1, wxEXPAND|wxALL, 10);
	sizer->Add(btnSizer, 0, wxALIGN_CENTER|wxBOTTOM, 10);
	
	panel->SetSizer(sizer);
}

void Registro_Cliente_hijo::OnRegistrar(wxCommandEvent& event) {
	// Validación básica
	if (txtNombre->GetValue().empty() || txtDni->GetValue().empty()) {
		wxMessageBox("Nombre y DNI son campos obligatorios", "Error", wxOK|wxICON_ERROR, this);
		return;
	}
	
	event.Skip(); // Permite que el diálogo se cierre con wxID_OK
}

void Registro_Cliente_hijo::OnCancelar(wxCommandEvent& event) {
	EndModal(wxID_CANCEL);
}

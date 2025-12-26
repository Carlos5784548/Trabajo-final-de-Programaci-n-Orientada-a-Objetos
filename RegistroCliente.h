#ifndef REGISTROCLIENTE_H
#define REGISTROCLIENTE_H
#include "wxfb_project.h"

class RegistroCliente : public MyDialog2 {
public:
	RegistroCliente (wxWindow* parent);
	 ~RegistroCliente(); 
	
private:
	wxTextCtrl *txtNombre, *txtApellido, *txtDni, *txtMail, *txtTelefono, *txtDireccion;
	wxComboBox *comboActividad;
	
	void OnRegistrar(wxCommandEvent& event);
	void OnCancelar(wxCommandEvent& event);
	
	wxDECLARE_EVENT_TABLE();
};

#endif


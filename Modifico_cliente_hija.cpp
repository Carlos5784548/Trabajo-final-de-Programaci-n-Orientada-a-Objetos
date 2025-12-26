#include "Modifico_cliente_hija.h"
#include <wx/msgdlg.h>
using namespace std;
/// para convertir un c-string, o una constante, a wxString
inline wxString c_to_wx(const char *c_str) { return wxString::From8BitData(c_str); }

/// para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) { return wxString::From8BitData(std_str.c_str()); }

/// para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) { return static_cast<const char*>(wx_str.To8BitData()); }
Modifico_cliente_hija::Modifico_cliente_hija(wxWindow *parent, Lista_Clientes *lista_clientes, int cual) : Modifico_cliente(parent), m_lista(lista_clientes), m_indice_cliente(cual) {
	Clientes &c=(*m_lista)[cual];
	txtnombre->SetValue( std_to_wx(c.VerNombre()) );
	txtapellido->SetValue( std_to_wx(c.VerApellido()) );
	txttelofono->SetValue( std_to_wx(c.VerTelefono()) );
	txtdni->SetValue( std_to_wx(c.VerDireccion()) );
	//txtdirrecion->SetValue( std_to_wx(c.VerLocalidad()) );
	txtmail->SetValue( std_to_wx(c.VerEmail()) );
	/*if (p.VerAnioNac()!=0) m_anio->SetValue( wxString()<<p.VerAnioNac() );
	if (p.VerMesNac()!=0) m_mes->SetValue( wxString()<<p.VerMesNac() );
	if (p.VerDiaNac()!=0) m_dia->SetValue( wxString()<<p.VerDiaNac() );/*¿¿*/
	
	btnVolver->SetLabel("Volver");
	btnGuardar->SetLabel("Guardar");
	SetTitle("Editar Persona");
}


Modifico_cliente_hija::~Modifico_cliente_hija() {
	
}

void Modifico_cliente_hija::Click_Guardar( wxCommandEvent& event )  {
	long dni; // convertir cadenas a numeros
	txtdni->GetValue().ToLong(&dni);

	Clientes p( // crear la instancia de persona
			  wx_to_std(txtnombre->GetValue()),
			  wx_to_std(txtapellido->GetValue()),
			  wx_to_std(txttelofono->GetValue()),
			  wx_to_std(txtdirrecion->GetValue()),
			  wx_to_std(txtmail->GetValue()),
			  dni);
	string errores = p.ValidarDatos();
	if (errores.size()) { // ver si no pasa la validacion
		// la conversión mediante wxString::From8BitData es porque usualmente 
		// los std::string utilizan una determinada codificacion para los 
		// caracteres (digamos ASCII), mientras que wxString otra (Unicode)
		wxMessageBox(std_to_wx(errores.c_str()),"Errores",wxOK|wxICON_ERROR,this); // mostrar errores
	} else {
		(*m_lista)[m_indice_cliente]=p; // agregar
		m_lista->Guardar(); // actualizar el archivo
	//	EndModal(1); // cerrar indicando que se agrego
}
}
	
	
void Modifico_cliente_hija::Click_Volver( wxCommandEvent& event )  {
	event.Skip();
}


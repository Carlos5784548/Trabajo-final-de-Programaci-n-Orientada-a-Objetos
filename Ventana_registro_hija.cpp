#include "Ventana_registro_hija.h"
#include <wx/msgdlg.h>
#include <string>
#include "Clientes.h"
#include <fstream>
#include "Lista_Clientes.h"
using namespace std;

Ventana_registro_hija::Ventana_registro_hija(wxWindow *parent,Lista_Clientes* lista_clientes) : Ventana_registro(parent),m_lista(lista_clientes) {
	



}
void Ventana_registro_hija::Agregar(wxCommandEvent& event) {
	// Obtener wxStrings
	wxString nombreWx = txtNombre->GetValue();
	wxString apellidoWx = txtApellido->GetValue();
	wxString dniWx = txtDni->GetValue();
	wxString mailWx = txtMail->GetValue();
	wxString telefonoWx = txtTelefono->GetValue();
	wxString direccionWx = txtDirrecion->GetValue();
	wxString actividadWx = Actividad->GetValue();
	wxString mensaje;
	
	// Convertir a std::string
	std::string nombre = std::string(nombreWx.mb_str());
	std::string apellido = std::string(apellidoWx.mb_str());
	std::string mail = std::string(mailWx.mb_str());
	std::string telefono = std::string(telefonoWx.mb_str());
	std::string direccion = std::string(direccionWx.mb_str());
	std::string actividad = std::string(actividadWx.mb_str());
	
	if (nombre.empty() || apellido.empty()) {
		wxMessageBox("Por favor complete los campos obligatorios.", "Error", wxICON_ERROR);
		return;
	}
	// Convertir DNI a entero
	long dni;
	if (!dniWx.ToLong(&dni)) {
		wxMessageBox("DNI inválido. Ingresá un número entero.", "Error", wxICON_ERROR);
		return;
	}
	Clientes nuevo(nombre, apellido, telefono, direccion, mail, dni, actividad);	
	m_lista->AgregarCliente(nuevo);
	std::ofstream archivo("clientes.dat", std::ios::binary | std::ios::app); // modo append para no sobreescribir
	nuevo.GuardarEnBinario(archivo);
	archivo.close();
	std::cout << "Cliente guardado con éxito\n";
	mensaje << "Cliente registrado:\n\n"
		<< "Nombre: " << nuevo.VerNombre() << "\n"
		<< "Apellido: " << nuevo.VerApellido()<< "\n"
		<< "DNI: " << nuevo.Verdni()<< "\n"
		<< "Email: " << nuevo.Verdni() << "\n"
		<< "Teléfono: " << nuevo.VerTelefono() << "\n"
		<< "Dirección: " << nuevo.VerDireccion() << "\n"
		<< "Actividad: " << nuevo.VerActividad();
	
	wxMessageBox(mensaje, "Registro Exitoso", wxICON_INFORMATION);
	txtNombre->SetValue("");
	txtApellido->SetValue("");
	txtTelefono->SetValue("");
	txtDirrecion->SetValue("");
	txtMail->SetValue("");
	txtDni->SetValue("");
	Actividad->SetSelection(-1);
	EndModal(wxID_OK);
}

	
	// Evento: botón Cancelar
	void Ventana_registro_hija::cancelar(wxCommandEvent& event) {
		EndModal(wxID_CANCEL);
	}
	


Ventana_registro_hija::~Ventana_registro_hija() {
	
}


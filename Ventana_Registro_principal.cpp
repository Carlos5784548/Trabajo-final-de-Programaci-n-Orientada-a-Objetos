#include "Ventana_Registro_principal.h"
#include "Vetana_Login_Principal.h"

#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <wx/msgdlg.h>

Ventana_Registro_principal::Ventana_Registro_principal(wxWindow *parent) : Ventana_Registro(parent) {
	
}

Ventana_Registro_principal::~Ventana_Registro_principal() {
	
}

void Ventana_Registro_principal::registro( wxCommandEvent& event )  {
	std::string username_registro = txt_registro_usu->GetValue().ToStdString(); // Obtener el nombre de usuario
	std::string password_registro= txt_registro_contra->GetValue().ToStdString();// Obtener la contraseña
	bool esAdmin = si->GetValue(); // Retorna true si "Sí" está seleccionado, false si "No" está seleccionado
	if (Agrego_usuario(username_registro,password_registro,esAdmin)) { // Verificar credenciales
		error_r->SetLabel("¡El Usuario se registro correctamente!"); // Mensaje de éxito
		Vetana_Login_Principal *abro=new Vetana_Login_Principal(NULL);
		abro->Show();
		
	}
	
	
}


bool Ventana_Registro_principal::Agrego_usuario(const std::string &Usu, const std::string &contr, bool admin) {
	// Validación: No permitir campos vacíos
	if (Usu.empty() || contr.empty()) {
		wxMessageBox("Error: Usuario o contraseña no pueden estar vacíos.",  "Advertencia",
					 wxICON_WARNING, 
					 this);
		
		return false;
	}
	
	
	
	// Cargar usuarios existentes desde el archivo

	std::vector<Usuario> usuarios = Vetana_Login_Principal::Cargo_usuario();
	for (const auto& user : usuarios) {
		if (std::strcmp(user.nombre, Usu.c_str()) == 0) {
			wxMessageBox("Error: El usuario ya está registrado.", 
						 "Advertencia", 
						 wxICON_WARNING | wxOK, 
						 this);
			return false;
		}
	}
	// Crear nuevo usuario
	Usuario nuevoUsuario;
	std::strncpy(nuevoUsuario.nombre, Usu.c_str(), sizeof(nuevoUsuario.nombre) - 1);
	nuevoUsuario.nombre[sizeof(nuevoUsuario.nombre) - 1] = '\0'; // Asegurar terminación nula
	std::strncpy(nuevoUsuario.contra, contr.c_str(), sizeof(nuevoUsuario.contra) - 1);
	nuevoUsuario.contra[sizeof(nuevoUsuario.contra) - 1] = '\0';
	nuevoUsuario.rol = admin;
	
	// Guardar en el archivo
	std::ofstream archivoEscritura("Credenciales.dat", std::ios::binary | std::ios::app);
	if (!archivoEscritura) {
		std::cout << "Error: No se pudo abrir el archivo para escribir." << std::endl;
		return false;
	}
	
	archivoEscritura.write(reinterpret_cast<const char*>(&nuevoUsuario), sizeof(Usuario));
	archivoEscritura.close();
	wxMessageBox("Usuario registrado con éxito.",  "Advertencia",
				 wxICON_WARNING | wxOK, 
				 this);
	return true;
}


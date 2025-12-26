#include "Vetana_Login_Principal.h"
#include <fstream>
#include "Ventana_Registro_principal.h"
#include "Lista_Asistencias.h"
#include "Lista_Clientes.h"
#include "HistorialPagos.h"
#include "Lista_Grilla.h"
#include "Application.h"
Vetana_Login_Principal::Vetana_Login_Principal(wxWindow *parent) : Ventana_Login(parent) {

}

void Vetana_Login_Principal::Ingresar(wxCommandEvent& event) {
	std::string username = txtUsu->GetValue().ToStdString();
	std::string password = txtContra->GetValue().ToStdString();
	
	if (Verificar_Usuario(username, password)) {
		error->SetLabel("¡Inicio de sesión exitoso!");
		
		// Cargar datos desde archivos binarios
		Lista_Clientes* m_lista = new Lista_Clientes("clientes.dat");
		HistorialPagos* historial = new HistorialPagos("pagos.dat");
		Lista_Asistencias* asistencias = new Lista_Asistencias("asistencias.dat");
		
		Lista_Grilla* ventanaGrilla = new Lista_Grilla(m_lista, historial, asistencias);
		ventanaGrilla->Show();
		
		this->Close();
	} else {
		error->SetLabel("Credenciales incorrectas.");
	}
}






Vetana_Login_Principal::~Vetana_Login_Principal() {
	
}









bool Vetana_Login_Principal::Verificar_Usuario(const std::string &Usu, const std::string &contr) {
	std::vector<Usuario> lista = Cargo_usuario();
	for (int i = 0; i < lista.size(); i++) {
		std::string nombre_usuario(lista[i].nombre);
		std::string contrasena_usuario(lista[i].contra);
		
		if (nombre_usuario == Usu && contrasena_usuario == contr) {
			Application::esAdmin = lista[i].rol;  // ?? ? ESTA ES LA ASIGNACIÓN CORRECTA
			return true;
		}
	}
	return false;
}



std::vector<Usuario> Vetana_Login_Principal::Cargo_usuario() {
	std::vector<Usuario> cargados;
	Usuario c;
	std::ifstream archi("Credenciales.dat", std::ios::binary | std::ios::ate);
	
	if (!archi) {
		return cargados; // retorna vector vacío si hay error
		
	}
	
	// Calculamos cantidad de usuarios
	int total_usuarios = archi.tellg() / sizeof(Usuario);
	archi.seekg(0, std::ios::beg); // Volvemos al inicio del archivo
	
	for(int i = 0; i < total_usuarios; i++) { 
		archi.read(reinterpret_cast<char*>(&c), sizeof(Usuario));
		cargados.push_back(c); // push_back en lugar de pop_back
	}
	
	archi.close();
	return cargados;
}




#include "Lista_Clientes.h"
#include <fstream>
#include <Algorithm>
#include "Utils.h"
using namespace std;

// Constructor: carga los clientes desde el archivo binario al crear el objeto.
Lista_Clientes::Lista_Clientes(std::string a_nombre_archivo) {
	nombre_archivo = a_nombre_archivo;
	
	ifstream archivo(nombre_archivo.c_str(),std::ios::binary|std::ios::ate);
	if (archivo.is_open()) {
		int tamanio_archivo = archivo.tellg();
		int cantidad_clientes = tamanio_archivo/sizeof(registro_Cliente);
		arreglo.resize(cantidad_clientes);
		archivo.seekg(0,std::ios::beg);
		for (int i=0;i<cantidad_clientes;i++)
			arreglo[i].LeerDesdeBinario(archivo);
		archivo.close();
	}
	
}
// Muestra todos los clientes por consola (nombre, apellido y DNI).
void Lista_Clientes::MostrarPorConsola() {
	for (int i = 0; i < CantidadDatos(); ++i) {
		 Clientes& c = VerCliente(i); // o como accedas al cliente
		std::cout << "Cliente " << i + 1 << ":\n";
		std::cout << "  Nombre: " << c.VerNombre() << "\n";
		std::cout << "  Apellido: " << c.VerApellido() << "\n";
		std::cout << "  DNI: " << c.Verdni() << "\n";
		std::cout << "-------------------------\n";
	}
}
// Busca un cliente por DNI y devuelve un puntero al cliente (o nullptr si no existe).
Clientes* Lista_Clientes::BuscarPorDni(int dni) {
	for (int i = 0; i < arreglo.size(); ++i) {
		if (arreglo[i].Verdni() == dni) {
			return &arreglo[i];
		}
	}
	return nullptr;
}




// Guarda todos los clientes en el archivo binario. Devuelve true si tuvo éxito.
bool Lista_Clientes::Guardar() {
	ofstream archivo(nombre_archivo.c_str(),std::ios::binary|std::ios::trunc);
	if (!archivo.is_open()) return false;
	int cantidad_personas = CantidadDatos();
	for (int i=0;i<cantidad_personas;i++)
		arreglo[i].GuardarEnBinario(archivo);
	archivo.close();
	return true;
}
// Acceso por índice (permite usar lista[i] para obtener un cliente).
Clientes &Lista_Clientes::operator[](int i) {
	return arreglo[i];
}

// Devuelve una referencia al cliente en la posición i.
Clientes &Lista_Clientes::VerCliente(int i) {
	return arreglo[i];
}
// Devuelve la cantidad de clientes almacenados.
int Lista_Clientes::CantidadDatos(){
	return arreglo.size();
}

// Agrega un nuevo cliente a la lista.
void Lista_Clientes::AgregarCliente(const Clientes &c) {
	arreglo.push_back(c);
}

// Busca un cliente por parte del apellido y nombre (insensible a mayúsculas/minúsculas), desde una posición dada.
// Devuelve el índice o NO_SE_ENCUENTRA.
int Lista_Clientes::BuscarApellidoYNombre(std::string parte, int pos_desde) {
	pasar_a_minusculas(parte);
	int cant = CantidadDatos();
	for (int i=pos_desde;i<cant;i++) {
		Clientes &c = arreglo[i];
		std::string apenom = c.VerApellido()+", "+c.VerNombre();
		pasar_a_minusculas(apenom);
		if (apenom.find(parte,0)!=std::string::npos)
			return i;
	}
	return NO_SE_ENCUENTRA;
}
// Ordena la lista de clientes según el criterio especificado (apellido y nombre, teléfono, dirección o email).
void Lista_Clientes::Ordenar(CriterioOrden criterio) {
	switch (criterio) {
	case ORDEN_APELLIDO_Y_NOMBRE: 
		sort(arreglo.begin(),arreglo.end(),criterio_comparacion_apellido_y_nombre); 
		break;
	case ORDEN_TELEFONO: 
		sort(arreglo.begin(),arreglo.end(),criterio_comparacion_telefono); 
		break;
	case ORDEN_DIRECCION: 
		sort(arreglo.begin(),arreglo.end(),criterio_comparacion_direccion); 
		break;
	case ORDEN_EMAIL: 
		sort(arreglo.begin(),arreglo.end(),criterio_comparacion_email); 
		break;
	};
}
// Elimina el cliente en la posición i.
void Lista_Clientes::EliminarPersona(int i) {
	arreglo.erase(arreglo.begin()+i);
}

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct registro_Cliente {
	char nombre[256];
	char apellido[256];
	char telefono[256];
	char direccion[256];
	char localidad[256];
	char email[256];
	int dni;
	char actividad[256];
};
int main(int argc, char *argv[]) {
	
		// Vector para almacenar los registros de clientes
		std::vector<registro_Cliente> clientes;
	
	// Abrir el archivo binario para lectura
	std::ifstream archivo("pagos.dat", std::ios::binary);
	if (!archivo) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return 1;
	}
	
	// Leer los registros del archivo y almacenarlos en el vector
	registro_Cliente cliente;
	while (archivo.read(reinterpret_cast<char*>(&cliente), sizeof(registro_Cliente))) {
		clientes.push_back(cliente);
	}
	
	// Cerrar el archivo
	archivo.close();
	
	// Mostrar los datos almacenados
	std::cout << "Datos de los clientes almacenados:" << std::endl;
	for (const auto& c : clientes) {
		std::cout << "Nombre: " << c.nombre << std::endl;
		std::cout << "Apellido: " << c.apellido << std::endl;
		std::cout << "Teléfono: " << c.telefono << std::endl;
		std::cout << "Dirección: " << c.direccion << std::endl;
		std::cout << "Localidad: " << c.localidad << std::endl;
		std::cout << "Email: " << c.email << std::endl;
		std::cout << "DNI: " << c.dni << std::endl;
		std::cout << "Actividad: " << c.actividad << std::endl;
		std::cout << "-----------------------------------" << std::endl;
	}
	
	return 0;
}


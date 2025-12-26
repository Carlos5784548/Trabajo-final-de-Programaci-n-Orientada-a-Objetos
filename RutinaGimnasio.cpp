#include "RutinaGimnasio.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
struct rutina_registro{
	int codigo;
	char nombre[60]; // Arreglo de caracteres para el nombre
	int hora; // Hora en formato HHMM
	double precio;
};

RutinaGimnasio::RutinaGimnasio(int codigo, const string& nombre, int hora, double precio): codigo(codigo), hora(hora), precio(precio)   {
}
RutinaGimnasio::RutinaGimnasio() : codigo(0), nombre(""), hora(0), precio(0.0) {}
// Métodos de acceso (getters)
int RutinaGimnasio::getCodigo() const {
	return codigo;
}

std::string RutinaGimnasio::getNombre() const {
	return std::string(nombre);
}

int RutinaGimnasio::getHora() const {
	return hora;
}

double RutinaGimnasio::getPrecio() const {
	return precio;
}

// Métodos de modificación (setters)
void RutinaGimnasio::setCodigo(int codigo) {
	this->codigo = codigo;
}

void RutinaGimnasio::setNombre(const std::string& nombre) {
	this->nombre;
}

void RutinaGimnasio::setHora(int hora) {
	this->hora = hora;
}

void RutinaGimnasio::setPrecio(double precio) {
	this->precio = precio;
}

// Método para mostrar la rutina
void RutinaGimnasio::mostrar() const {
	std::cout << "Código: " << codigo << ", Nombre: " << nombre
		<< ", Hora: " << hora << ", Precio: " << precio << std::endl;
}

// Método para guardar en archivo binario
void RutinaGimnasio::guardarEnBinario(std::ofstream& archivo) const {
	// Asignar valores a la nueva estructura
	rutina_registro rutina;
	rutina.codigo = codigo; // Asumiendo que 'codigo' es un entero que ya tienes
	strncpy(rutina.nombre, nombre.c_str(), sizeof(rutina.nombre) - 1);
	rutina.nombre[sizeof(rutina.nombre) - 1] = '\0'; // Asegurar que esté terminado en null
	rutina.hora = hora; // Asumiendo que 'hora' es un entero en formato HHMM
	rutina.precio = precio; // Asumiendo que 'precio' es un double que ya tienes
	// Aquí puedes agregar cualquier otra lógica que necesites para trabajar con la estructura 'rutina'
	archivo.write((char*)&rutina, sizeof(rutina));
}

// Método para leer desde archivo binario
void RutinaGimnasio::leerDesdeBinario(std::ifstream& archivo) {
	rutina_registro reg;
	// Leer el registro completo desde el archivo
	archivo.read(reinterpret_cast<char*>(&reg), sizeof(reg));
	// Asignar los datos a las variables de la clase
	codigo = reg.codigo;
	nombre = reg.nombre; // Asignación directa a std::string
	hora = reg.hora;
	precio = reg.precio;
	// Asegurarse de que el nombre esté terminado en null
	reg.nombre[sizeof(reg.nombre) - 1] = '\0'; // Esto asegura que el nombre esté null-terminado
}

/*int main() {
	// Crear un objeto RutinaGimnasio
	RutinaGimnasio rutina(1, "Rutina de Entrenamiento", 10, 50.0);
	
	// Mostrar la rutina
	std::cout << "Rutina original:" << std::endl;
	rutina.mostrar();
	
	// Guardar la rutina en un archivo binario
	std::ofstream archivo("rutina.bin", std::ios::binary);
	if (!archivo) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return 1;
	}
	rutina.guardarEnBinario(archivo);
	archivo.close();
	
	// Leer la rutina desde el archivo binario
	ifstream archivoLeer("rutina.bin", std::ios::binary);
	if (!archivoLeer) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return 1;
	}
	RutinaGimnasio rutinaLeida;
	rutinaLeida.leerDesdeBinario(archivoLeer);
	archivoLeer.close();
	
	// Mostrar la rutina leída
	std::cout << "Rutina leída:" << std::endl;
	rutinaLeida.mostrar();
	
	return 0;
}*/

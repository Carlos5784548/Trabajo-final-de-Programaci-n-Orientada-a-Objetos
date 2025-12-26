#include "RutinaGimnasio_Lista.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "RutinaGimnasio.h"
using namespace std;

RutinaGimnasio_Lista::RutinaGimnasio_Lista() {
	
}
// Método para agregar una rutina
void RutinaGimnasio_Lista::agregarRutina(const RutinaGimnasio& rutina) {
	rutinas.push_back(rutina);
}

// Método para eliminar una rutina por código
void RutinaGimnasio_Lista::eliminarRutina(int codigo) {
	rutinas.erase(
	remove_if(rutinas.begin(), rutinas.end(),
[codigo](const RutinaGimnasio& r) { return r.getCodigo() == codigo; }),
				  rutinas.end());
}

// Método para modificar una rutina por código
void RutinaGimnasio_Lista::modificarRutina(int codigo, const RutinaGimnasio& nuevaRutina) {
	for (auto& rutina : rutinas) {
		if (rutina.getCodigo() == codigo) {
			rutina = nuevaRutina;
			break;
		}
	}
}

// Método para guardar en archivo binario
void RutinaGimnasio_Lista::guardarEnArchivo(const std::string& nombreArchivo) const {
	std::ofstream archivo(nombreArchivo, std::ios::binary);
	if (!archivo) {
		cout<< "Error al abrir el archivo para guardar." << std::endl;
		return;
	}
	
	for (const auto& rutina : rutinas) {
		rutina.guardarEnBinario(archivo);
	}
	
	archivo.close();
}

// Método para cargar desde archivo binario
void RutinaGimnasio_Lista::cargarDesdeArchivo(const std::string& nombreArchivo) {
	std::ifstream archivo(nombreArchivo, std::ios::binary);
	if (!archivo) {
		std::cerr << "Error al abrir el archivo para cargar." << std::endl;
		return;
	}
	rutinas.clear(); // Limpiar la lista actual
//RutinaGimnasio rutina;
	
	while (archivo.peek() != EOF) {
	//	rutina.leerDesdeBinario(archivo);
		//rutinas.push_back(rutina);
	}
	
	archivo.close();
}

// Método para listar todas las rutinas
void RutinaGimnasio_Lista::listarRutinas() const {
	for (const auto& rutina : rutinas) {
		rutina.mostrar();
	}
}

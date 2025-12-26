#include "Lista_Asistencias.h"
#include "Asistencias.h"
#include <fstream>

// Constructor: inicializa la lista de asistencias y carga los datos desde el archivo binario.
Lista_Asistencias::Lista_Asistencias(std::string archivo) : nombre_archivo(archivo) {
	Cargar();
}

// Agregar(): agrega una nueva asistencia a la lista en memoria (no la guarda en archivo hasta llamar a Guardar).
void Lista_Asistencias::Agregar(const Asistencias& a) {
	asistencias.push_back(a);
}

// Guardar(): guarda todas las asistencias de la lista en el archivo binario, sobrescribiendo el contenido anterior.
void Lista_Asistencias::Guardar() {
	std::ofstream archivo(nombre_archivo, std::ios::binary | std::ios::trunc);
	for (const auto& a : asistencias)
		a.GuardarEnBinario(archivo);
	archivo.close();
}

// Cargar(): lee todas las asistencias del archivo binario y las carga en la lista en memoria.
void Lista_Asistencias::Cargar() {
	asistencias.clear();
	std::ifstream archivo(nombre_archivo, std::ios::binary);
	if (!archivo.is_open()) return;
	
	while (archivo) {
		Asistencias a;
		a.LeerDesdeBinario(archivo);
		if (!archivo) break;  // evita cargar basura si falla la lectura
		asistencias.push_back(a);
	}
	archivo.close();
}

// VerDeCliente(): devuelve un vector con todas las asistencias de un cliente específico (por DNI).
std::vector<Asistencias> Lista_Asistencias::VerDeCliente(int dni) const {
	std::vector<Asistencias> filtradas;
	for (const auto& a : asistencias)
		if (a.VerDni() == dni)
			filtradas.push_back(a);
	return filtradas;
}

// CantidadDeAsistencias(): devuelve la cantidad de asistencias registradas para un cliente específico (por DNI).
int Lista_Asistencias::CantidadDeAsistencias(int dni) const {
	int contador = 0;
	for (const auto& a : asistencias)
		if (a.VerDni() == dni)
			contador++;
	return contador;
}

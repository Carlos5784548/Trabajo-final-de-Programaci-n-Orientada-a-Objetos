#include "HistorialPagos.h"
#include <fstream>
// Constructor: inicializa el historial de pagos cargando los datos desde el archivo binario.
HistorialPagos::HistorialPagos(const std::string& archivo)
	: nombre_archivo(archivo) {
	Cargar();
}
// Cargar(): Lee todos los pagos almacenados en el archivo binario y los carga en el vector 'pagos'.
void HistorialPagos::Cargar() {
	std::ifstream archivo(nombre_archivo.c_str(), std::ios::binary | std::ios::ate);
	if (!archivo.is_open()) return;
	
	int tamanio_archivo = archivo.tellg();
	int cantidad_pagos = tamanio_archivo / sizeof(registro_Pago);
	pagos.resize(cantidad_pagos);
	
	archivo.seekg(0, std::ios::beg);
	for (int i = 0; i < cantidad_pagos; ++i) {
		pagos[i].LeerDesdeBinario(archivo);
	}
	
	archivo.close();
}
// Guardar(): Escribe todos los pagos del vector 'pagos' en el archivo binario, sobrescribiendo el contenido anterior.
void HistorialPagos::Guardar() {
	std::ofstream out(nombre_archivo, std::ios::binary | std::ios::trunc);
	for (const Pagos& p : pagos) {
		p.GuardarEnBinario(out);
	}
	out.close();
}

// AgregarPago(): Agrega un nuevo pago al vector 'pagos' (no lo guarda automáticamente en el archivo).
void HistorialPagos::AgregarPago(const Pagos& p) {
	pagos.push_back(p);
}
// CantidadPagos(): Devuelve la cantidad total de pagos almacenados en el historial.
int HistorialPagos::CantidadPagos() const {
	return pagos.size();
}

//PagosDeCliente(): Devuelve un vector con todos los pagos realizados por un cliente específico (por DNI).
std::vector<Pagos> HistorialPagos::PagosDeCliente(int dni) const {
	std::vector<Pagos> resultado;
	for (const Pagos& p : pagos) {
		if (p.VerDniCliente() == dni) {
			resultado.push_back(p);
		}
	}
	return resultado;
}


// TotalPagadoPorCliente(): Calcula el monto total pagado por un cliente específico (por DNI).
double HistorialPagos::TotalPagadoPorCliente(int dni) const {
	double total = 0.0;
	for (const Pagos& p : pagos) {
		if (p.VerDniCliente() == dni) {
			total += p.VerMonto();
		}
	}
	return total;
}
// VerTodos(): Devuelve una referencia constante al vector con todos los pagos almacenados.
const std::vector<Pagos>& HistorialPagos::VerTodos() const {
	return pagos;
}

#include "Asistencias.h"
#include <cstring>
#include <fstream>
#include <string>
// Constructor: inicializa una asistencia con el DNI del cliente y la fecha.
Asistencias::Asistencias(int dni, const std::string& fecha) : dni_cliente(dni), fecha(fecha) {}
Asistencias::Asistencias() {}
// VerDni(): Devuelve el DNI del cliente asociado a la asistencia.
int Asistencias::VerDni() const { return dni_cliente; }
// VerFecha(): Devuelve la fecha de la asistencia como string.
std::string Asistencias::VerFecha() const { return fecha; }
// GuardarEnBinario(): Guarda la asistencia en un archivo binario usando la estructura registro_Asistencia.
void Asistencias::GuardarEnBinario(std::ofstream& archivo) const {
	registro_Asistencia reg;
	reg.dni_cliente = dni_cliente;
	std::strncpy(reg.fecha, fecha.c_str(), sizeof(reg.fecha) - 1);
	reg.fecha[sizeof(reg.fecha) - 1] = '\0';
	archivo.write((char*)&reg, sizeof(reg));
}
// LeerDesdeBinario(): Lee una asistencia desde un archivo binario y carga los datos en el objeto.
void Asistencias::LeerDesdeBinario(std::ifstream& archivo) {
	registro_Asistencia reg;
	archivo.read((char*)&reg, sizeof(reg));
	dni_cliente = reg.dni_cliente;
	fecha = reg.fecha;
}



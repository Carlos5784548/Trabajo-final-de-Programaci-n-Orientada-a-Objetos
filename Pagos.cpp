#include "Pagos.h"
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

Pagos::Pagos() {}
// Constructor: inicializa un pago con todos sus datos.
Pagos::Pagos(int dni, std::string a_fecha, double a_monto, std::string a_metodo_pago, int dias) {
	dni_cliente = dni;
	fecha = a_fecha;
	monto = a_monto;
	metodo_pago = a_metodo_pago;
	dias_pagados = dias; // Aquí sin int, para asignar al miembro
}


std::string Pagos::VerFecha() const { return fecha; }

double Pagos::VerMonto() const { return monto; }

std::string Pagos::VerMetodoPago() const { return metodo_pago; }
int Pagos::VerDiasPagados() const { return dias_pagados; }

int Pagos::VerDniCliente() const { return dni_cliente; }
// Métodos para modificar los datos del pago.
void Pagos::ModificarFecha(std::string a_fecha) { fecha = a_fecha; }
void Pagos::ModificarMonto(double a_monto) { monto = a_monto; }
void Pagos::ModificarMetodoPago(std::string a_metodo_pago) { metodo_pago = a_metodo_pago; }
void Pagos::ModificarDniCliente(int dni) { dni_cliente = dni; }

// Guarda el pago en un archivo binario usando la estructura registro_Pago.
void Pagos::GuardarEnBinario(std::ofstream& archivo)const  {
	registro_Pago reg;
	reg.dni_cliente = dni_cliente;
	reg.dias_paga=dias_pagados;
	strncpy(reg.fecha, fecha.c_str(), sizeof(reg.fecha) - 1);
	reg.fecha[sizeof(reg.fecha) - 1] = '\0';
	reg.monto = monto;
	strncpy(reg.metodo_pago, metodo_pago.c_str(), sizeof(reg.metodo_pago) - 1);
	reg.metodo_pago[sizeof(reg.metodo_pago) - 1] = '\0';
	archivo.write((char*)&reg, sizeof(reg));
}

// Lee un pago desde un archivo binario y carga los datos en el objeto.
void Pagos::LeerDesdeBinario(std::ifstream& archivo) {
	registro_Pago reg;
	archivo.read((char*)&reg, sizeof(reg));
	dni_cliente = reg.dni_cliente;
	fecha = reg.fecha;
	monto = reg.monto;
	metodo_pago = reg.metodo_pago;
	dias_pagados=reg.dias_paga;
}



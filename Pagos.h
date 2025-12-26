#ifndef PAGOS_H
#define PAGOS_H
#include <string>
struct registro_Pago {
	int dni_cliente;         // Relación con el cliente
	char fecha[11];          // Formato "YYYY-MM-DD"
	double monto;
	char metodo_pago[50]; // Efectivo, tarjeta, etc.
	int dias_paga;
};



class Pagos {
public:
	Pagos();
	Pagos(int dni, std::string a_fecha, double a_monto, std::string a_metodo_pago,int dias);
	
	std::string VerFecha() const;
	double VerMonto() const;
	std::string VerMetodoPago() const;
	int VerDniCliente() const;
	int VerDiasPagados() const;
	void ModificarFecha(std::string a_fecha);
	void ModificarMonto(double a_monto);
	void ModificarMetodoPago(std::string a_metodo_pago);
	void ModificarDniCliente(int dni);
	
	void GuardarEnBinario(std::ofstream& archivo)const ;
	void LeerDesdeBinario(std::ifstream& archivo);
private:
	int dni_cliente;
	std::string fecha;
	double monto;
	std::string metodo_pago;
	int dias_pagados;
};

#endif


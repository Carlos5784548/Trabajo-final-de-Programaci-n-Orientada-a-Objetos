#ifndef HISTORIALPAGOS_H
#define HISTORIALPAGOS_H
#include <vector>
#include <string>
#include "Pagos.h"

class HistorialPagos {
private:
	std::string nombre_archivo;
	std::vector<Pagos> pagos;
	
public:
	HistorialPagos(const std::string& archivo = "pagos.dat");
	
	void Cargar();
	void Guardar();
	
	void AgregarPago(const Pagos& p);
	std::vector<Pagos> PagosDeCliente(int dni) const;
	double TotalPagadoPorCliente(int dni) const;
	const std::vector<Pagos>&VerTodos() const;
	int CantidadPagos() const;
	
};

#endif


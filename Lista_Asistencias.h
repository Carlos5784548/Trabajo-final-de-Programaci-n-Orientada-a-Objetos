#ifndef LISTA_ASISTENCIAS_H
#define LISTA_ASISTENCIAS_H
#include "Asistencias.h"
#include <vector>

class Lista_Asistencias {
public:
	Lista_Asistencias(std::string archivo);
	void Agregar(const Asistencias& a);
	void Guardar();
	void Cargar();
	std::vector<Asistencias> VerDeCliente(int dni) const;
	int CantidadDeAsistencias(int dni) const;
private:
	std::vector<Asistencias> asistencias;
	std::string nombre_archivo;
};

#endif


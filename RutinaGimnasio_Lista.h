#ifndef RUTINAGIMNASIO_LISTA_H
#define RUTINAGIMNASIO_LISTA_H
#include <vector>
#include "RutinaGimnasio.h"
using namespace std;

class RutinaGimnasio_Lista {
public:
	RutinaGimnasio_Lista();
	// Métodos para ABM (Altas, Bajas, Modificaciones)
	void agregarRutina(const RutinaGimnasio& rutina);
	void eliminarRutina(int codigo);
	void modificarRutina(int codigo, const RutinaGimnasio& nuevaRutina);
	
	// Métodos para manejo de archivos binarios
	void guardarEnArchivo(const std::string& nombreArchivo) const;
	void cargarDesdeArchivo(const std::string& nombreArchivo);
	
	// Método para listar todas las rutinas
	void listarRutinas() const;
	
private:
	vector<RutinaGimnasio> rutinas; // Vector para almacenar las rutinas
};

#endif


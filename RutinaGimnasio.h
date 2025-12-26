#ifndef RUTINAGIMNASIO_H
#define RUTINAGIMNASIO_H
#include <string>
#include <fstream>
using namespace std;


class RutinaGimnasio {
public:
	RutinaGimnasio();
	RutinaGimnasio(int codigo, const std::string& nombre, int hora, double precio);
	
	// Métodos de acceso (getters)
	int getCodigo() const;
	string getNombre() const;
	int getHora() const;
	double getPrecio() const;
	
	// Métodos de modificación (setters)
	void setCodigo(int codigo);
	void setNombre(const string&nombre);
	void setHora(int hora);
	void setPrecio(double precio);
	
	// Método para mostrar la rutina
	void mostrar() const;
	
	// Métodos para manejo de archivos binarios
	void guardarEnBinario(std::ofstream& archivo) const;
	void leerDesdeBinario(std::ifstream& archivo);
private:
	int codigo;
	string nombre; // string para el nombre
	int hora; // Hora en formato HHMM
	double precio;
	
};

#endif



	

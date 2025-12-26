#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H
/// @brief constante para indicar que falló una búsqueda
#define NO_SE_ENCUENTRA -1
#include <vector>
#include "Clientes.h"
#include "wxfb_project.h"
#include "Lista_Clientes.h"


/// @brief enumeración para los posibles criterios de ordenamiento
/// es para pasar como argumento al método, queda más legible que un número
enum CriterioOrden { ORDEN_APELLIDO_Y_NOMBRE, ORDEN_TELEFONO, ORDEN_DIRECCION, ORDEN_EMAIL };

/**
* @brief Clase contenedora que administra la lista de personas
*
* Contiene la lista total de personas, y los metodos para buscar, ordenar, 
* modificar, y leer y guardar en los archivos binarios. Es la clase que engloba
* todo el problema. Deberia haber una sola instancia y que todos trabajen
* sobre la misma.
* Notar que los datos estan siempre en memoria, y luego de modificarlos se debe
* llamar al metodo Guardar para que los cambios se reflejen en los archivos.
**/
class Lista_Clientes {
private:
	/// @brief Nombre del archivo de donde se leen y donde se escriben los datos
	std::string nombre_archivo;
	
	/// @brief Contenedor STL para los datos
	std::vector<Clientes> arreglo;
public:
	Lista_Clientes();
	/// @brief Crea el objeto y carga los datos desde un archivo
	Lista_Clientes (std::string archivo);
	
	/// @brief Guarda los datos en el archivo
	bool Guardar();
	
	/// @brief Devuelve la cantidad de registros
	int CantidadDatos();
	
	/// @brief Agrega un registro
	void AgregarCliente(const Clientes &c);
	
	/// @brief Devuelve un registro para ver o modificar
	Clientes &operator[](int i);
	/// @brief Devuelve un registro para ver o modificar
	Clientes &VerCliente(int i);
	
	
	/// @brief Quita una persona de la base de datos
	void EliminarPersona(int i);
	
	/// @brief Ordena el vector
	void Ordenar(CriterioOrden criterio);
	
	// funciones para busquedas
	/// @brief Buscar una persona por nombre
	int BuscarNombre(std::string parte_nombre, int pos_desde);
	/// @brief Buscar una persona por apellido
	int BuscarApellido(std::string parte_apellido, int pos_desde);
	/// @brief Buscar una persona por apellido y nombre
	int BuscarApellidoYNombre(std::string parte_apellido, int pos_desde);
	/// @brief Buscar una persona por direccion
	int BuscarDireccion(std::string parte_direccion, int pos_desde);
	/// @brief Buscar una persona por telefono
	int BuscarTelefono(std::string parte_telefono, int pos_desde);
	/// @brief Buscar una persona por email
	int BuscarEmail(std::string parte_correo, int pos_desde);
	/// @brief Buscar una persona por ciudad
	int BuscarCiudad(std::string parte_ciudad, int pos_desde);
	/// @brief Buscar una persona por fecha de nacimiento
	int BuscarNacimiento(int dia, int mes, int anio, int pos_desde);
	//Buscar por BuscarPorDni
	Clientes* BuscarPorDni(int dni);
	void MostrarPorConsola();

};

#endif


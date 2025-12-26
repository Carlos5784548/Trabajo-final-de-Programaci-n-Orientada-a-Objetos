#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>
#include "Clientes.h"
#include "HistorialPagos.h"
#include "Lista_Asistencias.h"
using namespace std;
/**
* @brief Estructura auxiliar para usar con archivos binarios
*
* En los binarios no se debe guardar ni escribir objetos string porque al ser
* dinamicos contienen punteros y lo que en realidad se guardaria seria el
* puntero y no la informacion a la que apunta. Esta estructura sirve de 
* intermediaria para guardar y escribir los datos de una persona.
**/
struct registro_Cliente {
	char nombre[256];
	char apellido[256];
	char telefono[256];
	char direccion[256];
	char localidad[256];
	char email[256];
	int dni;
	char actividad[256];
};
/**
* @brief Clase que representa a una Clientes. 
*
* Contiene los atributos que se guardan de cada persona, metodos para definirlos
* y modificarlos, para validar los datos, y para guardar o escribir en archivos
* binarios.
**/
class Clientes {
private:
	string nombre; ///< nombres de la persona
	string apellido; ///< apellido de la persona
	string telefono; ///< telefono de la persona
	string direccion; ///< direccion de la persona
	string localidad; ///< localidad donde vive la persona
	string email; ///< direccion de correo electronico de la persona
	int dni;
	string actividad;
public:
	Clientes(std::string a_nombre="", std::string a_apellido="", std::string a_telefono="",
			 std::string a_direccion="", std::string a_email="", int a_dni=0,std::string a_actividad="");

	
	// construir un obejto con los datos
	/// Inicializa los datos de una persona
	
	
	/// Valida que los datos cargados sean correctos y suficientes
	std::string ValidarDatos();
	
	// obtener los datos guardados
	std::string VerNombre() const; ///< devuelve el nombre de la persona
	std::string VerApellido() const; ///< devuelve el apellido de la persona
	std::string VerDireccion() const; ///< devuelve la direccion de la persona
	std::string VerLocalidad() const; ///< devuelve la localidad de la persona
	std::string VerTelefono() const; ///< devuelve el telefono de la persona
	std::string VerEmail() const; ///< devuelve la direccion de correo electronico de la persona
	std::string VerActividad() const;
	int Verdni() const; ///< devuelve el dni del Clientes
	double CalcularDeuda(const HistorialPagos& historial) const;
	bool EstaVencido(const HistorialPagos& historial) const;
	int DiasDisponibles(const HistorialPagos &historial, const Lista_Asistencias &asistencias)const;
	
	// modificar los datos
	void ModificarNombre(std::string a_nombre); ///< actualiza el nombre de la persona
	void ModificarApellido(std::string a_apellido); ///< actualiza el apellido de la persona
	void ModificarDireccion(std::string a_direccion); ///< actualiza la direccion de la persona
	void ModificarLocalidad(std::string a_localidad); ///< actualiza la localidad de la persona
	void ModificarTelefono(std::string a_telefono); ///< actualiza el telefono de la persona
	void ModificarEmail(std::string a_email); ///< actualiza la direccion de correo electronico de la persona
	void ModificarDni(int d) ;///< actualiza la fecha de nacimiento de la persona
	void ModificarActividad(std::string a_actividad);


	/// guarda su registro en un archivo binario
	void GuardarEnBinario(std::ofstream &archivo);						
	/// lee su registro desde un archivo binario
	void LeerDesdeBinario(std::ifstream &archivo);

	
};
// crirerios para comparar dos personas

/// @brief Funcion para comparar dos personas por nombre y apellido 
bool criterio_comparacion_apellido_y_nombre(const Clientes &p1, const Clientes &p2);
/// @brief Funcion para comparar personas por direccion
bool criterio_comparacion_direccion(const Clientes &p1, const Clientes &p2);
/// @brief Funcion para comparar dos personas por telefono
bool criterio_comparacion_telefono(const Clientes &p1, const Clientes &p2);
/// @brief Funcion para comparar dos personas por email
bool criterio_comparacion_email(const Clientes &p1, const Clientes &p2);
#endif


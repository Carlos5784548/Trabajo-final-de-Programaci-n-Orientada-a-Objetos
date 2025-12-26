#include "Clientes.h"
#include <string>
#include <cstring> // Para usar strcpy
#include <algorithm>
#include <cstring>
#include <fstream>
#include <wx/datetime.h>
#include "Lista_Asistencias.h"
using namespace std;

Clientes::Clientes(std::string a_nombre, std::string a_apellido, std::string a_telefono,std::string a_direccion, std::string a_email, int a_dni,std::string a_actividad) {
	nombre = a_nombre;
	apellido = a_apellido;
	telefono = a_telefono;
	direccion = a_direccion;
	email = a_email;
	dni = a_dni;// Corregido: se asignaba 'dni' a sí mismo
	actividad=a_actividad;
}

string Clientes::VerNombre() const {
	return nombre;
}

string Clientes::VerApellido() const {
	return apellido;
}

string Clientes::VerDireccion() const {
	return direccion;
}

string Clientes::VerTelefono() const {
	return telefono;
}

string Clientes::VerEmail() const {
	return email;
}

int Clientes::Verdni() const {
	return dni;
}

string Clientes::VerActividad() const {
	return actividad;
}

void Clientes::ModificarNombre(std::string a_nombre) {
	nombre = a_nombre;
}

void Clientes::ModificarApellido(std::string a_apellido) {
	apellido = a_apellido;
}

void Clientes::ModificarDireccion(std::string a_direccion) {
	direccion = a_direccion;
}

void Clientes::ModificarTelefono(std::string a_telefono) {
	telefono = a_telefono;
}

void Clientes::ModificarEmail(std::string a_email) {
	email = a_email;
}

void Clientes::ModificarDni(int dn) {
	dni = dn;
}
void Clientes::ModificarActividad(std::string a_actividad) {
	actividad = a_actividad;
}



void Clientes::GuardarEnBinario(std::ofstream &archivo) {
	registro_Cliente reg;
	strncpy(reg.nombre, nombre.c_str(), sizeof(reg.nombre) - 1);
	reg.nombre[sizeof(reg.nombre) - 1] = '\0'; // Asegurar que esté terminado en null
	strncpy(reg.apellido, apellido.c_str(), sizeof(reg.apellido) - 1);
	reg.apellido[sizeof(reg.apellido) - 1] = '\0';
	strncpy(reg.telefono, telefono.c_str(), sizeof(reg.telefono) - 1);
	reg.telefono[sizeof(reg.telefono) - 1] = '\0';
	strncpy(reg.direccion, direccion.c_str(), sizeof(reg.direccion) - 1);
	reg.direccion[sizeof(reg.direccion) - 1] = '\0';
	strncpy(reg.email, email.c_str(), sizeof(reg.email) - 1);
	reg.email[sizeof(reg.email) - 1] = '\0';
	reg.dni = dni;
	strncpy(reg.actividad, actividad.c_str(), sizeof(reg.actividad) - 1);
	reg.actividad[sizeof(reg.actividad) - 1] = '\0';
	
	archivo.write((char*)&reg, sizeof(reg));
}

void Clientes::LeerDesdeBinario(std::ifstream &archivo) {
	registro_Cliente reg;
	archivo.read((char*)&reg, sizeof(reg));
	nombre = reg.nombre;
	apellido = reg.apellido;
	telefono = reg.telefono;
	direccion = reg.direccion;
	email = reg.email;
	dni = reg.dni;
	actividad=reg.actividad;
}

// Calcula la deuda del cliente según su actividad y los pagos realizados.
double Clientes::CalcularDeuda(const HistorialPagos& historial) const {
	// Suponiendo que cada actividad tiene un costo fijo:
	double montoEsperado = 0;
	if (actividad == "Musculacion") return 5000.0;
	if (actividad == "Funcional") return 4000.0 ;
	if (actividad == "Boxeo") return 7000.0;
	// Obtener pagos del historial para este cliente
	std::vector<Pagos> pagosCliente = historial.PagosDeCliente(dni);
	double totalPagado = 0;
	for (const auto& pago : pagosCliente)
		totalPagado += pago.VerMonto();
	
	return montoEsperado - totalPagado;
}
// Devuelve true si el cliente tiene la cuota vencida, false si está al día.
bool Clientes::EstaVencido(const HistorialPagos& historial) const{
	std::vector<Pagos> pagos = historial.PagosDeCliente(dni);
	wxDateTime hoy = wxDateTime::Now();
	int diasRestantes = 0;
	
	for (const auto& p : pagos) {
		wxDateTime fechaPago;
		int d, m, a;
		sscanf(p.VerFecha().c_str(), "%d/%d/%d", &d, &m, &a);
		fechaPago.SetDay(d);
		fechaPago.SetMonth((wxDateTime::Month)(m - 1));
		fechaPago.SetYear(a);
		
		int dias = p.VerDiasPagados();
		wxDateTime vencimiento = fechaPago + wxDateSpan::Days(dias);
		
		if (vencimiento > hoy)
			diasRestantes += (vencimiento - hoy).GetDays();
	}
	
	return diasRestantes <= 0;
}
// Devuelve la cantidad de días disponibles (pagados menos asistencias realizadas).

int Clientes::DiasDisponibles(const HistorialPagos& historial, const Lista_Asistencias& asistencias) const {
	int totalDiasPagados = 0;
	for (const auto& p : historial.PagosDeCliente(dni)) {
		totalDiasPagados += p.VerDiasPagados();
	}
	
	int asistenciasRealizadas = asistencias.CantidadDeAsistencias(dni);
	
	return totalDiasPagados - asistenciasRealizadas;
}




// Valida los datos del cliente y devuelve un string con los errores encontrados (vacío si no hay errores).
std::string Clientes::ValidarDatos() {
	std::string errores;
	if (nombre.empty()) errores += "El nombre no puede estar vacio\n";
	if (nombre.size() > 256) errores += "El nombre es demasiado largo\n";
	if (apellido.empty()) errores += "El apellido no puede estar vacio\n";
	if (apellido.size() > 256) errores += "El apellido es demasiado largo\n";
	if (telefono.size() > 256) errores += "El telefono es demasiado largo\n";
	if (direccion.size() > 256) errores += "La direccion es demasiado larga\n";
	if (email.size() > 256) errores += "El e-mail es demasiado largo\n";
	if (dni < 0 || dni > 99999999) errores += "El DNI ingresado no es válido\n"; // Corregido: rango de DNI
	return errores;
}

bool criterio_comparacion_apellido_y_nombre(const Clientes &p1, const Clientes &p2) {
	std::string s1 = p1.VerApellido() + ", " + p1.VerNombre();
	std::string s2 = p2.VerApellido() + ", " + p2.VerNombre();
	// Convertir a minúsculas
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}

bool criterio_comparacion_direccion(const Clientes &p1, const Clientes &p2) {
	std::string s1 = p1.VerDireccion();
	std::string s2 = p2.VerDireccion();
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}

bool criterio_comparacion_telefono(const Clientes &p1, const Clientes &p2) {
	std::string s1 = p1.VerTelefono();
	std::string s2 = p2.VerTelefono();
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}

bool criterio_comparacion_email(const Clientes &p1, const Clientes &p2) {
	std::string s1 = p1.VerEmail();
	std::string s2 = p2.VerEmail();
	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	return s1 < s2;
}

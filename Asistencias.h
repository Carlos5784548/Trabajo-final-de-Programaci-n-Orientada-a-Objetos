#ifndef ASISTENCIAS_H
#define ASISTENCIAS_H
#include <string>

struct registro_Asistencia {
	int dni_cliente;
	char fecha[11]; // dd/mm/yyyy
};


class Asistencias {
public:
	Asistencias();
	Asistencias	(int dni, const std::string& fecha);
	int VerDni() const;             // Solo declaración
	std::string VerFecha() const;
	
	void GuardarEnBinario(std::ofstream& archivo) const;
	void LeerDesdeBinario(std::ifstream& archivo);
private:
	int dni_cliente;
	std::string fecha; // formato dd/mm/yyyy
};

#endif


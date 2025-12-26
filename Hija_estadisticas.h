#ifndef HIJA_ESTADISTICAS_H
#define HIJA_ESTADISTICAS_H
#include "wxfb_project.h"
#include "Clientes.h"
#include "HistorialPagos.h"
#include "Lista_Clientes.h"
#include "Lista_Asistencias.h"


class Hija_estadisticas : public Estadisticas {
private:
	Lista_Clientes* m_clientes = nullptr;
	HistorialPagos* m_historial = nullptr;
	Lista_Asistencias* m_listaAsistencias= nullptr;
	
	
protected:
	void btnaplica(wxCommandEvent& event) override;
	
public:
	Hija_estadisticas(wxWindow* parent = nullptr, Lista_Clientes* clientes = nullptr, HistorialPagos* historial = nullptr,Lista_Asistencias* asistencias=nullptr);
	~Hija_estadisticas();
};


#endif


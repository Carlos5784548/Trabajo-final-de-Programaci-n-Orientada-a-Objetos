#ifndef VENTANAESTADISTICASHIJO_H
#define VENTANAESTADISTICASHIJO_H
#include "wxfb_project.h"
#include "HistorialPagos.h"
#include "Lista_Clientes.h"
#include <wx/listctrl.h>

class VentanaEstadisticasHijo : public VentanaEstadisticas {
	
private:
	wxButton* BtnPrueba;
protected:
	void probar( wxCommandEvent& event )  override;
	void BtnFiltrar( wxCommandEvent& event )  override;
	Lista_Clientes* m_clientes;
	HistorialPagos* m_historial;
	
public:
	VentanaEstadisticasHijo(wxWindow *parent=NULL);
	
	
};

#endif


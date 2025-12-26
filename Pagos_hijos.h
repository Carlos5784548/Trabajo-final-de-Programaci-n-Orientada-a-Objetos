#ifndef PAGOS_HIJOS_H
#define PAGOS_HIJOS_H
#include "wxfb_project.h"
#include "HistorialPagos.h"
#include "Clientes.h"

class Pagos_hijos : public Ventana_Pagos {
	
private:
	int m_dni_cliente;   // DNI del cliente    
	HistorialPagos m_historial;          // Objeto historial que contiene los pagos
	Clientes m_cliente; //Clientes
protected:
	void Ver_Pre( wxCommandEvent& event )  override;
	void BtnImprimir( wxCommandEvent& event )  override;
	void Pagar( wxCommandEvent& event )  override;
	void CargarFilaPago(int i);
	
public:
	Pagos_hijos(wxWindow* parent, const Clientes& cliente);
	~Pagos_hijos();
};

#endif


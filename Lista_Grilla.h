#ifndef LISTA_GRILLA_H
#define LISTA_GRILLA_H
#include "wxfb_project.h"
#include "Lista_Clientes.h"
#include "Lista_Asistencias.h"
#include "Asistencias.h"
class Lista_Clientes;


class Lista_Grilla : public Lista_Clientes_Grilla {
private:
	
	void CargarFila(int i);
protected:
	void Registar( wxCommandEvent& event )  override;
	void Asistencia( wxCommandEvent& event )  override;
	void VerEstadisticas( wxCommandEvent& event )  override;
	void RegistrarPago( wxCommandEvent& event )  override;
	void Click_Modifica( wxCommandEvent& event )  override;
	void Click_agregar( wxCommandEvent& event )  override;
	void Click_eliminar( wxCommandEvent& event )  override;
	void clickBuscar( wxCommandEvent& event )  override;
	void OnClickGrilla( wxGridEvent& event )  override;
	Lista_Clientes *m_lista;
	Lista_Asistencias* m_listaAsistencias;
	HistorialPagos* m_historial;
	
public:
	Lista_Grilla(Lista_Clientes* listaClientes, HistorialPagos* historial, Lista_Asistencias* listaAsistencias);
	~Lista_Grilla();
};

#endif


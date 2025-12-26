#ifndef VENTANA_REGISTRO_HIJA_H
#define VENTANA_REGISTRO_HIJA_H
#include "wxfb_project.h"
#include "Lista_Clientes.h"

class Ventana_registro_hija : public Ventana_registro {
	
private:
	Lista_Clientes* m_lista;
protected:
	void Agregar( wxCommandEvent& event );
	void cancelar( wxCommandEvent& event );
public:
	Ventana_registro_hija(wxWindow* parent, Lista_Clientes* lista_clientes);
	
	~Ventana_registro_hija();
	
};

#endif


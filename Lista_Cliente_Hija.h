#ifndef LISTA_CLIENTE_HIJA_H
#define LISTA_CLIENTE_HIJA_H
#include "wxfb_project.h"

class Lista_Cliente_Hija : public Lista_Clientes {
	
private:
	
protected:
	void OnClickGrilla( wxGridEvent& event )  override;
	void clickBuscar( wxCommandEvent& event )  override;
	
public:
	Lista_Cliente_Hija(wxWindow *parent=NULL);
	Lista_Cliente_Hija(wxWindow* parent = nullptr, Lista_Clientes* listaClientes = nullptr);
	~Lista_Cliente_Hija();
};

#endif


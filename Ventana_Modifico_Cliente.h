
#define VENTANA_MODIFICO_CLIENTE_H
#include "wxfb_project.h"
#include "Lista_Clientes.h"

class Ventana_Modifico_Cliente : public Ventana_Modifico {
private:
	Lista_Clientes* m_lista = nullptr;
	int m_indice = -1;
	
protected:
	void Actulizar(wxCommandEvent& event) override;
	void cancelar(wxCommandEvent& event) override;
	
public:
	Ventana_Modifico_Cliente(wxWindow* parent = NULL, Lista_Clientes* lista = nullptr, int indice = -1);
	~Ventana_Modifico_Cliente();
};



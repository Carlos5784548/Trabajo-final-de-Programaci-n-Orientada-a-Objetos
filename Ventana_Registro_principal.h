#ifndef VENTANA_REGISTRO_PRINCIPAL_H
#define VENTANA_REGISTRO_PRINCIPAL_H
#include "wxfb_project.h"
#include <vector>
using namespace std;

class Ventana_Registro_principal : public Ventana_Registro {
	
private:
	
protected:

	void registro( wxCommandEvent& event )  override;
	bool Agrego_usuario(const std::string &Usu, const std::string &contr, bool admin);
	
	
public:
	Ventana_Registro_principal(wxWindow *parent=NULL);
	~Ventana_Registro_principal();
};

#endif


#ifndef VETANA_LOGIN_PRINCIPAL_H
#define VETANA_LOGIN_PRINCIPAL_H
#include "wxfb_project.h"
#include <vector>
using namespace std;


struct Usuario{
	char nombre[80];
	char contra[20];
	bool rol;
};


class Vetana_Login_Principal : public Ventana_Login {
	
private:
	
protected:
	void Ingresar( wxCommandEvent& event )  override;
	
	
	
public:
	Vetana_Login_Principal(wxWindow *parent=NULL);
	~Vetana_Login_Principal();
	
	static vector<Usuario>Cargo_usuario();
	bool Verificar_Usuario(const std::string &Usu,const std::string &contr);
	bool crearArchivoPrueba();
	
	
};

#endif


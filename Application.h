#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Lista_Clientes.h"
 
class Application : public wxApp {
Lista_Clientes *m_lista;
	public:
	static bool loginExitoso;
	static bool esAdmin;
	virtual bool OnInit(); 
};

#endif

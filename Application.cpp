#include <wx/image.h>
#include "Application.h"
#include "Vetana_Login_Principal.h"
#include "Ventana_Registro_principal.h"

#include "Lista_Grilla.h"
#include "Ventana_registro_hija.h"
#include "Asistencias.h"
#include "Lista_Asistencias.h"

IMPLEMENT_APP(Application)
	bool Application::loginExitoso = false;

bool Application::esAdmin = false;

bool Application::OnInit() {
	wxInitAllImageHandlers();
	
	// Mostrar login (no modal)
	Vetana_Login_Principal* login = new Vetana_Login_Principal(nullptr);
	login->Show(); // solo se muestra, no devuelve nada
	
	return true; // continuar ejecución normal

}


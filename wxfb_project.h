///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/radiobut.h>
#include <wx/grid.h>
#include <wx/tglbtn.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/choice.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_Login
///////////////////////////////////////////////////////////////////////////////
class Ventana_Login : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* txtUsu;
		wxStaticText* m_staticText3;
		wxTextCtrl* txtContra;
		wxButton* btnIngresar;
		wxStaticText* error;

		// Virtual event handlers, override them in your derived class
		virtual void Ingresar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_Login( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,229 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_Login();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_Registro
///////////////////////////////////////////////////////////////////////////////
class Ventana_Registro : public wxFrame
{
	private:

	protected:
		wxStaticText* Regsitro;
		wxStaticText* m_staticText7;
		wxTextCtrl* txt_registro_usu;
		wxStaticText* m_staticText8;
		wxTextCtrl* txt_registro_contra;
		wxStaticText* m_staticText9;
		wxRadioButton* si;
		wxRadioButton* no;
		wxButton* btn_registrar;
		wxStaticText* error_r;

		// Virtual event handlers, override them in your derived class
		virtual void registro( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_Registro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana_Registro();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Lista_Clientes_Grilla
///////////////////////////////////////////////////////////////////////////////
class Lista_Clientes_Grilla : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText10;
		wxTextCtrl* txtBuscar;
		wxButton* btnBuscar;
		wxGrid* m_grilla;
		wxButton* btnAgregar;
		wxButton* btn_eliminar;
		wxButton* btn_Modifica;
		wxToggleButton* btnPagar;
		wxButton* Estadisticas;
		wxButton* m_button18;
		wxToggleButton* Registrar_usuario;

		// Virtual event handlers, override them in your derived class
		virtual void clickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void Click_agregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_eliminar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Click_Modifica( wxCommandEvent& event ) { event.Skip(); }
		virtual void RegistrarPago( wxCommandEvent& event ) { event.Skip(); }
		virtual void VerEstadisticas( wxCommandEvent& event ) { event.Skip(); }
		virtual void Asistencia( wxCommandEvent& event ) { event.Skip(); }
		virtual void Registar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Lista_Clientes_Grilla( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 924,519 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Lista_Clientes_Grilla();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_Modifico
///////////////////////////////////////////////////////////////////////////////
class Ventana_Modifico : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* txtNombre;
		wxStaticText* m_staticText33;
		wxTextCtrl* txtApellido;
		wxStaticText* m_staticText28;
		wxTextCtrl* txtTelefono;
		wxStaticText* m_staticText29;
		wxTextCtrl* txtDirrecion;
		wxStaticText* m_staticText30;
		wxTextCtrl* txtMail;
		wxStaticText* m_staticText31;
		wxTextCtrl* txtDni;
		wxStaticText* m_staticText32;
		wxComboBox* Actividad;
		wxButton* ActulizarBtn;
		wxButton* Cancelar;

		// Virtual event handlers, override them in your derived class
		virtual void Actulizar( wxCommandEvent& event ) { event.Skip(); }
		virtual void cancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_Modifico( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 805,552 ), long style = wxDEFAULT_DIALOG_STYLE );

		~Ventana_Modifico();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_registro
///////////////////////////////////////////////////////////////////////////////
class Ventana_registro : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText26;
		wxTextCtrl* txtNombre;
		wxStaticText* m_staticText33;
		wxTextCtrl* txtApellido;
		wxStaticText* m_staticText28;
		wxTextCtrl* txtTelefono;
		wxStaticText* m_staticText29;
		wxTextCtrl* txtDirrecion;
		wxStaticText* m_staticText30;
		wxTextCtrl* txtMail;
		wxStaticText* m_staticText31;
		wxTextCtrl* txtDni;
		wxStaticText* m_staticText32;
		wxComboBox* Actividad;
		wxButton* AgregarBtn;
		wxButton* Cancelar;

		// Virtual event handlers, override them in your derived class
		virtual void Agregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void cancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_registro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 805,552 ), long style = wxDEFAULT_DIALOG_STYLE );

		~Ventana_registro();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_Pagos
///////////////////////////////////////////////////////////////////////////////
class Ventana_Pagos : public wxDialog
{
	private:

	protected:
		wxStaticText* p;
		wxStaticText* m_staticText41;
		wxDatePickerCtrl* m_datePicker2;
		wxStaticText* m_staticText42;
		wxTextCtrl* txtdn;
		wxStaticText* m_staticText29;
		wxTextCtrl* txtActi;
		wxStaticText* m_staticText44;
		wxTextCtrl* txtmonto;
		wxStaticText* m_staticText46;
		wxComboBox* m_comboBox5;
		wxButton* btnPagar;
		wxButton* Ver_Precio;
		wxButton* Btnimprimir;
		wxGrid* m_grilla_pagos;

		// Virtual event handlers, override them in your derived class
		virtual void Pagar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Ver_Pre( wxCommandEvent& event ) { event.Skip(); }
		virtual void BtnImprimir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana_Pagos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 805,647 ), long style = wxDEFAULT_DIALOG_STYLE );

		~Ventana_Pagos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Estadisticas
///////////////////////////////////////////////////////////////////////////////
class Estadisticas : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText52;
		wxStaticText* m_staticText75;
		wxChoice* filtroActividad;
		wxStaticText* m_staticText76;
		wxStaticText* m_staticText77;
		wxDatePickerCtrl* filtroDesde;
		wxStaticText* m_staticText78;
		wxDatePickerCtrl* filtroHasta;
		wxStaticText* m_staticText79;
		wxChoice* filtroMetodo;
		wxStaticText* m_staticText80;
		wxChoice* filtroEstadoCuenta;
		wxButton* m_button31;
		wxGrid* grillaEstadisticas;

		// Virtual event handlers, override them in your derived class
		virtual void btnaplica( wxCommandEvent& event ) { event.Skip(); }


	public:

		Estadisticas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 757,647 ), long style = wxDEFAULT_DIALOG_STYLE );

		~Estadisticas();

};


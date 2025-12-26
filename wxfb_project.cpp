///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Ventana_Login::Ventana_Login( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtUsu = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( txtUsu, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer2->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtContra = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( txtContra, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	btnIngresar = new wxButton( this, wxID_ANY, wxT("Ingresar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( btnIngresar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	error = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	error->Wrap( -1 );
	bSizer2->Add( error, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	btnIngresar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Login::Ingresar ), NULL, this );
}

Ventana_Login::~Ventana_Login()
{
	// Disconnect Events
	btnIngresar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Login::Ingresar ), NULL, this );

}

Ventana_Registro::Ventana_Registro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	Regsitro = new wxStaticText( this, wxID_ANY, wxT("Registro de usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	Regsitro->Wrap( -1 );
	bSizer3->Add( Regsitro, 0, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Nombre de usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer3->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txt_registro_usu = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( txt_registro_usu, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Contraceña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer3->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txt_registro_contra = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( txt_registro_contra, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Es admin?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer3->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	si = new wxRadioButton( this, wxID_ANY, wxT("Si"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( si, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	no = new wxRadioButton( this, wxID_ANY, wxT("No"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( no, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	btn_registrar = new wxButton( this, wxID_ANY, wxT("Registrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_registrar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	error_r = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	error_r->Wrap( -1 );
	bSizer3->Add( error_r, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	btn_registrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Registro::registro ), NULL, this );
}

Ventana_Registro::~Ventana_Registro()
{
	// Disconnect Events
	btn_registrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Registro::registro ), NULL, this );

}

Lista_Clientes_Grilla::Lista_Clientes_Grilla( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("NOMBRE"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer5->Add( m_staticText10, 0, wxALL, 5 );

	txtBuscar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( txtBuscar, 1, wxALL, 5 );

	btnBuscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( btnBuscar, 0, wxALL, 5 );


	bSizer3->Add( bSizer5, 1, wxEXPAND, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 4 );
	m_grilla->EnableEditing( false );
	m_grilla->EnableGridLines( true );
	m_grilla->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 219 );
	m_grilla->SetColSize( 1, 142 );
	m_grilla->SetColSize( 2, 132 );
	m_grilla->SetColSize( 3, 177 );
	m_grilla->EnableDragColMove( true );
	m_grilla->EnableDragColSize( false );
	m_grilla->SetColLabelValue( 0, wxT("NOMBRE Y APELLIDO") );
	m_grilla->SetColLabelValue( 1, wxT("DNI") );
	m_grilla->SetColLabelValue( 2, wxT("TELEFONO ") );
	m_grilla->SetColLabelValue( 3, wxT("ACTIVIDAD") );
	m_grilla->SetColLabelSize( 30 );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( wxGRID_AUTOSIZE );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer3->Add( m_grilla, 1, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	btnAgregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( btnAgregar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	btn_eliminar = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( btn_eliminar, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	btn_Modifica = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( btn_Modifica, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	btnPagar = new wxToggleButton( this, wxID_ANY, wxT("Pagar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( btnPagar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	Estadisticas = new wxButton( this, wxID_ANY, wxT("Estadisticas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( Estadisticas, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button18 = new wxButton( this, wxID_ANY, wxT("Registrar_Asistencia"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	Registrar_usuario = new wxToggleButton( this, wxID_ANY, wxT("Registrar_usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( Registrar_usuario, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer3->Add( bSizer6, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	btnBuscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::clickBuscar ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Lista_Clientes_Grilla::OnClickGrilla ), NULL, this );
	btnAgregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Click_agregar ), NULL, this );
	btn_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Click_eliminar ), NULL, this );
	btn_Modifica->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Click_Modifica ), NULL, this );
	btnPagar->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::RegistrarPago ), NULL, this );
	Estadisticas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::VerEstadisticas ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Asistencia ), NULL, this );
	Registrar_usuario->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Registar ), NULL, this );
}

Lista_Clientes_Grilla::~Lista_Clientes_Grilla()
{
	// Disconnect Events
	btnBuscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::clickBuscar ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Lista_Clientes_Grilla::OnClickGrilla ), NULL, this );
	btnAgregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Click_agregar ), NULL, this );
	btn_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Click_eliminar ), NULL, this );
	btn_Modifica->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Click_Modifica ), NULL, this );
	btnPagar->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::RegistrarPago ), NULL, this );
	Estadisticas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::VerEstadisticas ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Asistencia ), NULL, this );
	Registrar_usuario->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( Lista_Clientes_Grilla::Registar ), NULL, this );

}

Ventana_Modifico::Ventana_Modifico( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer13->Add( m_staticText26, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtNombre, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer13->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtApellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtApellido, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer13->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtTelefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtTelefono, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Dirrecion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer13->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtDirrecion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtDirrecion, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Email"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer13->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtMail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtMail, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Dni"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer13->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtDni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtDni, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Actividad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer13->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Actividad = new wxComboBox( this, wxID_ANY, wxT("Funcional"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	Actividad->Append( wxT("Musculacion") );
	Actividad->Append( wxT("Funcional") );
	Actividad->Append( wxT("Boxeo") );
	Actividad->SetSelection( 1 );
	bSizer13->Add( Actividad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	ActulizarBtn = new wxButton( this, wxID_ANY, wxT("Actualizar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( ActulizarBtn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( Cancelar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	ActulizarBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Modifico::Actulizar ), NULL, this );
	Cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Modifico::cancelar ), NULL, this );
}

Ventana_Modifico::~Ventana_Modifico()
{
	// Disconnect Events
	ActulizarBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Modifico::Actulizar ), NULL, this );
	Cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Modifico::cancelar ), NULL, this );

}

Ventana_registro::Ventana_registro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer13->Add( m_staticText26, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtNombre, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer13->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtApellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtApellido, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer13->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtTelefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtTelefono, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Dirrecion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer13->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtDirrecion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtDirrecion, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Email"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer13->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtMail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtMail, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Dni"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer13->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtDni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtDni, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Actividad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer13->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Actividad = new wxComboBox( this, wxID_ANY, wxT("Musculacion"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	Actividad->Append( wxT("Musculacion") );
	Actividad->Append( wxT("Funcional") );
	Actividad->Append( wxT("Boxeo") );
	Actividad->Append( wxEmptyString );
	Actividad->Append( wxEmptyString );
	Actividad->SetSelection( 0 );
	bSizer13->Add( Actividad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	AgregarBtn = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( AgregarBtn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( Cancelar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	AgregarBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_registro::Agregar ), NULL, this );
	Cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_registro::cancelar ), NULL, this );
}

Ventana_registro::~Ventana_registro()
{
	// Disconnect Events
	AgregarBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_registro::Agregar ), NULL, this );
	Cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_registro::cancelar ), NULL, this );

}

Ventana_Pagos::Ventana_Pagos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	p = new wxStaticText( this, wxID_ANY, wxT("Pagos"), wxDefaultPosition, wxDefaultSize, 0 );
	p->Wrap( -1 );
	bSizer13->Add( p, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("Fecha"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer13->Add( m_staticText41, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_datePicker2 = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer13->Add( m_datePicker2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer13->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtdn = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtdn, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Actividad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer13->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtActi = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtActi, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText44 = new wxStaticText( this, wxID_ANY, wxT("Monto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	bSizer13->Add( m_staticText44, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	txtmonto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( txtmonto, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText46 = new wxStaticText( this, wxID_ANY, wxT("Metodo de pago"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	bSizer13->Add( m_staticText46, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_comboBox5 = new wxComboBox( this, wxID_ANY, wxT("MERCADO PAGO"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBox5->Append( wxT("EFECTIVO") );
	m_comboBox5->Append( wxT("TRANSFERENCIA") );
	m_comboBox5->Append( wxT("MERCADO PAGO") );
	m_comboBox5->SetSelection( 2 );
	bSizer13->Add( m_comboBox5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	btnPagar = new wxButton( this, wxID_ANY, wxT("Pagar "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( btnPagar, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );

	Ver_Precio = new wxButton( this, wxID_ANY, wxT("Ver_precio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( Ver_Precio, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Btnimprimir = new wxButton( this, wxID_ANY, wxT("Imprimir_Factura"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( Btnimprimir, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_grilla_pagos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla_pagos->CreateGrid( 0, 4 );
	m_grilla_pagos->EnableEditing( false );
	m_grilla_pagos->EnableGridLines( true );
	m_grilla_pagos->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_grilla_pagos->EnableDragGridSize( false );
	m_grilla_pagos->SetMargins( 0, 0 );

	// Columns
	m_grilla_pagos->SetColSize( 0, 219 );
	m_grilla_pagos->SetColSize( 1, 142 );
	m_grilla_pagos->SetColSize( 2, 132 );
	m_grilla_pagos->SetColSize( 3, 177 );
	m_grilla_pagos->EnableDragColMove( false );
	m_grilla_pagos->EnableDragColSize( true );
	m_grilla_pagos->SetColLabelValue( 0, wxT("Fecha") );
	m_grilla_pagos->SetColLabelValue( 1, wxT("Monto") );
	m_grilla_pagos->SetColLabelValue( 2, wxT("Metodo de  pago") );
	m_grilla_pagos->SetColLabelValue( 3, wxT("Dias Pagados") );
	m_grilla_pagos->SetColLabelValue( 4, wxEmptyString );
	m_grilla_pagos->SetColLabelValue( 5, wxEmptyString );
	m_grilla_pagos->SetColLabelValue( 6, wxEmptyString );
	m_grilla_pagos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla_pagos->EnableDragRowSize( true );
	m_grilla_pagos->SetRowLabelSize( 1 );
	m_grilla_pagos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla_pagos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_grilla_pagos, 1, wxALL|wxEXPAND, 5 );


	bSizer13->Add( bSizer11, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	btnPagar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Pagos::Pagar ), NULL, this );
	Ver_Precio->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Pagos::Ver_Pre ), NULL, this );
	Btnimprimir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Pagos::BtnImprimir ), NULL, this );
}

Ventana_Pagos::~Ventana_Pagos()
{
	// Disconnect Events
	btnPagar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Pagos::Pagar ), NULL, this );
	Ver_Precio->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Pagos::Ver_Pre ), NULL, this );
	Btnimprimir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana_Pagos::BtnImprimir ), NULL, this );

}

Estadisticas::Estadisticas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Filtro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	bSizer13->Add( m_staticText52, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText75 = new wxStaticText( this, wxID_ANY, wxT("Actividad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText75->Wrap( -1 );
	bSizer13->Add( m_staticText75, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString filtroActividadChoices[] = { wxT("Musculacion"), wxT("Funcional"), wxT("Boxeo"), wxEmptyString };
	int filtroActividadNChoices = sizeof( filtroActividadChoices ) / sizeof( wxString );
	filtroActividad = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, filtroActividadNChoices, filtroActividadChoices, 0 );
	filtroActividad->SetSelection( 0 );
	bSizer13->Add( filtroActividad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText76 = new wxStaticText( this, wxID_ANY, wxT("Fechas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText76->Wrap( -1 );
	bSizer13->Add( m_staticText76, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText77 = new wxStaticText( this, wxID_ANY, wxT("Desde"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText77->Wrap( -1 );
	bSizer13->Add( m_staticText77, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	filtroDesde = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer13->Add( filtroDesde, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText78 = new wxStaticText( this, wxID_ANY, wxT("Hasta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText78->Wrap( -1 );
	bSizer13->Add( m_staticText78, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	filtroHasta = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer13->Add( filtroHasta, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText79 = new wxStaticText( this, wxID_ANY, wxT("Medios de pagos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText79->Wrap( -1 );
	bSizer13->Add( m_staticText79, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString filtroMetodoChoices[] = { wxT("EFECTIVO"), wxT("TRANSFERENCIA"), wxT("MERCADO PAGO") };
	int filtroMetodoNChoices = sizeof( filtroMetodoChoices ) / sizeof( wxString );
	filtroMetodo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, filtroMetodoNChoices, filtroMetodoChoices, 0 );
	filtroMetodo->SetSelection( 0 );
	bSizer13->Add( filtroMetodo, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText80 = new wxStaticText( this, wxID_ANY, wxT("Estado  de la cuenta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText80->Wrap( -1 );
	bSizer13->Add( m_staticText80, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString filtroEstadoCuentaChoices[] = { wxT("Todos"), wxT("Al día"), wxT("Con deuda"), wxEmptyString, wxEmptyString, wxEmptyString, wxEmptyString };
	int filtroEstadoCuentaNChoices = sizeof( filtroEstadoCuentaChoices ) / sizeof( wxString );
	filtroEstadoCuenta = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, filtroEstadoCuentaNChoices, filtroEstadoCuentaChoices, 0 );
	filtroEstadoCuenta->SetSelection( 0 );
	bSizer13->Add( filtroEstadoCuenta, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button31 = new wxButton( this, wxID_ANY, wxT("Aplicar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button31, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	grillaEstadisticas = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaEstadisticas->CreateGrid( 0, 2 );
	grillaEstadisticas->EnableEditing( true );
	grillaEstadisticas->EnableGridLines( true );
	grillaEstadisticas->EnableDragGridSize( false );
	grillaEstadisticas->SetMargins( 0, 0 );

	// Columns
	grillaEstadisticas->SetColSize( 0, 219 );
	grillaEstadisticas->SetColSize( 1, 142 );
	grillaEstadisticas->SetColSize( 2, 132 );
	grillaEstadisticas->SetColSize( 3, 177 );
	grillaEstadisticas->EnableDragColMove( false );
	grillaEstadisticas->EnableDragColSize( true );
	grillaEstadisticas->SetColLabelValue( 0, wxT("Estadisticas") );
	grillaEstadisticas->SetColLabelValue( 1, wxT("Totales") );
	grillaEstadisticas->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grillaEstadisticas->EnableDragRowSize( true );
	grillaEstadisticas->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grillaEstadisticas->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer13->Add( grillaEstadisticas, 1, wxEXPAND|wxBOTTOM, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button31->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Estadisticas::btnaplica ), NULL, this );
}

Estadisticas::~Estadisticas()
{
	// Disconnect Events
	m_button31->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Estadisticas::btnaplica ), NULL, this );

}

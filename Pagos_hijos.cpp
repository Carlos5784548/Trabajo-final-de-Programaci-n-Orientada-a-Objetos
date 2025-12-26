#include "Pagos_hijos.h"
#include "HistorialPagos.h"
#include <wx/msgdlg.h>
#include "Clientes.h"
#include <fstream>
#include <sstream>
#include <iomanip>
// Convierte std::string a wxString para mostrar en controles wxWidgets.
inline wxString std_to_wx(const std::string& str) {
	return wxString(str.c_str());
}
// Calcula el monto esperado según la actividad.
double CalcularMontoPorActividad(const std::string& actividad) {
	if (actividad == "Musculacion") return 5000.0;
	if (actividad == "Funcional") return 4000.0;
	if (actividad == "Boxeo") return 7000.0;
	return 0.0; // Valor por defecto si no coincide
}

// Calcula los días pagados según la actividad y el monto abonado.
int CalcularDiasPorActividad(const std::string& actividad, double monto) {
	if (actividad == "Musculacion") return monto / 100.0;
	if (actividad == "Funcional")   return monto / 150.0;
	if (actividad == "Boxeo")       return monto / 120.0;
	return 0;
}

// Constructor: inicializa la ventana de pagos, muestra historial y datos del cliente.
//Llama al constructor de la clase base Ventana_Pagos pasando el puntero parent.
//	Inicializa el atributo m_dni_cliente con el DNI del cliente recibido.
//Inicializa el atributo m_cliente copiando el objeto cliente recibido.
//	Inicializa el atributo m_historial cargando el historial de pagos desde el archivo "pagos.dat".
//Prepara la ventana de pagos para el cliente seleccionado, cargando sus datos y el historial de pagos desde el a
Pagos_hijos::Pagos_hijos(wxWindow *parent, const Clientes& cliente)
	:Ventana_Pagos(parent), m_dni_cliente(cliente.Verdni()), m_cliente(cliente), m_historial("pagos.dat") {
	
	// Mostrar el DNI en el campo correspondiente
	txtdn->SetValue(std_to_wx(std::to_string(m_dni_cliente)));
	txtdn->Disable(); // Opcional: evita que el usuario lo modifique
	
	m_datePicker2->Disable();
	txtActi->SetValue(std_to_wx((m_cliente.VerActividad())));
	txtActi->Disable(); // Opcional: evita que el usuario lo modifique
	// Obtener los pagos del cliente
	std::vector<Pagos> pagos = m_historial.PagosDeCliente(m_dni_cliente);
	
	// Limpiar grilla si tiene filas
	if (m_grilla_pagos->GetNumberRows() > 0) {
		m_grilla_pagos->DeleteRows(0, m_grilla_pagos->GetNumberRows());
	}
	
	// Si hay pagos, los agregamos
	if (!pagos.empty()) {
		m_grilla_pagos->AppendRows(pagos.size());
		
		for (size_t i = 0; i < pagos.size(); ++i) {
			// Fecha
			m_grilla_pagos->SetCellValue(i, 0, std_to_wx(pagos[i].VerFecha()));
			
			// Monto con 2 decimales
			std::ostringstream oss;
			oss << std::fixed << std::setprecision(1) << pagos[i].VerMonto();
			m_grilla_pagos->SetCellValue(i, 1, std_to_wx(oss.str()));
			
			// Método de pago
			m_grilla_pagos->SetCellValue(i, 2, std_to_wx(pagos[i].VerMetodoPago()));
			
			// Días pagados (asegurándonos que no sea un número desbordado)
			m_grilla_pagos->SetCellValue(i, 3, std_to_wx(std::to_string(pagos[i].VerDiasPagados())));
		}
	}
}
Pagos_hijos::~Pagos_hijos() {
	
}
// Carga los datos de un pago en la fila i de la grilla.
void Pagos_hijos::CargarFilaPago(int i) {
	const Pagos& pago = m_historial.VerTodos()[i];
	
	// Fecha
	m_grilla_pagos->SetCellValue(i, 0, std_to_wx(pago.VerFecha()));
	
	// Monto con formato
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << pago.VerMonto();
	m_grilla_pagos->SetCellValue(i, 1, std_to_wx(oss.str()));
	
	// Método
	m_grilla_pagos->SetCellValue(i, 2, std_to_wx(pago.VerMetodoPago()));
	
	// Días pagados
	m_grilla_pagos->SetCellValue(i, 3, std_to_wx(std::to_string(pago.VerDiasPagados())));
}




void Pagos_hijos::Pagar(wxCommandEvent& event) {
	wxString wxMonto = txtmonto->GetValue();
	wxString wxMetodo = m_comboBox5->GetValue();
	
	if (wxMonto.IsEmpty() || wxMetodo.IsEmpty()) {
		wxMessageBox("Complete todos los campos.", "Error", wxICON_ERROR);
		return;
	}
	
	double montoIngresado = std::stod(std::string(wxMonto.mb_str())); 
	std::string metodo_pago = std::string(wxMetodo.mb_str());
	wxDateTime fechaSeleccionada = m_datePicker2->GetValue();
	std::string fecha = std::string(fechaSeleccionada.FormatISODate().mb_str());
	
	
	std::string actividad = m_cliente.VerActividad();
	
	
	float montoEsperado = CalcularMontoPorActividad(actividad);
	
	int diasPagados = CalcularDiasPorActividad(actividad, montoIngresado); // NUEVO
	
	
	if (montoIngresado < montoEsperado) {
		double deuda = montoEsperado - montoIngresado;
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(2) << deuda;
		wxMessageBox("Pago incompleto.\nDeuda restante: $" + oss.str(), "Aviso de deuda", wxICON_WARNING);
		
	}
	int cantidadAntes = m_historial.CantidadPagos();
	Pagos nuevo(m_dni_cliente, fecha, montoIngresado, metodo_pago, diasPagados);
	m_historial.AgregarPago(nuevo);
	m_historial.Guardar();

	m_historial = HistorialPagos("pagos.dat");
	std::vector<Pagos> pagos = m_historial.PagosDeCliente(m_dni_cliente);
	
	if (m_grilla_pagos->GetNumberRows() > 0) {
		m_grilla_pagos->DeleteRows(0, m_grilla_pagos->GetNumberRows());
	}
	
	m_grilla_pagos->AppendRows(pagos.size());
	
	for (size_t i = 0; i < pagos.size(); ++i) {
		m_grilla_pagos->SetCellValue(i, 0, std_to_wx(pagos[i].VerFecha()));
		
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(1) << pagos[i].VerMonto();
		m_grilla_pagos->SetCellValue(i, 1, std_to_wx(oss.str()));
		
		m_grilla_pagos->SetCellValue(i, 2, std_to_wx(pagos[i].VerMetodoPago()));
		m_grilla_pagos->SetCellValue(i, 3, std_to_wx(std::to_string(pagos[i].VerDiasPagados())));
	}
	
	m_grilla_pagos->ForceRefresh();
	
	// Limpiar campos
	txtmonto->Clear();
	m_grilla_pagos->ClearSelection();
	
	wxMessageBox("Pago registrado con éxito.", "Éxito", wxICON_INFORMATION);}


void Pagos_hijos::BtnImprimir( wxCommandEvent& event )  {
	std::string nombreArchivo = "factura_" + std::to_string(m_dni_cliente) + ".txt";
	std::ofstream out(nombreArchivo);
	
	if (!out.is_open()) {
		wxMessageBox("No se pudo crear la factura.", "Error", wxICON_ERROR);
		return;
	}
	
	out << "====== FACTURA DE PAGO ======\n";
	out << "Cliente: " << m_cliente.VerApellido() << ", " << m_cliente.VerNombre() << "\n";
	out << "DNI: " << m_cliente.Verdni() << "\n";
	out << "Actividad: " << m_cliente.VerActividad() << "\n";
	out << "-----------------------------\n";
	
	std::vector<Pagos> pagos = m_historial.PagosDeCliente(m_dni_cliente);
	double total = 0.0;
	
	for (const Pagos& p : pagos) {
		out << "Fecha: " << p.VerFecha()
			<< " | Monto: $" << p.VerMonto()
			<< " | Método: " << p.VerMetodoPago() << "\n";
		total += p.VerMonto();
	}
	
	out << "-----------------------------\n";
	out << "Total pagado: $" << total << "\n";
	
	double montoEsperado = CalcularMontoPorActividad(m_cliente.VerActividad());
	if (total < montoEsperado) {
		double deuda = montoEsperado - total;
		out << ">>> DEUDA PENDIENTE: $" << deuda << " <<<\n";
	}
	
	out.close();
	
	wxMessageBox("Factura generada correctamente.", "Factura", wxICON_INFORMATION);
	
	// Abrir con el bloc de notas
	wxExecute("notepad " + nombreArchivo, wxEXEC_ASYNC);
}

void Pagos_hijos::Ver_Pre( wxCommandEvent& event )  {
	wxString message = wxString::Format(
										"LISTA DE PRECIOS\n\n"
										"Funcional: $6.000\n"
										"Musculación: $5.000\n"
										"Boxeo: $7.000\n\n"
										);
	
	wxMessageBox(message, "Información de Precios", 
				 wxOK | wxICON_INFORMATION | wxCENTER);
}


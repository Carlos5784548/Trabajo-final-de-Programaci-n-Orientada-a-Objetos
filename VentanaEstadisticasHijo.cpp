#include "VentanaEstadisticasHijo.h"
#include <wx/listctrl.h>
#include <vector>
#include "Clientes.h"
#include "HistorialPagos.h"
#include <wx/wx.h>

VentanaEstadisticasHijo::VentanaEstadisticasHijo(wxWindow *parent) : VentanaEstadisticas(parent) {
	
}



void VentanaEstadisticasHijo::BtnFiltrar( wxCommandEvent& event )  {
	wxMessageBox("Botón aplicar filtros presionado");
	listaEstadisticas->DeleteAllItems();
	
	// Obtener filtros seleccionados
	std::string filtroAct = std::string(filtroActividad->GetStringSelection().mb_str());
	std::string filtroMet = std::string(filtroMetodo->GetStringSelection().mb_str());
	std::string filtroEstado = std::string(filtroEstadoCuenta->GetStringSelection().mb_str());
	
	wxDateTime desdeFecha = filtroDesde->GetValue();
	wxDateTime hastaFecha = filtroHasta->GetValue();
	
	int totalClientes = m_clientes->CantidadDatos();
	std::vector<Pagos> pagosTotales = m_historial->VerTodos();
	std::vector<Pagos> pagosFiltrados;
	
	// Filtrar pagos
	for (const auto& pago : pagosTotales) {
		std::string metodo = pago.VerMetodoPago();
		std::string fechaStr = pago.VerFecha();
		int dni = pago.VerDniCliente();
		Clientes* cli = m_clientes->BuscarPorDni(dni);
		
		if (!cli) continue;
		if (filtroAct != "Todas" && cli->VerActividad() != filtroAct) continue;
		if (filtroMet != "Todos" && metodo != filtroMet) continue;
		
		int d, m, a;
		sscanf(fechaStr.c_str(), "%d/%d/%d", &d, &m, &a);
		wxDateTime fechaPago(d, (wxDateTime::Month)(m - 1), a);
		
		if (fechaPago.IsValid() && (fechaPago < desdeFecha || fechaPago > hastaFecha)) continue;
		
		pagosFiltrados.push_back(pago);
	}
	
	// Calcular estadísticas
	double totalRecaudado = 0;
	std::string actividadFrecuente = "No disponible";
	int pagosUltimoMes = 0;
	
	if (!pagosFiltrados.empty()) {
		for (const auto& p : pagosFiltrados) {
			totalRecaudado += p.VerMonto();
		}
		
		Clientes* cli = m_clientes->BuscarPorDni(pagosFiltrados[0].VerDniCliente());
		if (cli) actividadFrecuente = cli->VerActividad();
		
		std::string ultimoMes = pagosFiltrados.back().VerFecha().substr(3, 7);
		for (const auto& p : pagosFiltrados) {
			if (p.VerFecha().substr(3, 7) == ultimoMes) pagosUltimoMes++;
		}
	}
	
	int alDia = 0, conDeuda = 0;
	for (int i = 0; i < totalClientes; ++i) {
		Clientes& cli = (*m_clientes)[i];
		
		if (filtroAct != "Todas" && cli.VerActividad() != filtroAct) continue;
		
		double deuda = cli.CalcularDeuda(*m_historial);
		
		if (deuda > 0) {
			if (filtroEstado == "Con deuda" || filtroEstado == "Todos") conDeuda++;
		} else {
			if (filtroEstado == "Al día" || filtroEstado == "Todos") alDia++;
		}
	}
	
	// Mostrar en wxListCtrl
	auto agregar = [&](const std::string& desc, const std::string& valor) {
		long i = listaEstadisticas->InsertItem(listaEstadisticas->GetItemCount(), desc);
		listaEstadisticas->SetItem(i, 1, valor);
	};
	
	agregar("Total de clientes registrados", std::to_string(totalClientes));
	agregar("Total recaudado (filtrado)", "$" + std::to_string((int)totalRecaudado));
	agregar("Pagos en " + (pagosFiltrados.empty() ? "-" : pagosFiltrados.back().VerFecha().substr(3, 7)), std::to_string(pagosUltimoMes));
	agregar("Actividad más frecuente (simple)", actividadFrecuente);
	agregar("Clientes al día", std::to_string(alDia));
	agregar("Clientes con deuda", std::to_string(conDeuda));
	
	wxMessageBox("Estadísticas actualizadas con éxito.",
				 "Filtrado aplicado",
				 wxICON_INFORMATION | wxOK);
}


void VentanaEstadisticasHijo::probar( wxCommandEvent& event )  {
	EndModal(wxID_CANCEL);}


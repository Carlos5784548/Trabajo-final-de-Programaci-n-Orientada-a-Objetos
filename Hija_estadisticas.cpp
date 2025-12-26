#include "Hija_estadisticas.h"
#include <wx/msgdlg.h>
#include "Pagos.h"
#include "Clientes.h"
#include "HistorialPagos.h"
#include "Lista_Clientes.h"
#include "Application.h"
#include "Lista_Asistencias.h"
// para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) { return wxString::From8BitData(std_str.c_str()); }

Hija_estadisticas::Hija_estadisticas(wxWindow* parent, Lista_Clientes* clientes, HistorialPagos* historial,Lista_Asistencias* asistencias)
	: Estadisticas(parent), m_clientes(clientes), m_historial(historial), m_listaAsistencias(asistencias){
}



Hija_estadisticas::~Hija_estadisticas() {
	
}
// 1. Limpiar la grilla de estadísticas
// 2. Verificar que existan datos de clientes e historial
// 3. Obtener los filtros seleccionados por el usuario
// 4. Filtrar los pagos según actividad, método, estado y fechas
// 5. Calcular estadísticas: total recaudado, actividad frecuente, pagos del último mes
// 6. Contar clientes al día y con deuda según los filtros
// 7. Mostrar los resultados en la grilla
// 8. Notificar al usuario que las estadísticas se actualizaron

void Hija_estadisticas::btnaplica(wxCommandEvent& event)  {
	grillaEstadisticas->ClearGrid();
	
	if (!m_clientes || !m_historial) {
		wxMessageBox("Faltan datos: lista de clientes o historial de pagos.", "Error", wxICON_ERROR);
		return;
	}
	
	// Filtros
	std::string filtroAct = std::string(filtroActividad->GetStringSelection().mb_str());
	std::string filtroMet = std::string(filtroMetodo->GetStringSelection().mb_str());
	std::string filtroEstado = std::string(filtroEstadoCuenta->GetStringSelection().mb_str());
	
	wxDateTime desdeFecha = filtroDesde->GetValue();
	wxDateTime hastaFecha = filtroHasta->GetValue();
	
	int totalClientes = m_clientes->CantidadDatos();
	std::vector<Pagos> pagosTotales = m_historial->VerTodos();
	std::vector<Pagos> pagosFiltrados;
	
	// Filtrado de pagos
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
	
	// Estadísticas
	double totalRecaudado = 0;
	std::string actividadFrecuente = "No disponible";
	int pagosUltimoMes = 0;
	
	if (!pagosFiltrados.empty()) {
		for (const auto& p : pagosFiltrados) {
			totalRecaudado += p.VerMonto();
		}
		
		Clientes* cli = m_clientes->BuscarPorDni(pagosFiltrados[0].VerDniCliente());
		if (cli) actividadFrecuente = cli->VerActividad();
		
		// Obtener mes y año del último pago filtrado
		int d, m, a;
		sscanf(pagosFiltrados.back().VerFecha().c_str(), "%d/%d/%d", &d, &m, &a);
		std::string mesAnioUltimoPago = (m < 10 ? "0" : "") + std::to_string(m) + "/" + std::to_string(a);
		
		for (const auto& p : pagosFiltrados) {
			int dd, mm, aa;
			sscanf(p.VerFecha().c_str(), "%d/%d/%d", &dd, &mm, &aa);
			std::string mesAnio = (mm < 10 ? "0" : "") + std::to_string(mm) + "/" + std::to_string(aa);
			
			if (mesAnio == mesAnioUltimoPago)
				pagosUltimoMes++;
		}
		
	}
	
	int alDia = 0, conDeuda = 0;
	
	for (int i = 0; i < totalClientes; ++i) {
		Clientes& cli = (*m_clientes)[i];
		
		if (filtroAct != "Todas" && cli.VerActividad() != filtroAct)
			continue;
		
		int diasDisponibles = cli.DiasDisponibles(*m_historial, *m_listaAsistencias);
		
		if (diasDisponibles > 0) {
			if (filtroEstado == "Al día" || filtroEstado == "Todos") alDia++;
		} else {
			if (filtroEstado == "Con deuda" || filtroEstado == "Todos") conDeuda++;
		}
	}
	
	
	// Asegura que la grilla tenga al menos 6 filas
	int rows = grillaEstadisticas->GetNumberRows();
	if (rows < 6) grillaEstadisticas->AppendRows(6 - rows);
	
	// Función lambda para cargar los datos en la grilla
	auto agregar = [this](int fila, const std::string& desc, const std::string& valor) {
		grillaEstadisticas->SetCellValue(fila, 0, std_to_wx(desc));
		grillaEstadisticas->SetCellValue(fila, 1, std_to_wx(valor));
	};
	
	agregar(0, "Total de clientes registrados", std::to_string(totalClientes));
	agregar(1, "Total recaudado (filtrado)", "$" + std::to_string((int)totalRecaudado));
	agregar(2, "Pagos en " + (pagosFiltrados.empty() ? "-" : pagosFiltrados.back().VerFecha().substr(3, 7)), std::to_string(pagosUltimoMes));
	agregar(3, "Actividad más frecuente (simple)", actividadFrecuente);
	agregar(4, "Clientes al día", std::to_string(alDia));
	agregar(5, "Clientes con deuda", std::to_string(conDeuda));
	
	wxMessageBox("Estadísticas actualizadas con éxito.", "Filtrado aplicado", wxICON_INFORMATION | wxOK);
}


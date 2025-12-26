#ifndef UTILS_PAGOS_H
#define UTILS_PAGOS_H

#include <string>

class UtilsPagos {
public:
	static double CalcularMontoPorActividad(const std::string& actividad);  // método estático
};

#endif

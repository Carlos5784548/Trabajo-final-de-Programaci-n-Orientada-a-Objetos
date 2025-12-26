# Trabajo-final-de-Programacion-Orientada-a-Objetos
🏋️ Sistema de Administración de Gimnasio – C++
📌 Descripción general

Este proyecto corresponde al trabajo final de Programación Orientada a Objetos desarrollado en C++, cuyo objetivo es implementar un sistema de administración de un gimnasio.

El sistema permite gestionar de forma integral la información de los clientes, sus asistencias, los pagos realizados y generar estadísticas, aplicando los principales conceptos de la POO y el uso de estructuras de datos de la STL.

🎯 Objetivos del proyecto

Aplicar Programación Orientada a Objetos en un caso real.

Utilizar clases, encapsulamiento, herencia y polimorfismo.

Manejar archivos binarios para persistencia de datos.

Implementar estructuras STL como vector.

Separar responsabilidades en módulos bien definidos.

Integrar una interfaz gráfica usando wxWidgets.

🧩 Funcionalidades principales
👤 Gestión de clientes

Alta, baja y modificación de clientes.

Búsqueda por distintos criterios (nombre, apellido, DNI, teléfono, email, etc.).

Validación de datos.

Persistencia de clientes en archivos binarios.

📅 Control de asistencias

Registro de asistencias por cliente y fecha.

Consulta de asistencias por DNI.

Cálculo de cantidad de asistencias.

Guardado y lectura desde archivo binario.

💳 Gestión de pagos

Registro de pagos realizados por los clientes.

Cálculo del total pagado por cliente.

Consulta del historial de pagos.

Determinación de deuda y vencimientos.

📊 Estadísticas

Generación de estadísticas a partir de clientes, pagos y asistencias.

Implementación mediante herencia sobre una ventana base (wxWidgets).

🛠️ Tecnologías y conceptos utilizados

Lenguaje: C++

Paradigma: Programación Orientada a Objetos

STL: vector, algoritmos de búsqueda y ordenamiento

Archivos: binarios (ifstream / ofstream)

Interfaz gráfica: wxWidgets

Diseño: separación por clases y módulos

Buenas prácticas: encapsulamiento, validaciones, comentarios y documentación

📁 Estructura general del proyecto

Clientes
Gestión de datos personales y lógica del cliente.

Lista_Clientes
Administración del conjunto de clientes.

Asistencias / Lista_Asistencias
Registro y control de asistencias.

Pagos / HistorialPagos
Manejo de pagos y cálculos financieros.

Estadísticas
Generación de reportes y métricas.

Archivos binarios para persistencia de datos.

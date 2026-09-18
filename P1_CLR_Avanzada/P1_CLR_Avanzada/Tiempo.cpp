#include "pch.h"
#include "Tiempo.h"
#include <ctime>
#include <iomanip>

Tiempo::Tiempo() : fechaActual(std::chrono::system_clock::now()) {}

void Tiempo::avanzarDias(int dias) {
    fechaActual += std::chrono::hours(24 * dias);
}

std::string Tiempo::obtenerFechaActual() const {
    auto tiempoT = std::chrono::system_clock::to_time_t(fechaActual);
    std::string fechaStr = std::ctime(&tiempoT);
    fechaStr.pop_back(); // Elimina el salto de línea final.
    return fechaStr;
}
std::chrono::system_clock::time_point Tiempo::obtenerFechaActualComoTimePoint() const {
    return fechaActual;
}
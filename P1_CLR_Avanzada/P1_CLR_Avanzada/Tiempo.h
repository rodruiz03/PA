#pragma once
#include <chrono>
#include <string>

class Tiempo {
public:
    Tiempo(); // Constructor que inicia con la fecha actual del sistema.

    void avanzarDias(int dias);
    std::string obtenerFechaActual() const;
    std::chrono::system_clock::time_point obtenerFechaActualComoTimePoint() const;

private:
    std::chrono::system_clock::time_point fechaActual;
};

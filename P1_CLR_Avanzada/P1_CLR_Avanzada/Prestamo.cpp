#include "pch.h"
#include "Prestamo.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

// Constructor
Prestamo::Prestamo(std::shared_ptr<Cliente> cliente, std::shared_ptr<Publicacion> publicacion, const std::string& fechaPrestamo)
    : cliente(cliente), publicacion(publicacion), fechaPrestamo(fechaPrestamo), prorrogado(false), devuelto(false) {
    // Inicializar la fecha de devolución con la fecha de préstamo, por defecto
    fechaDevolucion = fechaPrestamo;
}

// Método para prorrogar la fecha de devolución
void Prestamo::prorrogar() {
    if (!prorrogado && !devuelto) {
        std::tm tm = {};
        std::istringstream ss(fechaPrestamo);
        ss >> std::get_time(&tm, "%Y-%m-%d");
        std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        tp += std::chrono::hours(24 * 7); // Se añaden 7 días para la prórroga
        std::time_t t = std::chrono::system_clock::to_time_t(tp);
        std::tm* tm_ptr = std::localtime(&t);
        char buffer[11];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_ptr);
        fechaDevolucion = buffer;
        prorrogado = true;
    }
    else {
        std::cout << "El préstamo no puede ser prorrogado." << std::endl;
    }
}

// Método para realizar la devolución del préstamo
void Prestamo::realizarDevolucion(const std::string& fechaDevolucionStr) {
    if (!devuelto) {
        fechaDevolucion = fechaDevolucionStr;
        devuelto = true;
    }
    else {
        std::cout << "El préstamo ya fue devuelto." << std::endl;
    }
}

// Método para calcular la multa basada en la fecha real de devolución
double Prestamo::calcularMulta(const std::chrono::system_clock::time_point& fechaRealDevolucion) {
    std::tm tmFechaDevolucion = {};
    std::istringstream ssFechaDevolucion(fechaDevolucion);
    ssFechaDevolucion >> std::get_time(&tmFechaDevolucion, "%Y-%m-%d");
    std::chrono::system_clock::time_point tpFechaDevolucion = std::chrono::system_clock::from_time_t(std::mktime(&tmFechaDevolucion));
    std::chrono::system_clock::duration duracion = fechaRealDevolucion - tpFechaDevolucion;
    auto diasRetraso = std::chrono::duration_cast<std::chrono::hours>(duracion).count() / 24; // Conversión de horas a días

    if (diasRetraso > 0) {
        return diasRetraso * publicacion->calcularCuotaMulta(); // Se calcula la multa por día de retraso
    }
    return 0.0; // No hay multa si no hay retraso
}

// Getters
std::shared_ptr<Cliente> Prestamo::getCliente() const {
    return cliente;
}

std::shared_ptr<Publicacion> Prestamo::getPublicacion() const {
    return publicacion;
}

std::string Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

std::string Prestamo::getFechaDevolucion() const {
    return fechaDevolucion;
}

bool Prestamo::esProrrogado() const {
    return prorrogado;
}

bool Prestamo::esDevuelto() const {
    return devuelto;
}
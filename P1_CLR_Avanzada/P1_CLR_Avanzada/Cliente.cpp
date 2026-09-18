#include "pch.h"
#include "Cliente.h"
#include <iostream>
#include <chrono>

Cliente::Cliente(const std::string& id, const std::string& nombre, const std::string& direccion)
    : identidad(id), nombre(nombre), direccion(direccion), prestamosActivos(0), multasAcumuladas(0.0), prohibicionHasta(std::chrono::system_clock::now()) {}

void Cliente::mostrarDetalles() const {
    std::cout << "Cliente: " << nombre << "\nIdentidad: " << identidad << "\nDirección: " << direccion << std::endl;
}

void Cliente::incrementarPrestamos() {
    ++prestamosActivos;
}

void Cliente::decrementarPrestamos() {
    if (prestamosActivos > 0) {
        --prestamosActivos;
    }
}

int Cliente::getPrestamosActivos() const {
    return prestamosActivos;
}

bool Cliente::puedePrestar() const {
    return prestamosActivos < 5; // Suponiendo que 5 es el límite de préstamos activos permitidos
}

void Cliente::imponerProhibicionTemporal(int diasProhibicion) {
    prohibicionHasta = std::chrono::system_clock::now() + std::chrono::hours(diasProhibicion * 24);
}

bool Cliente::estaProhibido() const {
    return std::chrono::system_clock::now() < prohibicionHasta;
}

void Cliente::agregarMulta(double cantidad) {
    multasAcumuladas += cantidad;
}

double Cliente::obtenerMultasAcumuladas() const {
    return multasAcumuladas;
}

void Cliente::resetearMulta() {
    multasAcumuladas = 0.0;
}

std::string Cliente::getIdentidad() const {
    return identidad; // Devuelve el valor de la variable miembro identidad
}
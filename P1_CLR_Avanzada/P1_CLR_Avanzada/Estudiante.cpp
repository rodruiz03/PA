#include "pch.h"  // Encabezado precompilado para Visual Studio
#include "Estudiante.h"
#include <iostream>

Estudiante::Estudiante(const std::string& id, const std::string& nombre, const std::string& direccion)
    : Cliente(id, nombre, direccion) {}

void Estudiante::mostrarDetalles() const {
    Cliente::mostrarDetalles();
    std::cout << "Tipo de Cliente: Estudiante" << std::endl;
}

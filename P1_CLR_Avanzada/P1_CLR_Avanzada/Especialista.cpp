#include "pch.h"  // Encabezado precompilado para Visual Studio
#include "Especialista.h"
#include "Publicacion.h" // Asegúrate de que este include esté presente
#include <iostream>

Especialista::Especialista(const std::string& id, const std::string& nombre, const std::string& direccion)
    : Cliente(id, nombre, direccion) {}

void Especialista::mostrarDetalles() const {
    Cliente::mostrarDetalles();
    std::cout << "Tipo de Cliente: Especialista" << std::endl;
}

void Especialista::asignarPrecioPublicacion(Publicacion* publicacion, double precio) {
    // Lógica para asignar precio, suponiendo que Publicacion tiene setPrecio
}

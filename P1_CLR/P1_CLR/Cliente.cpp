#include "pch.h"
#include "iostream"
#include "Cliente.h"
#include "Publicacion.h"

Cliente::Cliente(const std::string& id, const std::string& nombre, const std::string& direccion)
    : identidad(id), nombre(nombre), direccion(direccion) {}

Cliente::~Cliente() {}

std::string Cliente::getIdentidad() const {
    return identidad;
}

std::string Cliente::getNombre() const {
    return nombre;
}

std::string Cliente::getDireccion() const {
    return direccion;
}

void Cliente::asignarPrecioPublicacion(Publicacion* publicacion, double precio) {
    // Implementación por defecto; los especialistas tendrán una implementación diferente
    std::cout << "Operación no permitida para clientes generales.\n";
}

#include "Cliente.h"
#include <string>

Cliente::Cliente(int id, std::string nombre, std::string direccion) : Usuario(id, nombre, direccion) {
    cantidadPrestamos = 0; // Al crear un cliente, no tiene préstamos
}

int Cliente::GetCantidadPrestamos() {
    return cantidadPrestamos;
}

void Cliente::SetCantidadPrestamos(int cantidad) {
    cantidadPrestamos = cantidad;
}

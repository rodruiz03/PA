#include "pch.h"
#include "cliente.h"

Cliente::Cliente(int id, String^ nombre, String^ direccion) : Usuario(id, nombre, direccion) {
    cantidadPrestamos = 0; // Al crear un cliente, no tiene préstamos
}

int Cliente::GetCantidadPrestamos() {
    return cantidadPrestamos;
}

void Cliente::SetCantidadPrestamos(int cantidad) {
    cantidadPrestamos = cantidad;
}
#include "pch.h"
#include "usuario.h"

Usuario::Usuario(int id, String^ nombre, String^ direccion) {
    this->id = id;
    this->nombre = nombre;
    this->direccion = direccion;
}

int Usuario::GetId() {
    return id;
}

String^ Usuario::GetNombre() {
    return nombre;
}

String^ Usuario::GetDireccion() {
    return direccion;
}

Cliente::Cliente(int id, String^ nombre, String^ direccion) : Usuario(id, nombre, direccion) {
    // Inicialización de información adicional de cliente
}

Especialista::Especialista(int id, String^ nombre, String^ direccion) : Usuario(id, nombre, direccion) {
    // Inicialización de información adicional de especialista
}

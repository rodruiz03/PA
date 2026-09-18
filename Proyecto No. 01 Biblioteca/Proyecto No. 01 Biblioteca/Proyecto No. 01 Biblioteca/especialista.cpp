#include "especialista.h"
#include <string>

especialista::especialista(int id, std::string nombre, std::string direccion, std::string especialidad) : Usuario(id, nombre, direccion) {
    this->especialidad = especialidad;
}

std::string especialista::GetEspecialidad() {
    return especialidad;
}

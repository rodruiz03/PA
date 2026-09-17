#include "especialista.h"

Especialista::Especialista(int id, String^ nombre, String^ direccion, String^ especialidad) : Usuario(id, nombre, direccion) {
    this->especialidad = especialidad;
}

String^ Especialista::GetEspecialidad() {
    return especialidad;
}

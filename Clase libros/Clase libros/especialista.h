#pragma once
#include "usuario.h"

ref class Especialista : public Usuario {
private:
    String^ especialidad;

public:
    Especialista(int id, String^ nombre, String^ direccion, String^ especialidad);
    String^ GetEspecialidad();
};

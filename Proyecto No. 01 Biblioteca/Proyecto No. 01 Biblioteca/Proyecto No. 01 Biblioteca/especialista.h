#pragma once
#include "Usuario.h"
#include <string>

class especialista : Usuario
{
private:
    std::string especialidad;

public:
    especialista(int id, std::string nombre, std::string direccion, std::string especialidad);
    std::string GetEspecialidad();
};


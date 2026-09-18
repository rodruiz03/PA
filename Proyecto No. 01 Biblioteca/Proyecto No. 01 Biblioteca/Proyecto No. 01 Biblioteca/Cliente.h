#pragma once
#include "Usuario.h"

class Cliente : Usuario
{
private:
    int cantidadPrestamos;

public:
    Cliente(int id, std::string nombre, std::string direccion);
    int GetCantidadPrestamos();
    void SetCantidadPrestamos(int cantidad);
};
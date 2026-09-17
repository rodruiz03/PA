#pragma once
#include "usuario.h"

ref class Cliente : public Usuario {
private:
    int cantidadPrestamos;

public:
    Cliente(int id, String^ nombre, String^ direccion);
    int GetCantidadPrestamos();
    void SetCantidadPrestamos(int cantidad);
};

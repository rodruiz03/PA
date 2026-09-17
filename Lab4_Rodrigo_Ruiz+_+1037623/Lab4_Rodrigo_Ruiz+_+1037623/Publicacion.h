#pragma once
#include <string>
#include <iostream>

using namespace std;

class Publicacion
{
protected:
    string fechaCreacion;
    string usuario;
    int cantidadReacciones;
    bool visible;

public:
    Publicacion(string fecha, string usuario);
    void ModificarReacciones(int cantidad);
    void ModificarVisibilidad(bool estado);
    virtual void Editar(string nuevoTitulo, string nuevoContenido) = 0;
};


#include "pch.h"
#include "Publicacion.h"

Publicacion::Publicacion(string fecha, string usuario) {
    fechaCreacion = fecha;
    this->usuario = usuario;
    cantidadReacciones = 0;
    visible = true;
}

void Publicacion::ModificarReacciones(int cantidad) {
    cantidadReacciones += cantidad;
}

void Publicacion::ModificarVisibilidad(bool estado) {
    visible = estado;
}

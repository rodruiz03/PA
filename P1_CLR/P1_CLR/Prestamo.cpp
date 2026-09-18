#include "pch.h"
#include "Prestamo.h"
#include "Cliente.h"
#include "Publicacion.h"

Prestamo::Prestamo(Cliente* cliente, Publicacion* publicacion, const std::string& fechaPrestamo)
    : cliente(cliente), publicacion(publicacion), fechaPrestamo(fechaPrestamo), devuelto(false) {}

void Prestamo::realizarDevolucion(const std::string& fechaDevolucion) {
    this->fechaDevolucion = fechaDevolucion;
    this->devuelto = true;
    publicacion->incrementarCantidad();
    // Aquí deberías incluir cualquier otra lógica necesaria cuando una publicación es devuelta
}

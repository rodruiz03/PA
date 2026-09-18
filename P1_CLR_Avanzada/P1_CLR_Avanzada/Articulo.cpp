#include "pch.h"
#include "Articulo.h"
#include <iostream>

Articulo::Articulo(int id, const std::string& titulo, const std::string& arbitro,
    const std::string& materia, int cantidad,
    const std::string& estado, double precio, int anio)
    : Publicacion(id, titulo, materia, cantidad, estado, precio, anio),
    arbitro(arbitro) {
    // Aquí puede ir lógica adicional para el constructor de Articulo, si es necesario.
}

void Articulo::mostrarDetalles() const {
    // Asegúrate de que esta implementación es correcta y concuerda con la declaración en Articulo.h
    std::cout << "Artículo: " << titulo << "\nÁrbitro: " << arbitro << "\nCantidad: " << cantidad << "\nEstado: " << estado << std::endl;
}

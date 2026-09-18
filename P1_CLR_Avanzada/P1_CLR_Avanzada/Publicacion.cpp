#include "pch.h"
#include "Publicacion.h"

Publicacion::Publicacion(int id, const std::string& titulo, const std::string& materia, int cantidad,
    const std::string& estado, double precio, int anio)
    : id(id), titulo(titulo), materia(materia), cantidad(cantidad), estado(estado),
    precio(precio), anio(anio), copiasDisponibles(cantidad) {
    // Constructor completo sin necesidad de definir setCantidad y getCantidad aquí
}

void Publicacion::setPrecio(double nuevoPrecio) {
    precio = nuevoPrecio;
}

double Publicacion::getPrecio() const {
    return precio;
}

void Publicacion::prestarCopia() {
    if (copiasDisponibles > 0) {
        --copiasDisponibles;
    }
    // Opcional: actualizar el estado si todas las copias están prestadas.
    estado = (copiasDisponibles > 0) ? estado : "agotado";
}

void Publicacion::devolverCopia() {
    if (copiasDisponibles < cantidad) {
        ++copiasDisponibles;
    }
    // Opcional: actualizar el estado si hay al menos una copia disponible.
    estado = (copiasDisponibles > 0) ? "disponible" : estado;
}

int Publicacion::getCopiasDisponibles() const {
    return copiasDisponibles;
}

double Publicacion::calcularCuotaMulta() const {
    double cuotaFinal = precio; // Usa el precio de la publicación como la cuota base de la multa

    // Aumenta la cuota basándose en la cantidad de copias disponibles
    if (cantidad < 10) {
        cuotaFinal += cuotaFinal * 0.30; // Añade el 30% del precio
    }
    else if (cantidad >= 11 && cantidad <= 20) {
        cuotaFinal += cuotaFinal * 0.20; // Añade el 20% del precio
    }
    else if (cantidad > 20) {
        cuotaFinal += cuotaFinal * 0.05; // Añade el 5% del precio
    }

    // Aquí podrías añadir cualquier otra lógica para ajustes adicionales basados en otros atributos si es necesario

    return cuotaFinal;
}


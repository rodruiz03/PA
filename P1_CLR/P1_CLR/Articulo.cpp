#include "pch.h"
#include "Articulo.h"

Articulo::Articulo(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta, const std::string& arbitro)
    : Publicacion(id, titulo, materia, cantidad, estado, precioMulta), arbitro(arbitro) {}

std::string Articulo::getArbitro() const {
    return arbitro;
}
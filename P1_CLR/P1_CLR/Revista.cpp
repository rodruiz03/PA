#include "pch.h"
#include "Revista.h"

Revista::Revista(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta, int ano, int numero)
    : Publicacion(id, titulo, materia, cantidad, estado, precioMulta), ano(ano), numero(numero) {}

int Revista::getAno() const {
    return ano;
}

int Revista::getNumero() const {
    return numero;
}
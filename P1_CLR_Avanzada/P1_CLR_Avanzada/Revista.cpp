#include "pch.h"
#include "Revista.h"
#include <iostream>

// Actualiza la implementación del constructor para incluir el año
Revista::Revista(int id, const std::string& titulo, int anio, int numero,
    const std::string& materia, int cantidad,
    const std::string& estado, double precio)
    : Publicacion(id, titulo, materia, cantidad, estado, precio, anio),
    numero(numero) {
    // Aquí puede ir lógica adicional para el constructor de Revista, si es necesario.
}

void Revista::mostrarDetalles() const {
    // Asegúrate de que esta implementación es correcta y concuerda con la declaración en Revista.h
    std::cout << "Revista: " << titulo << "\nAño: " << anio << "\nNúmero: " << numero << "\nCantidad: " << cantidad << "\nEstado: " << estado << std::endl;
}

#include "pch.h"
#include "Global.h"
#include <iostream>
#include <algorithm>


std::vector<std::shared_ptr<Cliente>> clientes;
std::vector<std::shared_ptr<Publicacion>> publicaciones;
std::vector<std::shared_ptr<Estudiante>> estudiantes;
std::vector<std::shared_ptr<Especialista>> especialistas;
std::vector<std::shared_ptr<Libro>> libros;
std::vector<std::shared_ptr<Revista>> revistas;
std::vector<std::shared_ptr<Articulo>> articulos;
std::vector<std::shared_ptr<Prestamo>> prestamos;

// Implementación de buscarClientePorId
std::shared_ptr<Cliente> buscarClientePorId(const std::string& identidad) {
    for (auto& estudiante : estudiantes) {
        if (estudiante->getIdentidad() == identidad) {
            return estudiante; // estudiante es ya un shared_ptr<Cliente>
        }
    }
    for (auto& especialista : especialistas) {
        if (especialista->getIdentidad() == identidad) {
            return especialista; // especialista es ya un shared_ptr<Cliente>
        }
    }
    return nullptr; // Si no se encuentra
}

std::shared_ptr<Publicacion> buscarPublicacionPorId(int id) {
    for (auto& libro : libros) {
        if (libro->getId() == id) {
            return libro; // libro es ya un shared_ptr<Publicacion>
        }
    }
    for (auto& revista : revistas) {
        if (revista->getId() == id) {
            return revista; // revista es ya un shared_ptr<Publicacion>
        }
    }
    for (auto& articulo : articulos) {
        if (articulo->getId() == id) {
            return articulo; // articulo es ya un shared_ptr<Publicacion>
        }
    }
    return nullptr; // Si no se encuentra
}

void buscarPorAnio(int anio) {
    bool encontrado = false;
    for (const auto& pub : publicaciones) {
        if (pub->getAnio() == anio) {
            pub->mostrarDetalles();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron publicaciones para el año ingresado." << std::endl;
    }
}

void buscarPorID(int id) {
    auto pub = buscarPublicacionPorId(id);
    if (pub) {
        pub->mostrarDetalles();
    }
    else {
        std::cout << "No se encontró una publicación con el ID ingresado." << std::endl;
    }
}

void buscarPorEditorial(const std::string& editorial) {
    bool encontrado = false;
    for (const auto& libro : libros) {
        if (libro->getEditorial() == editorial) {
            libro->mostrarDetalles();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron publicaciones para la editorial ingresada." << std::endl;
    }
}

void buscarPorAutor(const std::string& autor) {
    bool encontrado = false;
    for (const auto& libro : libros) {
        if (libro->getAutor() == autor) {
            libro->mostrarDetalles();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron publicaciones para el autor ingresado." << std::endl;
    }
}

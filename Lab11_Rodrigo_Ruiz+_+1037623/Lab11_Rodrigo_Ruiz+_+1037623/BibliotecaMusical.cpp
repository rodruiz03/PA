#include "pch.h"
#include "BibliotecaMusical.h"
#include <iostream>

void BibliotecaMusical::agregarLista(const ListaDeCanciones& lista) {
    listas.push_back(lista);
    std::cout << "Lista agregada exitosamente." << std::endl;
}

void BibliotecaMusical::mostrarListas() const {
    std::cout << "Listas disponibles:\n";
    for (const auto& lista : listas) {
        std::cout << "ID: " << lista.getId() << " - Nombre: " << lista.getNombre() << std::endl;
    }
}

void BibliotecaMusical::buscarCancionEnListas(const std::string& criterio) const {
    bool cancionEncontrada = false;
    for (const auto& lista : listas) {
        const auto& canciones = lista.getCanciones();
        for (const auto& cancion : canciones) {
            if (cancion.getNombre() == criterio || cancion.getArtista() == criterio || cancion.getGenero() == criterio) {
                std::cout << "Encontrado en la lista '" << lista.getNombre() << "':\n";
                cancion.mostrarInformacion();
                cancionEncontrada = true;
            }
        }
    }
    if (!cancionEncontrada) {
        std::cout << "No se encontraron canciones con el criterio proporcionado." << std::endl;
    }
}

void BibliotecaMusical::agregarCancionALista(int idCancion, int idLista, const Cancion& cancion) {
    for (auto& lista : listas) {
        if (lista.getId() == idLista) {
            lista.agregarCancion(cancion);
            return;
        }
    }
    std::cout << "Lista no encontrada." << std::endl;
}

void BibliotecaMusical::mostrarCancionesDeLista(int idLista) const {
    for (const auto& lista : listas) {
        if (lista.getId() == idLista) {
            lista.mostrarCanciones();
            return;
        }
    }
    std::cout << "Lista no encontrada." << std::endl;
}

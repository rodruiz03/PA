#include "pch.h"
#include "ListaDeCanciones.h"
#include <algorithm>
#include <iostream>

ListaDeCanciones::ListaDeCanciones(int id, std::string nombre, std::string fechaCreacion)
    : id(id), nombre(nombre), fechaCreacion(fechaCreacion) {}

void ListaDeCanciones::agregarCancion(const Cancion& cancion) {
    canciones.push_back(cancion);
    std::cout << "Canción agregada exitosamente a la lista: " << nombre << std::endl;
}

void ListaDeCanciones::eliminarCancion(int idCancion) {
    auto it = std::remove_if(canciones.begin(), canciones.end(),
        [idCancion](const Cancion& c) { return c.getId() == idCancion; });
    canciones.erase(it, canciones.end());
    std::cout << "Canción eliminada exitosamente." << std::endl;
}

void ListaDeCanciones::mostrarCanciones() const {
    std::cout << "Listando canciones en '" << nombre << "':\n";
    for (const auto& cancion : canciones) {
        cancion.mostrarInformacion();
    }
}

void ListaDeCanciones::buscarCancionPorNombre(const std::string& nombreBusqueda) const {
    bool found = false;
    for (const auto& cancion : canciones) {
        if (cancion.getNombre() == nombreBusqueda) {
            cancion.mostrarInformacion();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Canción no encontrada." << std::endl;
    }
}



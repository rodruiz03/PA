#pragma once
#include "pch.h"
#include "Cancion.h"
#include <string>
#include <list>

class ListaDeCanciones {
private:
    int id;
    std::string nombre;
    std::list<Cancion> canciones;
    std::string fechaCreacion;

public:
    ListaDeCanciones(int id, std::string nombre, std::string fechaCreacion);
    void agregarCancion(const Cancion& cancion);
    void eliminarCancion(int idCancion);
    void mostrarCanciones() const;
    void buscarCancionPorNombre(const std::string& nombre) const;
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    const std::list<Cancion>& getCanciones() const { return canciones; }
};


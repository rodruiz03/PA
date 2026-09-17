#pragma once
#include "pch.h"
#include <list>
#include "ListaDeCanciones.h"

class BibliotecaMusical {
private:
    std::list<ListaDeCanciones> listas;

public:
    void agregarLista(const ListaDeCanciones& lista);
    void mostrarListas() const;
    void buscarCancionEnListas(const std::string& criterio) const;
    void agregarCancionALista(int idCancion, int idLista, const Cancion& cancion);
    void mostrarCancionesDeLista(int idLista) const;
};

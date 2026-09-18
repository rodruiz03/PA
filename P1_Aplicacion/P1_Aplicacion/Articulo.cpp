#include "Articulo.h"


Articulo::Articulo() : Publicacion() {
}

Articulo::~Articulo() {
}

void Articulo::llenarDatos() {
    Publicacion::llenarDatos();
    std::cout << "Ingrese el árbitro del artículo: ";
    std::cin.ignore();
    std::getline(std::cin, arbitro);
}

std::string Articulo::getArbitro() const {
    return arbitro;
}

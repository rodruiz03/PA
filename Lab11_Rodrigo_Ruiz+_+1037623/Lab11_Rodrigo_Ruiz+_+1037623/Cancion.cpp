#include "pch.h"
#include "Cancion.h"
#include <iostream>

Cancion::Cancion(int id, std::string nombre, std::string artista, double duracion, std::string album, std::string genero, std::string linkPortada, int cantReproducciones)
    : id(id), nombre(nombre), artista(artista), duracion(duracion), album(album), genero(genero), linkPortada(linkPortada), cantReproducciones(cantReproducciones) {}

void Cancion::mostrarInformacion() const {
    std::cout << "ID: " << id << "\nNombre: " << nombre << "\nArtista: " << artista
        << "\nDuración: " << duracion << " mins\nÁlbum: " << album
        << "\nGénero: " << genero << "\nLink de Portada: " << linkPortada
        << "\nReproducciones: " << cantReproducciones << std::endl;
}

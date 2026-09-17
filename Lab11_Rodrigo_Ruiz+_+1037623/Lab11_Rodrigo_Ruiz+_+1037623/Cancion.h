#pragma once
#include "pch.h"
#include <string>

class Cancion {
private:
    int id;
    std::string nombre;
    std::string artista;
    double duracion;
    std::string album;
    std::string genero;
    std::string linkPortada;
    int cantReproducciones;

public:
    Cancion(int id, std::string nombre, std::string artista, double duracion, std::string album, std::string genero, std::string linkPortada, int cantReproducciones);
    void mostrarInformacion() const;
    // Getters y setters
    int getId() const { return id; }
    void setId(int id);
    std::string getNombre() const { return nombre; }
    void setNombre(const std::string& nombre);
    std::string getArtista() const { return artista; }
    std::string getGenero() const { return genero; }
    double getDuracion() const { return duracion; }
    void setDuracion(double duracion);
    std::string getAlbum() const { return album; }
    void setAlbum(const std::string& album);
    std::string getLinkPortada() const { return linkPortada; }
    void setLinkPortada(const std::string& linkPortada);
    int getCantReproducciones() const { return cantReproducciones; }
    void setCantReproducciones(int cantReproducciones);
};

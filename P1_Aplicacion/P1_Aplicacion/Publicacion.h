#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <iostream>
#include <string>

class Publicacion {
public:
    Publicacion();
    virtual ~Publicacion();

    virtual void llenarDatos() = 0;

    std::string getId() const;
    std::string getTitulo() const;
    std::string getMateria() const;
    int getCantidadEjemplares() const;
    int getCantidadDisponible() const;
    int getCantidadPrestamo() const;
    void prestarEjemplar();
    void devolverEjemplar();

protected:
    std::string id;
    std::string titulo;
    std::string materia;
    int cantidadEjemplares;
    std::string estado;

    int cantidadDisponible;
    int cantidadPrestamo;
};

#endif // PUBLICACION_H

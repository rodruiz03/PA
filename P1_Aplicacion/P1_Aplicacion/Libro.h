#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"

class Libro : public Publicacion {
public:
    Libro();
    virtual ~Libro();

    virtual void llenarDatos() override;

    std::string getAutor() const;
    std::string getEditorial() const;

private:
    std::string autor;
    std::string editorial;
};

#endif // LIBRO_H

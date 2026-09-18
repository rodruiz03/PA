#ifndef REVISTA_H
#define REVISTA_H

#include "Publicacion.h"

class Revista : public Publicacion {
public:
    Revista();
    virtual ~Revista();

    virtual void llenarDatos() override;

    int getAnio() const;
    int getNumero() const;

private:
    int anio;
    int numero;
};

#endif // REVISTA_H

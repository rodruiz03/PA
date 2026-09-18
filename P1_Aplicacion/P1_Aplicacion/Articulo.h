#ifndef ARTICULO_H
#define ARTICULO_H

#include "Publicacion.h"

class Articulo : public Publicacion {
public:
    Articulo();
    virtual ~Articulo();

    virtual void llenarDatos() override;

    std::string getArbitro() const;

private:
    std::string arbitro;
};

#endif // ARTICULO_H

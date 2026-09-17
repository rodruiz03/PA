#pragma once
#include "Publicacion.h"

class PublicacionImagen : public Publicacion
{
private:
    string linkImagen;
    int alto;
    int ancho;
    string formato;

public:
    PublicacionImagen(string fecha, string usuario, string link, int alto, int ancho, string formato);
    void Editar(string nuevoLink, int nuevoAlto, int nuevoAncho, string nuevoFormato);
};


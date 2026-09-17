#pragma once
#include "Publicacion.h"

 class PublicacionVideo : public Publicacion
{
private:
    string linkVideo;
    int duracion;

public:
    PublicacionVideo(string fecha, string usuario, string link, int duracion);
    void Editar(string nuevoLink, int nuevaDuracion);
};


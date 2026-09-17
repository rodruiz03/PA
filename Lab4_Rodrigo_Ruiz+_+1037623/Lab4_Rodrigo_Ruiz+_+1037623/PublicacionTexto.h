#pragma once
#include "Publicacion.h"

 class PublicacionTexto : public Publicacion
{
private:
    string titulo;
    string contenido;

public:
    PublicacionTexto(string fecha, string usuario, string titulo, string contenido);
    void Editar(string nuevoTitulo, string nuevoContenido) override;
};


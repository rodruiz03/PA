#include "pch.h"
#include "PublicacionImagen.h"

PublicacionImagen::PublicacionImagen(string fecha, string usuario, string link, int alto, int ancho, string formato)
    : Publicacion(fecha, usuario) {
    linkImagen = link;
    this->alto = alto;
    this->ancho = ancho;
    this->formato = formato;
}

void PublicacionImagen::Editar(string nuevoLink, int nuevoAlto, int nuevoAncho, string nuevoFormato) {
    linkImagen = nuevoLink;
    alto = nuevoAlto;
    ancho = nuevoAncho;
    formato = nuevoFormato;
}

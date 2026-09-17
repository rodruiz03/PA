#include "pch.h"
#include "PublicacionVideo.h"

PublicacionVideo::PublicacionVideo(string fecha, string usuario, string link, int duracion)
    : Publicacion(fecha, usuario) {
    linkVideo = link;
    this->duracion = duracion;
}

void PublicacionVideo::Editar(string nuevoLink, int nuevaDuracion) {
    linkVideo = nuevoLink;
    duracion = nuevaDuracion;
}
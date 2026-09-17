#include "pch.h"
#include "PublicacionTexto.h"

PublicacionTexto::PublicacionTexto(string fecha, string usuario, string titulo, string contenido)
    : Publicacion(fecha, usuario) {
    this->titulo = titulo;
    this->contenido = contenido;
}

void PublicacionTexto::Editar(string nuevoTitulo, string nuevoContenido) {
    titulo = nuevoTitulo;
    contenido = nuevoContenido;
}
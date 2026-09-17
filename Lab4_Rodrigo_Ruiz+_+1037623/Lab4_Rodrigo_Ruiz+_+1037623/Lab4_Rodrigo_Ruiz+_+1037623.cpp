#include <iostream>
#include "PublicacionTexto.h"
#include "PublicacionVideo.h"
#include "PublicacionImagen.h"

using namespace std;

int main() 
{
    // Crear instancias de publicaciones con clases concretas
    PublicacionTexto publicacionTexto("2024-02-11", "Usuario1", "Título original", "Contenido original");
    PublicacionVideo publicacionVideo("2024-02-11", "Usuario2", "https://ejemplo.com/video1", 120);
    PublicacionImagen publicacionImagen("2024-02-11", "Usuario3", "https://ejemplo.com/imagen1", 720, 1080, "JPEG");

    // Modificar reacciones
    publicacionTexto.ModificarReacciones(5);
    publicacionVideo.ModificarReacciones(3);
    publicacionImagen.ModificarReacciones(10);

    // Modificar visibilidad
    publicacionTexto.ModificarVisibilidad(false);

    // Editar publicaciones
    publicacionTexto.Editar("Nuevo título", "Nuevo contenido");
    publicacionVideo.Editar("https://ejemplo.com/nuevo_video", 150);
    publicacionImagen.Editar("https://ejemplo.com/nueva_imagen", 800, 1200, "PNG");

    return 0;
}

#pragma once
#include <memory>
#include <vector>
#include "Cliente.h"
#include "Publicacion.h"
#include "Estudiante.h"
#include "Especialista.h"
#include "Libro.h"
#include "Revista.h"
#include "Articulo.h"
#include "Prestamo.h"

extern std::vector<std::shared_ptr<Cliente>> clientes;
extern std::vector<std::shared_ptr<Publicacion>> publicaciones;
extern std::vector<std::shared_ptr<Estudiante>> estudiantes;
extern std::vector<std::shared_ptr<Especialista>> especialistas;
extern std::vector<std::shared_ptr<Libro>> libros;
extern std::vector<std::shared_ptr<Revista>> revistas;
extern std::vector<std::shared_ptr<Articulo>> articulos;
extern std::vector<std::shared_ptr<Prestamo>> prestamos;

std::shared_ptr<Cliente> buscarClientePorId(const std::string& identidad);
std::shared_ptr<Publicacion> buscarPublicacionPorId(int id);

// Declaraciones de nuevas funciones de búsqueda
void buscarPorAnio(int anio);
void buscarPorID(int id);
void buscarPorEditorial(const std::string& editorial);
void buscarPorAutor(const std::string& autor);
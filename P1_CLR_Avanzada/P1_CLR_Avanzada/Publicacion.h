#pragma once
#include <string>

class Publicacion {
protected:
    int id;
    std::string titulo;
    std::string materia;
    int cantidad;  // Total de copias de la publicación
    int copiasDisponibles;  // Copias disponibles para préstamo
    std::string estado;
    double precio;
    int anio;

public:
    Publicacion(int id, const std::string& titulo, const std::string& materia, int cantidad,
        const std::string& estado, double precio, int anio);
    virtual ~Publicacion() = default;

    int getId() const { return id; }  // Método para obtener el ID de la publicación

    virtual void mostrarDetalles() const = 0; // Método virtual puro que debe implementarse en clases derivadas.
    void setPrecio(double precio);
    double getPrecio() const;

    int getAnio() const { return anio; }
    void setAnio(int anio) { this->anio = anio; }

    void prestarCopia();  // Método para manejar el préstamo de una copia
    void devolverCopia();  // Método para manejar la devolución de una copia
    int getCopiasDisponibles() const;  // Método para obtener el número de copias disponibles

    int getCantidad() const { return cantidad; }
    void setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }

    double cuotaMultaDiaria = 10.50; // Valor por defecto
    virtual double calcularCuotaMulta() const; // Método que será sobreescrito por subclases si es necesario


};

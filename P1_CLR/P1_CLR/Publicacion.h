#pragma once
#include <string>

class Publicacion {
private:
    int id;
    std::string titulo;
    std::string materia;
    int cantidad;  // Declaración única de la variable cantidad
    std::string estado;
    double precioMulta;

public:
    Publicacion(int id, const std::string& titulo, const std::string& materia, int cantidad, const std::string& estado, double precioMulta);
    virtual ~Publicacion() = default;

    int getId() const;
    std::string getTitulo() const;
    std::string getMateria() const;
    int getCantidad() const;
    std::string getEstado() const;
    double getPrecioMulta() const;

    void decrementarCantidad() {
        if (cantidad > 0) cantidad--;
    }

    void incrementarCantidad() {
        cantidad++;
    }
};
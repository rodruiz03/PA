#pragma once
#include <string>
#include <chrono>

class Cliente {
protected:
    std::string identidad;
    std::string nombre;
    std::string direccion;
    int prestamosActivos; // Número de préstamos activos
    std::chrono::system_clock::time_point prohibicionHasta; // Fecha hasta la que está prohibido
    double multasAcumuladas; // Multas acumuladas

public:
    Cliente(const std::string& id, const std::string& nombre, const std::string& direccion);
    virtual ~Cliente() = default;

    virtual void mostrarDetalles() const;

    std::string getIdentidad() const;
    void incrementarPrestamos();
    void decrementarPrestamos();
    int getPrestamosActivos() const;
    bool puedePrestar() const;

    void imponerProhibicionTemporal(int diasProhibicion);
    bool estaProhibido() const;
    void agregarMulta(double cantidad);
    double obtenerMultasAcumuladas() const;
    void resetearMulta();
};



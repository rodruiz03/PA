#pragma once
#include "Cliente.h"
#include "Publicacion.h"
#include <string>
#include <memory>

class Prestamo {
private:
    std::shared_ptr<Cliente> cliente;
    std::shared_ptr<Publicacion> publicacion;
    std::string fechaPrestamo; // Fecha de préstamo como string
    std::string fechaDevolucion; // Fecha de devolución como string
    bool prorrogado;
    bool devuelto;

public:
    Prestamo(std::shared_ptr<Cliente> cliente, std::shared_ptr<Publicacion> publicacion, const std::string& fechaPrestamo);
    void prorrogar(); // Se actualiza para que no tome parámetros
    void realizarDevolucion(const std::string& fechaDevolucion); // Se mantiene el parámetro string

    std::shared_ptr<Cliente> getCliente() const;
    std::shared_ptr<Publicacion> getPublicacion() const;
    std::string getFechaPrestamo() const;
    std::string getFechaDevolucion() const;
    bool esProrrogado() const;
    bool esDevuelto() const;

    double calcularMulta(const std::chrono::system_clock::time_point& fechaRealDevolucion);
};


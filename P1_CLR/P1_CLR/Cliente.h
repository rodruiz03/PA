#pragma once
#include <string>

class Publicacion;  // Declaración anticipada para evitar inclusión circular

class Cliente {
protected:
    std::string identidad;
    std::string nombre;
    std::string direccion;

public:
    Cliente(const std::string& id, const std::string& nombre, const std::string& direccion);
    virtual ~Cliente();

    std::string getIdentidad() const;
    std::string getNombre() const;
    std::string getDireccion() const;

    virtual void asignarPrecioPublicacion(Publicacion* publicacion, double precio);
};


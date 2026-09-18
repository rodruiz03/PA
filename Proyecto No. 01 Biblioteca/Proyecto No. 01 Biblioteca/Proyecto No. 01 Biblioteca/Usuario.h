#pragma once
#include <iostream>
#include <string>

class Usuario {

public:
    Usuario() {}
	void getInfoUsuario();
	int crearUsuario(int tipoUsuario);
protected:
    int numId;
    std::string nombre;
    std::string direccion;

public:
    Usuario(int id, std::string nombre, std::string direccion);
    virtual ~Usuario() {} // Destructor virtual para que las clases derivadas puedan liberar memoria correctamente
    int GetId();
    std::string GetNombre();
    std::string GetDireccion();
};
    
class Cliente : public Usuario {
private:
    // Información adicional de cliente
public:
    Cliente(int id, std::string nombre, std::string direccion);
};

class especialista : public Usuario {
private:
    // Información adicional de especialista
public:
    especialista(int id, std::string nombre, std::string direccion);
};


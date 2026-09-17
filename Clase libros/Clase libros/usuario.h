#pragma once
#include <string>

using namespace System;

ref class Usuario {
protected:
    int id;
    String^ nombre;
    String^ direccion;

public:
    Usuario(int id, String^ nombre, String^ direccion);
    virtual ~Usuario() {} // Destructor virtual para que las clases derivadas puedan liberar memoria correctamente
    int GetId();
    String^ GetNombre();
    String^ GetDireccion();
};

ref class Cliente : public Usuario {
private:
    // Información adicional de cliente
public:
    Cliente(int id, String^ nombre, String^ direccion);
};

ref class Especialista : public Usuario {
private:
    // Información adicional de especialista
public:
    Especialista(int id, String^ nombre, String^ direccion);
};


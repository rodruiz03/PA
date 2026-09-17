#pragma once

using namespace System;

public ref class Ciclista
{
public:
    String^ nombre;
    String^ club;
    int puntos;
    int pruebasParticipadas;
    String^ tipoPrueba;

    Ciclista(String^ nombre, String^ club, String^ tipoPrueba)
    {
        this->nombre = nombre;
        this->club = club;
        this->puntos = 0;
        this->pruebasParticipadas = 0;
        this->tipoPrueba = tipoPrueba;
    }

    void AnadirPuntos(int pts)
    {
        puntos += pts;
    }

    void IncrementarPruebasParticipadas()
    {
        pruebasParticipadas++;
    }
};

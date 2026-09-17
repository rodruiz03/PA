#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char nombre[20]; 

    // Solicitar al usuario que ingrese su nombre
    cout << "Ingrese su nombre: ";
    cin.getline(nombre, sizeof(nombre));

    // Convertir el nombre a mayúsculas
    for (int i = 0; i < strlen(nombre); ++i) {
        nombre[i] = toupper(nombre[i]);
    }

    // Imprimir en pantalla el contenido del arreglo
    cout << "Nombre en mayusculas: " << nombre << endl;

    // Extender el arreglo para incluir su apellido
    char nombreApellido[30]; 
    strcpy_s(nombreApellido, nombre); 

    // Concatenar el apellido al arreglo existente
    cout << "Ingrese su apellido: ";
    cin.getline(nombreApellido + strlen(nombre), sizeof(nombreApellido) - strlen(nombre));

    // Imprimir en pantalla el contenido del nuevo arreglo
    cout << "Nombre y apellido en mayusculas: " << nombreApellido << endl;

    return 0;
}

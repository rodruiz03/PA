#include "pch.h"
#include <iostream>
#include "Calculadora.h"

using namespace System;

int main()
{
    int opcion;
    int resultado;
    int a, b;

    do {
        Console::WriteLine("Menu:");
        Console::WriteLine("1. Suma");
        Console::WriteLine("2. Resta");
        Console::WriteLine("3. Multiplicacion");
        Console::WriteLine("4. Division");
        Console::WriteLine("5. Potencia");
        Console::WriteLine("6. Radicacion");
        Console::WriteLine("7. Salir");
        Console::Write("Seleccione una opcion: ");
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> a;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> b;
            Calculadora::Suma(&resultado, a, b);
            std::cout << "El resultado es: " << resultado << std::endl;
            break;
        case 2:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> a;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> b;
            Calculadora::Resta(&resultado, a, b);
            std::cout << "El resultado es: " << resultado << std::endl;
            break;
        case 3:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> a;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> b;
            Calculadora::Multiplicacion(&resultado, a, b);
            std::cout << "El resultado es: " << resultado << std::endl;
            break;
        case 4:
            std::cout << "Ingrese el numerador: ";
            std::cin >> a;
            std::cout << "Ingrese el denominador: ";
            std::cin >> b;
            Calculadora::Division(&resultado, a, b);
            std::cout << "El resultado es: " << resultado << std::endl;
            break;
        case 5:
            std::cout << "Ingrese la base: ";
            std::cin >> a;
            std::cout << "Ingrese el exponente: ";
            std::cin >> b;
            Calculadora::Potencia(&resultado, a, b);
            std::cout << "El resultado es: " << resultado << std::endl;
            break;
        case 6:
            std::cout << "Ingrese el numero: ";
            std::cin >> a;
            std::cout << "Ingrese el indice de la raiz: ";
            std::cin >> b;
            Calculadora::Radicacion(&resultado, a, b);
            std::cout << "El resultado es: " << resultado << std::endl;
            break;
        case 7:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida. Por favor seleccione una opcion valida." << std::endl;
            break;
        }
    } while (opcion != 7);

    return 0;
}

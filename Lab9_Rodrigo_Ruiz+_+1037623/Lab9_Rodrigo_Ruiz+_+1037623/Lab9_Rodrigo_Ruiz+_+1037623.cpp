#include "pch.h"
#include <iostream>
#include <string>

int multiply(int a, int b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    return a + multiply(a, b - 1);
}

bool isOdd(int n);
bool isEven(int n) {
    if (n == 0) return true;
    return isOdd(n - 1);
}
bool isOdd(int n) {
    if (n == 0) return false;
    return isEven(n - 1);
}

bool esPalindroma(const std::string& palabra, int inicio, int fin) {
    if (inicio >= fin) return true;
    if (palabra[inicio] != palabra[fin]) return false;
    return esPalindroma(palabra, inicio + 1, fin - 1);
}

bool esPalindroma(const std::string& palabra) {
    return esPalindroma(palabra, 0, palabra.length() - 1);
}

int main() {
    int opcion = 0;
    do {
        std::cout << "Menu Principal\n";
        std::cout << "1. Multiplicar dos numeros\n";
        std::cout << "2. Determinar si un numero es par o impar\n";
        std::cout << "3. Verificar si una palabra es palindroma\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int num1, num2;
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            std::cout << "El resultado de la multiplicacioin es: " << multiply(num1, num2) << "\n";
            break;
        }
        case 2: {
            int num;
            std::cout << "Ingrese un numero: ";
            std::cin >> num;
            std::cout << "El número " << num << " es " << (isEven(num) ? "par" : "impar") << ".\n";
            break;
        }
        case 3: {
            std::string palabra;
            std::cout << "Ingrese una palabra: ";
            std::cin >> palabra;
            std::cout << "La palabra '" << palabra << "' " << (esPalindroma(palabra) ? "es" : "no es") << " palindroma.\n";
            break;
        }
        case 4:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opcion invalida, intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}


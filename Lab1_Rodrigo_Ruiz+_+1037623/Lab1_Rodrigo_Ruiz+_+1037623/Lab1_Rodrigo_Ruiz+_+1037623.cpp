#include "pch.h"

#include <iostream>

using namespace std;

int main() {
    int opcion;
    double num1, num2, resultado;

    while (true) {
        cout << "Calculadora Estándar\n";
        cout << "1. Suma (+)\n";
        cout << "2. Resta (-)\n";
        cout << "3. Multiplicación (*)\n";
        cout << "4. División (/)\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 5) break; // Salir del programa

        cout << "Ingrese el primer número: ";
        cin >> num1;
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora errores de entrada
            cout << "Entrada inválida. Por favor ingrese un número.\n";
            continue;
        }

        cout << "Ingrese el segundo número: ";
        cin >> num2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor ingrese un número.\n";
            continue;
        }

        if (opcion == 4 && num2 == 0) {
            cout << "Error: División por cero no permitida.\n";
            continue;
        }

        switch (opcion) {
        case 1: // Suma
            resultado = num1 + num2;
            cout << "El resultado de la suma es: " << resultado << endl;
            break;
        case 2: // Resta
            resultado = num1 - num2;
            cout << "El resultado de la resta es: " << resultado << endl;
            break;
        case 3: // Multiplicación
            if (num1 != 0 && num2 != 0) {
                resultado = num1 * num2;
                cout << "El resultado de la multiplicación es: " << resultado << endl;
            }
            else {
                cout << "Error: Multiplicación por cero.\n";
            }
            break;
        case 4: // División
            resultado = num1 / num2;
            cout << "El resultado de la división es: " << resultado << endl;
            break;
        default:
            cout << "Opción no válida.\n";
            break;
        }
    }
    return 0;
}

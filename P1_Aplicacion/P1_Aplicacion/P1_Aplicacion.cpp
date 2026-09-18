#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;

    do {
        cout << "----- Menu Principal -----" << endl;
        cout << "1. Indexar" << endl;
        cout << "2. Prestamos" << endl;
        cout << "3. Devoluciones" << endl;
        cout << "4. Registros" << endl;
        cout << "5. Busqueda de alguna publicacion" << endl;
        cout << "6. Pasar a determinado dia" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese la opcion deseada: " << endl;
        cout << " ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        {
            int opcionIndexar;
            cout << "Seleccione que desea indexar:" << endl;
            cout << "1. Cliente" << endl;
            cout << "2. Publicacion" << endl;
            cout << "3. Volver al menu principal" << endl;
            cout << "Ingrese la opcion deseada: ";
            cin >> opcionIndexar;

            if (opcionIndexar == 1) {
                int opcionCliente;
                cout << "Seleccione el tipo de cliente:" << endl;
                cout << "1. Estudiante" << endl;
                cout << "2. Especialista" << endl;
                cout << "3. Volver al menu principal" << endl;
                cout << "Ingrese la opcion deseada: ";
                cin >> opcionCliente;

                if (opcionCliente == 1) {
                    // Lógica para indexar un Estudiante
                }
                else if (opcionCliente == 2) {
                    // Lógica para indexar un Especialista
                }
                else if (opcionCliente == 3) {
                    // Volver al menu principal
                }
                else {
                    cout << "Opcion no valida. Intente de nuevo." << endl;
                }
            }
            else if (opcionIndexar == 2) {
                int opcionPublicacion;
                cout << "Seleccione el tipo de publicacion:" << endl;
                cout << "1. Libro" << endl;
                cout << "2. Articulo" << endl;
                cout << "3. Revista" << endl;
                cout << "4. Volver al menu principal" << endl;
                cout << "Ingrese la opcion deseada: ";
                cin >> opcionPublicacion;

                if (opcionPublicacion == 1) {
                    // Lógica para indexar un Libro
                }
                else if (opcionPublicacion == 2) {
                    // Lógica para indexar un Articulo
                }
                else if (opcionPublicacion == 3) {
                    // Lógica para indexar una Revista
                }
                else if (opcionPublicacion == 4) {
                    // Volver al menu principal
                }
                else {
                    cout << "Opcion no valida. Intente de nuevo." << endl;
                }
            }
            else if (opcionIndexar == 3) {
                // Volver al menu principal
            }
            else {
                cout << "Opcion no valida. Intente de nuevo." << endl;
            }

            break;
        }

        case 2:
            // Lógica para la opción Prestamos
            cout << "Seleccionaste Prestamos" << endl;
            break;
        case 3:
            // Lógica para la opción Devoluciones
            cout << "Seleccionaste Devoluciones" << endl;
            break;
        case 4:
            // Lógica para la opción Registros
            cout << "Seleccionaste Registros" << endl;
            break;
        case 5:
            // Lógica para la opción Busqueda de alguna publicacion
            cout << "Seleccionaste Busqueda de alguna publicacion" << endl;
            break;
        case 6:
            // Lógica para la opción Pasar a determinado dia
            cout << "Seleccionaste Pasar a determinado dia" << endl;
            break;
        case 7:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 7);

    return 0;
}
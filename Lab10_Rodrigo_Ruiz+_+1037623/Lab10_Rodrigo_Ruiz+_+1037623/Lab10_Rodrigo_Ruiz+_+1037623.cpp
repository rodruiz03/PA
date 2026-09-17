#include "pch.h"
#include "List.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\n--- Menú de Lista ---\n";
    std::cout << "1. Agregar un elemento al final de la lista\n";
    std::cout << "2. Eliminar todos los elementos\n";
    std::cout << "3. Cuenta la cantidad de elementos en la lista\n";
    std::cout << "4. Verifica si el elemento indicado se encuentra en la lista\n";
    std::cout << "5. Obtiene el índice de la primera ocurrencia del elemento indicado dentro de la lista\n";
    std::cout << "6. Inserta un elemento en una posición específica de la lista\n";
    std::cout << "7. Obtiene el valor del elemento en la posición indicada de la lista\n";
    std::cout << "8. Cambia el elemento en la posición indicada de la lista\n";
    std::cout << "9. Obtiene el índice de la última ocurrencia del elemento indicado dentro de la lista\n";
    std::cout << "10. Elimina la primera ocurrencia del elemento en la lista\n";
    std::cout << "11. Elimina el elemento en la posición de la lista indicada\n";
    std::cout << "12. Salir del programa\n";
    std::cout << "Seleccione una opción: ";
}

void clearCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    List myList;
    int choice, item, index;

    do {
        printMenu();
        std::cin >> choice;
        clearCin();

        switch (choice) {
        case 1:
            std::cout << "Ingrese un entero para añadir a la lista: ";
            std::cin >> item;
            clearCin();
            myList.Add(item);
            break;
        case 2:
            myList.Clear();
            std::cout << "Todos los elementos han sido eliminados.\n";
            break;
        case 3:
            std::cout << "Cantidad de elementos en la lista: " << myList.Count() << std::endl;
            break;
        case 4:
            std::cout << "Ingrese el entero a verificar: ";
            std::cin >> item;
            clearCin();
            if (myList.Contains(item))
                std::cout << "El elemento está en la lista.\n";
            else
                std::cout << "El elemento no se encuentra en la lista.\n";
            break;
        case 5:
            std::cout << "Ingrese el entero cuya primera ocurrencia desea encontrar: ";
            std::cin >> item;
            clearCin();
            index = myList.IndexOf(item);
            if (index != -1)
                std::cout << "Primera ocurrencia en índice: " << index << std::endl;
            else
                std::cout << "Elemento no encontrado." << std::endl;
            break;
        case 6:
            std::cout << "Ingrese un entero y un índice para insertar: ";
            std::cin >> item >> index;
            clearCin();
            try {
                myList.Insert(index, item);
            }
            catch (std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 7:
            std::cout << "Ingrese el índice para obtener el elemento: ";
            std::cin >> index;
            clearCin();
            try {
                item = myList.GetItem(index);
                std::cout << "Elemento en índice " << index << ": " << item << std::endl;
            }
            catch (std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 8:
            std::cout << "Ingrese índice y nuevo valor para el elemento: ";
            std::cin >> index >> item;
            clearCin();
            try {
                myList.SetItem(index, item);
                std::cout << "Elemento actualizado.\n";
            }
            catch (std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 9:
            std::cout << "Ingrese el entero cuya última ocurrencia desea encontrar: ";
            std::cin >> item;
            clearCin();
            index = myList.LastIndexOf(item);
            if (index != -1)
                std::cout << "Última ocurrencia en índice: " << index << std::endl;
            else
                std::cout << "Elemento no encontrado." << std::endl;
            break;
        case 10:
            std::cout << "Ingrese el entero a eliminar (primera ocurrencia): ";
            std::cin >> item;
            clearCin();
            if (!myList.Remove(item))
                std::cout << "Elemento no encontrado o no eliminado." << std::endl;
            break;
        case 11:
            std::cout << "Ingrese el índice del elemento a eliminar: ";
            std::cin >> index;
            clearCin();
            try {
                myList.RemoveAt(index);
            }
            catch (std::out_of_range& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            break;
        case 12:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción no válida, intente de nuevo.\n";
            break;
        }
    } while (choice != 12);

    return 0;
}


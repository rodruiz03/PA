#include "Usuario.h"
#include <string>

Usuario::Usuario(int id, std::string nombre, std::string direccion) {
	this->numId = id;
	this->nombre = nombre;
	this->direccion = direccion;
}
void Usuario::getInfoUsuario() {
	std::cout << "Numero de identidad: " << numId << std::endl;
	std::cout << "Nombre: " << nombre << std::endl;
	std::cout << "Direccion: " << direccion << std::endl;
}
int Usuario::GetId() {
	return numId;
}

std::string Usuario::GetNombre() {
	return nombre;
}

std::string Usuario::GetDireccion() {
	return direccion;
}

Cliente::Cliente(int id, std::string nombre, std::string direccion) : Usuario(id, nombre, direccion) {
	// Inicialización de información adicional de cliente
}

especialista::especialista(int id, std::string nombre, std::string direccion) : Usuario(id, nombre, direccion) {
	// Inicialización de información adicional de especialista
}
int Usuario::crearUsuario(int tipoUsuario) {
	std::cout << "** Crear un nuevo usuario **\n" << std::endl;
	std::cout << "Desea crear un usuario CLIENTE o ESPECIALISTA (1/2)" << std::endl;
	std::cin >> tipoUsuario;
	std::cout << "Ingrese su numero de identidad: " << std::endl;
	std::cin >> numId;
	while (numId < 0) {
		std::cout << "El valor ingresado es invalido. Intentelo de nuevo" << std::endl;
		std::cin >> numId;
	}
	std::cout << "Ingrese su nombre: " << std::endl;
	std::cin >> nombre;
	std::cout << "Ingrese su direccion: " << std::endl;
	std::cin >> direccion;
	return tipoUsuario;
}
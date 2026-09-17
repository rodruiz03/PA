#include "pch.h"
#include "Rectangulo.h"

// Constructor
Rectangulo::Rectangulo(double altura, double base) : altura(altura), base(base) {}

//2.1.1
int Rectangulo::area() {
	int area = (this->altura * this->base);
	return area;
}

//2.1.2
int Rectangulo::perimetro() {
	int perimetro = ((this->altura + this->base)*2);
	return perimetro;
}

//2.1.3
bool Rectangulo::cuadrado() {
	return altura == base;
}
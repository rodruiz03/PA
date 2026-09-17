#pragma once
ref class Rectangulo
{
	private:
		double altura;
		double base;

	public:

		//Constructor
		Rectangulo(double altura, double base);

		//Variables
		int area();
		int perimetro();
		bool cuadrado();
};


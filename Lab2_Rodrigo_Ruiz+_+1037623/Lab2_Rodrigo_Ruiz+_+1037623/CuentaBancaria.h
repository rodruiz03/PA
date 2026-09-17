#pragma once
#include <string>
#ifndef CUENTA_BANCARIA_H
#define CUENTA_BANCARIA_H


ref class CuentaBancaria
{
	private:
	int nombreTitular;// Cambiado de Str
	double saldo;
	int numeroCuenta;// Cambiado de Str

	public:
	// Constructor
	CuentaBancaria(int nombreTitular, double saldoInicial, int numeroCuenta);
	void depositar(double cantidad);
	bool retirar(double cantidad);
};

#endif // CUENTA_BANCARIA_H
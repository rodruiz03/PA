#include "pch.h"
#include "CuentaBancaria.h"
#include <iostream>

// Constructor
CuentaBancaria::CuentaBancaria(int nombreTitular, double saldoInicial, int numeroCuenta)
    : nombreTitular(nombreTitular), saldo(saldoInicial), numeroCuenta(numeroCuenta) {}

//2.2.1 (Depositar)
void CuentaBancaria::depositar(double cantidad) {
    saldo += cantidad;
}

//2.2.2 (Retirar)
bool CuentaBancaria::retirar(double cantidad) {
    if (cantidad > saldo) {
        return false;
    }

    saldo -= cantidad;
    return true;
}

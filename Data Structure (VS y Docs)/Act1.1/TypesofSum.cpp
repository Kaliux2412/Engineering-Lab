/*
 * Programa que calcula la suma de números enteros desde 1 hasta N
 * utilizando tres enfoques: iterativo, recursivo y fórmula directa.
 *
 * A01642979
 * 24/08/2026
 */

#include <iostream>
#include <stdexcept>

using namespace std;

/*
 * Calcula la suma desde 1 hasta n de forma iterativa.
 * n: limite superior de la suma.
 * Regresa el resultado acumulado de la suma.
 */
long iterativeSum(long n) {
    if (n < 0) {
        throw std::invalid_argument("Ingresa Valores Positivos");
    }
    
    long suma = 0;
    for (int i = 0; i <= n; i++) {
        suma = i + suma;
    }
    return suma;
}

/*
 * Calcula la suma desde 1 hasta n de forma recursiva.
 * n: limite superior de la suma.
 * Regresa el resultado de la suma recursiva.
 */
long recursiveSum(long n) {
    if (n < 0) {
        throw std::invalid_argument("Ingresa Valores Positivos");
    }
    if (n == 0) {
        return 0;
    }
    return n + recursiveSum(n - 1);
}

/*
 * Calcula la suma desde 1 hasta n utilizando la formula matemática directa.
 * n: limite superior de la suma.
 * Regresa el resultado directo de la formula.
 */
long directSum(long n) {
    if (n < 0) {
        throw std::invalid_argument("Ingresa Valores Positivos");
    }
    return (n * (n + 1)) / 2;
}

// Bloque main en donde se mandan a llamar los 3 tipos de funciones, con
// la configuracion del tray, catch y throw para arrojar mensajes de erros
// por si el numero ingresado es negativo.
int main() {
    long n = 0;
    
    cout << "Ingresa un numero positivo: " << endl;
    cin >> n;

    try {
        cout << "La suma Iterativa es: " << iterativeSum(n) << endl;
        cout << "La suma Recursiva es: " << recursiveSum(n) << endl;
        cout << "La suma Directa   es: " << directSum(n) << endl;
    } 
    catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
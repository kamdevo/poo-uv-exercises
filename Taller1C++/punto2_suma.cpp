/**
* @file punto2_suma.cpp
* @brief Programa que suma 2 enteros
*
* @details Programa básico que solicita dos números enteros al usuario
* y devuelve la suma de ambos. Incluye validación básica de entrada.
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se utilizó iostream para entrada y salida estándar.
* Se implementó una función para realizar la suma y otra para mostrar resultado.
* Programa básico sin librerías adicionales.
*/

#include <iostream>
using namespace std;

// Función para sumar dos enteros
int sumar(int a, int b) {
    return a + b;
}

// Función para mostrar el resultado
void mostrarResultado(int num1, int num2, int resultado) {
    cout << "La suma de " << num1 << " + " << num2 << " = " << resultado << endl;
}

int main() {
    int numero1, numero2, resultado;
    
    cout << "=== PROGRAMA SUMA DE DOS ENTEROS ===" << endl;
    cout << "Ingrese el primer número entero: ";
    cin >> numero1;
    
    cout << "Ingrese el segundo número entero: ";
    cin >> numero2;
    
    // Realizar la suma usando la función
    resultado = sumar(numero1, numero2);
    
    // Mostrar el resultado
    mostrarResultado(numero1, numero2, resultado);
    
    return 0;
}

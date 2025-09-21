/**
* @file punto3_raiz_cuadrada.cpp
* @brief Programa que calcula la raíz cuadrada de -1
*
* @details Demuestra el manejo de números complejos básicos en C++.
* Calcula la raíz cuadrada de -1 que matemáticamente es 'i' (unidad imaginaria).
* Muestra el concepto de números imaginarios de forma básica.
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se utilizó cmath para funciones matemáticas básicas.
* Se implementó manejo básico de números complejos sin usar <complex>.
* Se consultó sobre números imaginarios en matemáticas básicas.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Función para verificar si un número es negativo
bool esNegativo(double numero) {
    return numero < 0;
}

// Función para calcular raíz cuadrada de número positivo
double raizCuadradaPositiva(double numero) {
    return sqrt(numero);
}

// Función para mostrar resultado de raíz cuadrada de número negativo
void mostrarRaizNegativa(double numero) {
    double valorAbsoluto = -numero; // Convertir a positivo
    double raizDelAbsoluto = raizCuadradaPositiva(valorAbsoluto);
    
    cout << "La raíz cuadrada de " << numero << " es: " << raizDelAbsoluto << "i" << endl;
    cout << "Donde 'i' es la unidad imaginaria (i² = -1)" << endl;
}

int main() {
    double numero = -1;
    
    cout << "=== CÁLCULO DE RAÍZ CUADRADA DE -1 ===" << endl;
    cout << "Número a calcular: " << numero << endl;
    
    if (esNegativo(numero)) {
        cout << "El número es negativo." << endl;
        cout << "En números reales, no existe raíz cuadrada de números negativos." << endl;
        cout << "En números complejos:" << endl;
        mostrarRaizNegativa(numero);
        
        cout << endl << "EXPLICACIÓN:" << endl;
        cout << "√(-1) = i (unidad imaginaria)" << endl;
        cout << "√(-4) = 2i" << endl;
        cout << "√(-9) = 3i" << endl;
        cout << "En general: √(-n) = √(n) * i" << endl;
    } else {
        double resultado = raizCuadradaPositiva(numero);
        cout << "La raíz cuadrada de " << numero << " es: " << resultado << endl;
    }
    
    return 0;
}

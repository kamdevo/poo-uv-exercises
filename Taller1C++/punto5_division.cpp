/**
* @file punto5_division.cpp
* @brief Programa que divide 2 enteros con manejo de error para división por cero
*
* @details Solicita dos números enteros y realiza la división, manejando
* el caso especial de división por cero que es matemáticamente indeterminado.
* Muestra mensaje de error cuando el divisor es cero.
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se utilizó condicionales para validar división por cero.
* Se implementó manejo básico de errores sin excepciones.
* Se usó división entera y división con decimales para mostrar ambos resultados.
*/

#include <iostream>
using namespace std;

// Función para verificar si el divisor es cero
bool esDivisionPorCero(int divisor) {
    return divisor == 0;
}

// Función para realizar división entera
int divisionEntera(int dividendo, int divisor) {
    return dividendo / divisor;
}

// Función para realizar división con decimales
double divisionDecimal(int dividendo, int divisor) {
    return (double)dividendo / divisor;
}

// Función para mostrar resultado de división válida
void mostrarResultado(int dividendo, int divisor) {
    int resultadoEntero = divisionEntera(dividendo, divisor);
    double resultadoDecimal = divisionDecimal(dividendo, divisor);
    int residuo = dividendo % divisor;
    
    cout << "División: " << dividendo << " ÷ " << divisor << endl;
    cout << "Resultado entero: " << resultadoEntero << endl;
    cout << "Resultado decimal: " << resultadoDecimal << endl;
    cout << "Residuo: " << residuo << endl;
}

// Función para mostrar error de división por cero
void mostrarError() {
    cout << "ERROR: División por cero" << endl;
    cout << "La división por cero es matemáticamente indeterminada." << endl;
    cout << "No se puede realizar esta operación." << endl;
}

int main() {
    int dividendo, divisor;
    
    cout << "=== PROGRAMA DIVISIÓN DE ENTEROS ===" << endl;
    
    cout << "Ingrese el dividendo (número a dividir): ";
    cin >> dividendo;
    
    cout << "Ingrese el divisor (número por el cual dividir): ";
    cin >> divisor;
    
    // Verificar si es división por cero
    if (esDivisionPorCero(divisor)) {
        mostrarError();
    } else {
        mostrarResultado(dividendo, divisor);
    }
    
    return 0;
}

/**
* @file punto4_nombres.cpp
* @brief Programa que concatena dos nombres para formar nombre completo
*
* @details Solicita al usuario sus dos nombres (primer nombre y segundo nombre)
* y los concatena para mostrar el nombre completo. Utiliza strings básicos
* y operaciones de concatenación simples.
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se utilizó string para manejo de cadenas de texto.
* Se implementó concatenación básica con el operador +.
* Se usó getline para capturar nombres con espacios.
*/

#include <iostream>
#include <string>
using namespace std;

// Función para concatenar dos nombres
string concatenarNombres(string primerNombre, string segundoNombre) {
    return primerNombre + " " + segundoNombre;
}

// Función para mostrar el resultado
void mostrarNombreCompleto(string nombreCompleto) {
    cout << "Su nombre completo es: " << nombreCompleto << endl;
}

// Función para limpiar espacios al inicio y final
string limpiarEspacios(string texto) {
    // Eliminar espacios al inicio
    while (texto.length() > 0 && texto[0] == ' ') {
        texto = texto.substr(1);
    }
    
    // Eliminar espacios al final
    while (texto.length() > 0 && texto[texto.length()-1] == ' ') {
        texto = texto.substr(0, texto.length()-1);
    }
    
    return texto;
}

int main() {
    string primerNombre, segundoNombre, nombreCompleto;
    
    cout << "=== CONCATENACIÓN DE NOMBRES ===" << endl;
    
    cout << "Ingrese su primer nombre: ";
    getline(cin, primerNombre);
    
    cout << "Ingrese su segundo nombre: ";
    getline(cin, segundoNombre);
    
    // Limpiar espacios innecesarios
    primerNombre = limpiarEspacios(primerNombre);
    segundoNombre = limpiarEspacios(segundoNombre);
    
    // Concatenar los nombres
    nombreCompleto = concatenarNombres(primerNombre, segundoNombre);
    
    // Mostrar el resultado
    mostrarNombreCompleto(nombreCompleto);
    
    // Información adicional
    cout << endl << "INFORMACIÓN ADICIONAL:" << endl;
    cout << "Primer nombre: '" << primerNombre << "'" << endl;
    cout << "Segundo nombre: '" << segundoNombre << "'" << endl;
    cout << "Longitud total: " << nombreCompleto.length() << " caracteres" << endl;
    
    return 0;
}

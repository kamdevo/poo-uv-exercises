/**
* @file punto7_encriptar_cadena.cpp
* @brief Programa que encripta una cadena de 7 letras usando el algoritmo del punto 6
*
* @details Solicita una cadena de exactamente 7 letras minúsculas y aplica
* el algoritmo de clasificación del punto 6 a cada letra para generar
* un código encriptado de 7 dígitos (0s y 1s).
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se reutilizó el algoritmo del punto 6 para cada letra.
* Se implementó validación de longitud y tipo de caracteres.
* Se usó un ciclo for para procesar cada letra de la cadena.
*/

#include <iostream>
#include <string>
using namespace std;

// Función para validar si es una letra minúscula
bool esLetraMinuscula(char letra) {
    return letra >= 'a' && letra <= 'z';
}

// Función para clasificar una letra (algoritmo del punto 6)
int clasificarLetra(char letra) {
    // Rango a-n devuelve 0 (incluye 'm' y 'n')
    if (letra >= 'a' && letra <= 'n') {
        return 0;
    }
    // Rango o-z devuelve 1
    else if (letra >= 'o' && letra <= 'z') {
        return 1;
    }
    
    return -1; // Error
}

// Función para validar que la cadena tenga exactamente 7 letras minúsculas
bool validarCadena(string cadena) {
    if (cadena.length() != 7) {
        return false;
    }
    
    for (int i = 0; i < 7; i++) {
        if (!esLetraMinuscula(cadena[i])) {
            return false;
        }
    }
    
    return true;
}

// Función para encriptar la cadena
string encriptarCadena(string cadena) {
    string codigoEncriptado = "";
    
    for (int i = 0; i < 7; i++) {
        int codigo = clasificarLetra(cadena[i]);
        codigoEncriptado += to_string(codigo);
    }
    
    return codigoEncriptado;
}

// Función para mostrar el proceso de encriptación
void mostrarProceso(string cadena, string codigoEncriptado) {
    cout << "PROCESO DE ENCRIPTACIÓN:" << endl;
    cout << "Cadena original: " << cadena << endl;
    cout << "Letra por letra:" << endl;
    
    for (int i = 0; i < 7; i++) {
        char letra = cadena[i];
        int codigo = clasificarLetra(letra);
        string rango = (codigo == 0) ? "a-n" : "o-z";
        
        cout << "  " << letra << " -> " << codigo << " (rango " << rango << ")" << endl;
    }
    
    cout << "Código encriptado: " << codigoEncriptado << endl;
}

int main() {
    string cadena;
    
    cout << "=== ENCRIPTADOR DE CADENAS ===" << endl;
    cout << "Ingrese una cadena de exactamente 7 letras minúsculas: ";
    cin >> cadena;
    
    // Validar la cadena
    if (!validarCadena(cadena)) {
        cout << "Error: La cadena debe tener exactamente 7 letras minúsculas (a-z)" << endl;
        return 1;
    }
    
    // Encriptar la cadena
    string codigoEncriptado = encriptarCadena(cadena);
    
    // Mostrar el resultado
    mostrarProceso(cadena, codigoEncriptado);
    
    cout << endl << "ALGORITMO DE ENCRIPTACIÓN:" << endl;
    cout << "- Cada letra 'a' a 'n' se convierte en '0'" << endl;
    cout << "- Cada letra 'o' a 'z' se convierte en '1'" << endl;
    cout << "- El resultado es una secuencia de 7 dígitos binarios" << endl;
    
    return 0;
}

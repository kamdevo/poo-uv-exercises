/**
* @file punto6_clasificar_letra.cpp
* @brief Programa que clasifica una letra: devuelve 0 si está entre 'a'-'n', 1 si está entre 'm'-'z'
*
* @details Solicita una letra al usuario y determina en qué rango se encuentra.
* Nota: hay solapamiento en 'm' y 'n', se maneja dando prioridad al primer rango.
* Incluye validación para asegurar que la entrada sea una letra minúscula.
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se utilizó comparación de caracteres ASCII básica.
* Se implementó validación de entrada para letras minúsculas.
* Se manejó el solapamiento de 'm' y 'n' dando prioridad al rango a-n.
*/

#include <iostream>
using namespace std;

// Función para validar si es una letra minúscula
bool esLetraMinuscula(char letra) {
    return letra >= 'a' && letra <= 'z';
}

// Función para clasificar la letra según los rangos especificados
int clasificarLetra(char letra) {
    // Rango a-n devuelve 0 (incluye 'm' y 'n')
    if (letra >= 'a' && letra <= 'n') {
        return 0;
    }
    // Rango m-z devuelve 1 (pero 'm' y 'n' ya fueron clasificados como 0)
    else if (letra >= 'm' && letra <= 'z') {
        return 1;
    }
    
    return -1; // Error (no debería llegar aquí si la validación es correcta)
}

// Función para mostrar el resultado
void mostrarResultado(char letra, int codigo) {
    cout << "La letra '" << letra << "' tiene código: " << codigo << endl;
    
    if (codigo == 0) {
        cout << "Esta letra está en el rango 'a' - 'n'" << endl;
    } else if (codigo == 1) {
        cout << "Esta letra está en el rango 'o' - 'z'" << endl;
        cout << "(Nota: 'm' y 'n' se clasifican como 0 por prioridad)" << endl;
    }
}

int main() {
    char letra;
    
    cout << "=== CLASIFICADOR DE LETRAS ===" << endl;
    cout << "Ingrese una letra minúscula: ";
    cin >> letra;
    
    // Validar que sea una letra minúscula
    if (!esLetraMinuscula(letra)) {
        cout << "Error: Debe ingresar una letra minúscula (a-z)" << endl;
        return 1;
    }
    
    // Clasificar la letra
    int codigo = clasificarLetra(letra);
    
    // Mostrar resultado
    mostrarResultado(letra, codigo);
    
    cout << endl << "EXPLICACIÓN DEL ALGORITMO:" << endl;
    cout << "- Letras 'a' a 'n': código 0" << endl;
    cout << "- Letras 'o' a 'z': código 1" << endl;
    cout << "- Nota: 'm' y 'n' tienen prioridad en el primer rango" << endl;
    
    return 0;
}

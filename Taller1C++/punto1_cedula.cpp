/**
* @file punto1_cedula.cpp
* @brief Programa que implementa la variable cédula como string y número
*
* @details Demuestra el uso de cédula como string y como entero, mostrando
* las ventajas y desventajas de cada representación. Incluye validaciones
* básicas y operaciones comunes con cédulas.
* @author [Tu Nombre]
* @mail [tu.email@correounivalle.edu.co]
* @date 2025-09-10
* @version 1.0
*
* @comentario: Se utilizó string para mantener ceros a la izquierda y facilitar
* validaciones. Se usó int para operaciones matemáticas básicas.
* Se consultó sobre conversiones entre string e int en cppreference.com
*/

#include <iostream>
#include <string>
using namespace std;

// Función para validar cédula como string
bool validarCedulaString(string cedula) {
    if (cedula.length() < 6 || cedula.length() > 10) {
        return false;
    }
    
    for (int i = 0; i < cedula.length(); i++) {
        if (cedula[i] < '0' || cedula[i] > '9') {
            return false;
        }
    }
    return true;
}

// Función para validar cédula como número
bool validarCedulaNumero(int cedula) {
    return cedula >= 100000 && cedula <= 9999999999;
}

// Función para mostrar información de cédula como string
void mostrarCedulaString(string cedula) {
    cout << "Cédula como string: " << cedula << endl;
    cout << "Longitud: " << cedula.length() << " dígitos" << endl;
    cout << "Primer dígito: " << cedula[0] << endl;
    cout << "Último dígito: " << cedula[cedula.length()-1] << endl;
}

// Función para mostrar información de cédula como número
void mostrarCedulaNumero(int cedula) {
    cout << "Cédula como número: " << cedula << endl;
    cout << "Es par: " << (cedula % 2 == 0 ? "Sí" : "No") << endl;
    cout << "Suma de verificación: " << cedula % 10 << endl;
}

int main() {
    // Ejemplo con cédula como string
    string cedulaStr = "0012345678";
    cout << "=== CÉDULA COMO STRING ===" << endl;
    
    if (validarCedulaString(cedulaStr)) {
        mostrarCedulaString(cedulaStr);
        cout << "Ventaja: Mantiene ceros a la izquierda" << endl;
    } else {
        cout << "Cédula string inválida" << endl;
    }
    
    cout << endl;
    
    // Ejemplo con cédula como número
    int cedulaNum = 12345678;
    cout << "=== CÉDULA COMO NÚMERO ===" << endl;
    
    if (validarCedulaNumero(cedulaNum)) {
        mostrarCedulaNumero(cedulaNum);
        cout << "Ventaja: Permite operaciones matemáticas" << endl;
    } else {
        cout << "Cédula numérica inválida" << endl;
    }
    
    cout << endl;
    cout << "CONCLUSIÓN: Se recomienda usar string para cédulas" << endl;
    cout << "porque preserva el formato original y evita problemas" << endl;
    cout << "con ceros a la izquierda." << endl;
    
    return 0;
}

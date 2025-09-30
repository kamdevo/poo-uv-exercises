#include "InputHandler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;


std::string InputHandler::validateProvince() {
    while(true)
        {
            int choice = getValidatedInput("Ingrese el número correspondiente a su departamento: ");
            switch (choice) {
            case 1: return "Putumayo";
            case 2: return "Cauca";
            case 3: return "Valle del Cauca";
            case 4: return "Amazonas";
            case 5: return "Risaralda";
            case 6: return "Antioquia";
            case 7: return "Norte de Santander";
            case 8: return "Chocó";
            case 9: return "Arauca";
            case 10: return "Guainía";
            default:
                std::cout << "Elección inválida. Por favor, elige un número entre 1 y 10." << std::endl;
                
                break;
            }
        } 
}

//metodo mapProvince para mapear la elección numérica al nombre del departamento
std::string InputHandler::mapProvince(int choice) {
    switch (choice) {
        case 1: return "Putumayo";
        case 2: return "Cauca";
        case 3: return "Valle del Cauca";
        case 4: return "Amazonas";
        case 5: return "Risaralda";
        case 6: return "Antioquia";
        case 7: return "Norte de Santander";
        case 8: return "Chocó";
        case 9: return "Arauca";
        case 10: return "Guainía";
        default: return "";
    }
}




// el metodo validateBloodType consulta el valor escogido y retorna el tipo de sangre correspondiente (string)
// si la opción es inválida, muestra un mensaje y vuelve a pedir la entrada
std::string InputHandler::validateBloodType() {
    while(true)
        {
            int choice = getValidatedInput("Ingrese el número correspondiente a su tipo de sangre: ");
            switch (choice) {
            case 1: return "A+";
            case 2: return "A-";
            case 3: return "B+";
            case 4: return "B-";
            case 5: return "AB+";
            case 6: return "AB-";
            case 7: return "O+";
            case 8: return "O-";
            default:
                std::cout << "Elección inválida. Por favor, elige un número entre 1 y 8." << std::endl;
                
                break;
            }
        } 
}


int InputHandler::getValidatedInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                throw std::invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = std::stoi(input);
            break; // si la conversión es exitosa, salir del bucle
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
        }
    }
    return value;
}

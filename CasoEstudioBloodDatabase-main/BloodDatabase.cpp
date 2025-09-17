
/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando 
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    El código se basó en el proyecto BloodDatabase, fue traducido al español 
    y adaptado a las necesidades del curso.

    

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#include "BloodDatabase.h"
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

void BloodDatabase::displayProvinces() {
    std::cout << "Elige el departamento:\n";
    std::cout << "1. Putumayo\n";
    std::cout << "2. Cauca\n";
    std::cout << "3. Valle del Cauca\n";
    std::cout << "4. Amazonas\n";
    std::cout << "5. Risaralda\n";
    std::cout << "6. Antioquia\n";
    std::cout << "7. Norte de Santander\n";
    std::cout << "8. Chocó\n";
    std::cout << "9. Arauca\n";
    std::cout << "10. Guainía\n";
}

std::string BloodDatabase::validateProvince() {
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

//metodo displayBloodType para mostrar los tipos de sangre
void BloodDatabase::displayBloodTypes() {
    std::cout << "Elige tu tipo de sangre:\n";
    std::cout << "1. A+\n";
    std::cout << "2. A-\n";
    std::cout << "3. B+\n";
    std::cout << "4. B-\n";
    std::cout << "5. AB+\n";
    std::cout << "6. AB-\n";
    std::cout << "7. O+\n";
    std::cout << "8. O-\n";
}

// el metodo validateBloodType consulta el valor escogido y retorna el tipo de sangre correspondiente (string)
// si la opción es inválida, muestra un mensaje y vuelve a pedir la entrada
std::string BloodDatabase::validateBloodType() {
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

std::string BloodDatabase::mapProvince(int choice) {
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

void BloodDatabase::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    //   system("clear");
#endif
}

void BloodDatabase::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int BloodDatabase::getValidatedInput(const std::string& prompt) {
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

void BloodDatabase::getDonorDetails() {
    clearConsole();
    std::cout << "Ingrese los detalles del donante\n";

    Donor newDonor;
    newDonor.donorId = getValidatedInput("Id: ");
    std::cin.ignore(); // Limpiar el buffer después de getValidatedInput
    std::cout << "Nombre: ";
    std::getline(std::cin, newDonor.name);
    std::cout << "Dirección: ";
    std::getline(std::cin, newDonor.address);

    displayProvinces();
    newDonor.district = validateProvince();



    //Se muestra el menú de tipos de sangre
    displayBloodTypes();


    //Se valida y se asigna el tipo de sangre
    newDonor.bloodType = validateBloodType();

    //debido a que se modificó el tipo de dato de "number" de int a string, cambia la forma de capturarlo
    std::cout << "Número: ";
    std::getline(std::cin, newDonor.number);   //newDonor.number = getValidatedInput("Número: ");

    donors.push_back(newDonor);
}

void BloodDatabase::writeDataToFile() {
    std::ofstream outfile(fileName, std::ios::app);

    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    Donor newDonor = donors.back();
    outfile << newDonor.donorId << ",    " << newDonor.name << ",    " << newDonor.address << ",    " << newDonor.district << ",    " << newDonor.bloodType << ",    " << newDonor.number << std::endl;

    outfile.close();
}

void BloodDatabase::searchAndDisplay() const {
    clearConsole();
    displayProvinces();
    int provinceChoice = getValidatedInput("Ingrese el número de la departamento: ");
    std::cin.ignore(); // Limpiar el buffer después de getValidatedInput
    std::string provinceName = mapProvince(provinceChoice);
    
    if (provinceName.empty()) {
        std::cout << "Número de departamento inválido. Debe estar entre 1 y 10.\n";
        return;
    }

    std::cout << "Ingrese la dirección (dejar en blanco para omitir): ";
    std::string addressFilter;
    std::getline(std::cin, addressFilter);

    std::cout << "Ingrese el tipo de sangre (dejar en blanco para omitir): ";
    std::string bloodTypeFilter;
    std::getline(std::cin, bloodTypeFilter);

    std::ifstream inFile(fileName);

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> donors;
    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        bool match = d.district == provinceName &&
            (addressFilter.empty() || d.address.find(addressFilter) != std::string::npos) &&
            (bloodTypeFilter.empty() || d.bloodType == bloodTypeFilter);

        if (match) {
            donors.push_back(d);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No se encontraron personas de la departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        if (!bloodTypeFilter.empty()) {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
        }
        std::cout << "." << std::endl;
    } else {
        std::cout << "Personas de la departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'";
        }
        if (!bloodTypeFilter.empty()) {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
        }
        std::cout << ":" << std::endl;
        for (const auto& d : donors) {
            std::cout << "Nombre: " << d.name << std::endl;
            std::cout << "Dirección: " << d.address << std::endl;
            std::cout << "departamento: " << d.district << std::endl;
            std::cout << "Tipo de sangre: " << d.bloodType << std::endl;
            std::cout << "Número de móvil: " << d.number << std::endl;
            std::cout << std::endl;
        }
    }

    inFile.close();
    waitForKeyPress();
}

void BloodDatabase::deleteDonor(const std::string& donorName) {
    std::ifstream inFile(fileName);
    std::ofstream tempFile("temp.txt");

    if (!inFile) {
        std::cerr << "Error al abrir el archivo " << fileName << std::endl;
        return;
    }

    if (!tempFile) {
        std::cerr << "Error al crear el archivo temporal" << std::endl;
        return;
    }

    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        if (d.name == donorName) {
            found = true;
            std::cout << "Nombre: " << d.name << std::endl;
            std::cout << "Dirección: " << d.address << std::endl;
            std::cout << "Tipo de sangre: " << d.bloodType << std::endl;
            std::cout << "Número de móvil: " << d.number << std::endl;
            std::cout << std::endl;
            std::cout << "¿Está seguro de que desea eliminar al donante? [s/n]: ";
            char sureChoice;
            std::cin >> sureChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

            if (sureChoice == 's' || sureChoice == 'S') {
                continue;
            }
        }

        tempFile << d.donorId << ",    " << d.name << ",    " << d.address << ",    " << d.district << ",    " << d.bloodType << ",    " << d.number << std::endl;
    }

    inFile.close();
    tempFile.close();

    if (std::remove(fileName.c_str()) != 0) {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    if (std::rename("temp.txt", fileName.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
        return;
    }

    if (!found) {
        std::cout << "No se encontró ningún donante con el nombre " << donorName << std::endl;
    }
}

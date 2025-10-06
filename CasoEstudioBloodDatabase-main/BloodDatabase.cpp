
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


void BloodDatabase::displayDonorDetails(const Donor& donor) {
    std::cout << "ID del donante: " << donor.getDonorId() << std::endl;
    std::cout << "Nombre: " << donor.getName() << std::endl;
    std::cout << "Dirección: " << donor.getAddress() << std::endl;
    std::cout << "Departamento: " << donor.getDistrict() << std::endl;
    std::cout << "Tipo de sangre: " << donor.getBloodType() << std::endl;
    std::cout << "Edad: " << donor.getAge() << std::endl;
    std::cout << "Número de móvil: " << donor.getNumber() << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void BloodDatabase::getDonorDetails() {
    clearConsole();
    std::cout << "Ingrese los detalles del donante\n";

    Donor newDonor;
    newDonor.setDonorId(InputHandler::getValidatedInput("Id: "));

    std::cout << "Nombre: ";
    std::string nameInput;
    std::getline(std::cin, nameInput);
    newDonor.setName(nameInput);
    std::cout << "Dirección: ";
    std::string addressInput;
    std::getline(std::cin, addressInput);
    newDonor.setAddress(addressInput);

    displayProvinces();
    newDonor.setDistrict(InputHandler::validateProvince());

    newDonor.setAge(InputHandler::getValidatedInput("Edad: "));

    //Se muestra el menú de tipos de sangre
    displayBloodTypes();


    //Se valida y se asigna el tipo de sangre
    newDonor.setBloodType(InputHandler::validateBloodType());

    //debido a que se modificó el tipo de dato de "number" de int a string, cambia la forma de capturarlo
    std::cout << "Número: ";
    std::string numberInput;
    std::getline(std::cin, numberInput);
    newDonor.setNumber(numberInput);   //newDonor.number = getValidatedInput("Número: ");

    donors.push_back(newDonor);
    
    newDonor.donorDetails(newDonor);
    waitForKeyPress();
    
}

void BloodDatabase::writeDataToFile() {
    std::ofstream outfile(fileName, std::ios::app);

    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    Donor newDonor = donors.back();
    outfile << newDonor.getDonorId() << ",    " << newDonor.getName() << ",    " << newDonor.getAddress() << ",    " << newDonor.getDistrict() << ",    " << newDonor.getBloodType() << ",    " << newDonor.getAge() << ",    " << newDonor.getNumber() << std::endl;

    outfile.close();
}

void BloodDatabase::searchAndDisplay() const {
    clearConsole();
    displayProvinces();
    int provinceChoice = InputHandler::getValidatedInput("Ingrese el número de la departamento: ");
    std::cin.ignore(); // Limpiar el buffer después de getValidatedInput
    std::string provinceName = InputHandler::mapProvince(provinceChoice);
    
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
        bool match = d.getDistrict() == provinceName &&
            (addressFilter.empty() || d.getAddress().find(addressFilter) != std::string::npos) &&
            (bloodTypeFilter.empty() || d.getBloodType() == bloodTypeFilter);

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
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Dirección: " << d.getAddress() << std::endl;
            std::cout << "departamento: " << d.getDistrict() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Edad: " << d.getAge() << std::endl;
            std::cout << "Número de móvil: " << d.getNumber() << std::endl;
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
        if (d.getName() == donorName) {
            found = true;
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Dirección: " << d.getAddress() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Edad: " << d.getAge() << std::endl;
            std::cout << "Número de móvil: " << d.getNumber() << std::endl;
            std::cout << std::endl;
            std::cout << "¿Está seguro de que desea eliminar al donante? [s/n]: ";
            char sureChoice;
            std::cin >> sureChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar cualquier entrada extra

            if (sureChoice == 's' || sureChoice == 'S') {
                continue;
            }
        }

        tempFile << d.getDonorId() << ",    " << d.getName() << ",    " << d.getAddress() << ",    " << d.getDistrict() << ",    " << d.getBloodType() << ",    " << d.getAge() << ",    " << d.getNumber() << std::endl;
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

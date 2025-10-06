/*
    Proyecto: BloodDatabase (Adaptado) - Módulo de Reportes
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este módulo gestiona los reportes, estadísticas e indicadores del sistema
    de donantes de sangre, proporcionando funcionalidades para analizar
    la información de los donantes.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#include "ReportsModule.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;

void ReportsModule::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    // system("clear");
#endif
}

void ReportsModule::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

std::vector<Donor> ReportsModule::loadDonorsFromFile() const {
    std::vector<Donor> donors;
    std::ifstream inFile(fileName);
    
    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return donors;
    }
    
    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            donors.push_back(Donor::parseLine(line));
        }
    }
    
    inFile.close();
    return donors;
}

void ReportsModule::showReportsMenu() {
    while (true) {
        clearConsole();
        std::cout << "\n=== MÓDULO DE REPORTES, ESTADÍSTICAS E INDICADORES ===\n\n";
        std::cout << "1. Generar todos los reportes\n";
        std::cout << "2. Total de personas en el sistema\n";
        std::cout << "3. Conteos específicos por departamento y tipo de sangre\n";
        std::cout << "4. Edad promedio por departamentos específicos\n";
        std::cout << "5. Volver al menú principal\n";
        std::cout << "Ingrese su elección: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                generateAllReports();
                break;
            case 2:
                std::cout << "\nTotal de personas en el sistema: " << getTotalPersons() << std::endl;
                waitForKeyPress();
                break;
            case 3:
                getSpecificCounts();
                break;
            case 4:
                getAverageAges();
                break;
            case 5:
                return;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo.\n";
                waitForKeyPress();
                break;
        }
    }
}

void ReportsModule::generateAllReports() const {
    clearConsole();
    std::cout << "\n=== REPORTE COMPLETO DEL SISTEMA ===\n\n";
    
    // 1. Total de personas
    std::cout << "1. TOTAL DE PERSONAS EN EL SISTEMA: " << getTotalPersons() << "\n\n";
    
    // 2. Conteos específicos
    std::cout << "2. CONTEOS ESPECÍFICOS POR DEPARTAMENTO Y TIPO DE SANGRE:\n";
    getSpecificCounts();
    
    // 3. Edades promedio
    std::cout << "\n3. EDAD PROMEDIO POR DEPARTAMENTOS:\n";
    getAverageAges();
    
    std::cout << "\n=== FIN DEL REPORTE ===\n";
    waitForKeyPress();
}

int ReportsModule::getTotalPersons() const {
    std::vector<Donor> donors = loadDonorsFromFile();
    return donors.size();
}

void ReportsModule::getSpecificCounts() const {
    std::vector<Donor> donors = loadDonorsFromFile();
    
    int chocoAPlus = 0;
    int araucaOMinus = 0;
    int caucaAPlus = 0;
    
    for (const auto& donor : donors) {
        if (donor.getDistrict() == "Chocó" && donor.getBloodType() == "A+") {
            chocoAPlus++;
        }
        if (donor.getDistrict() == "Arauca" && donor.getBloodType() == "O-") {
            araucaOMinus++;
        }
        if (donor.getDistrict() == "Cauca" && donor.getBloodType() == "A+") {
            caucaAPlus++;
        }
    }
    
    std::cout << "   - Chocoanos con tipo de sangre A+: " << chocoAPlus << std::endl;
    std::cout << "   - Araucanos con tipo de sangre O-: " << araucaOMinus << std::endl;
    std::cout << "   - Caucanos con tipo de sangre A+: " << caucaAPlus << std::endl;
    
    if (!std::cin.rdbuf()->in_avail()) {
        waitForKeyPress();
    }
}

void ReportsModule::getAverageAges() const {
    std::vector<Donor> donors = loadDonorsFromFile();
    
    int chocoCount = 0, araucaCount = 0, valleCount = 0;
    int chocoAgeSum = 0, araucaAgeSum = 0, valleAgeSum = 0;
    
    for (const auto& donor : donors) {
        if (donor.getDistrict() == "Chocó") {
            chocoCount++;
            chocoAgeSum += donor.getAge();
        }
        if (donor.getDistrict() == "Arauca") {
            araucaCount++;
            araucaAgeSum += donor.getAge();
        }
        if (donor.getDistrict() == "Valle del Cauca") {
            valleCount++;
            valleAgeSum += donor.getAge();
        }
    }
    
    std::cout << "   - Edad promedio en Chocó: ";
    if (chocoCount > 0) {
        std::cout << std::fixed << std::setprecision(1) 
                  << (double)chocoAgeSum / chocoCount << " años (" << chocoCount << " personas)" << std::endl;
    } else {
        std::cout << "No hay datos disponibles" << std::endl;
    }
    
    std::cout << "   - Edad promedio en Arauca: ";
    if (araucaCount > 0) {
        std::cout << std::fixed << std::setprecision(1) 
                  << (double)araucaAgeSum / araucaCount << " años (" << araucaCount << " personas)" << std::endl;
    } else {
        std::cout << "No hay datos disponibles" << std::endl;
    }
    
    std::cout << "   - Edad promedio en Valle del Cauca: ";
    if (valleCount > 0) {
        std::cout << std::fixed << std::setprecision(1) 
                  << (double)valleAgeSum / valleCount << " años (" << valleCount << " personas)" << std::endl;
    } else {
        std::cout << "No hay datos disponibles" << std::endl;
    }
    
    if (!std::cin.rdbuf()->in_avail()) {
        waitForKeyPress();
    }
}

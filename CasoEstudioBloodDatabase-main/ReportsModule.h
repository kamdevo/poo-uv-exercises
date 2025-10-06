/*
    Clase: ReportsModule
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:
    
    Clase: ReportsModule

    Responsabilidades:
        - Generar reportes, estadísticas e indicadores del sistema de donantes
        - Calcular totales de personas en el sistema
        - Realizar conteos específicos por departamento y tipo de sangre
        - Calcular edades promedio por departamentos específicos
        - Proporcionar una interfaz de usuario para el módulo de reportes

    Colaboradores:
        - Colabora con la clase `Donor` para acceder a la información de los donantes
        - Lee datos del archivo de la base de datos

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class ReportsModule {
private:
    const std::string fileName = "data.txt";
    
    // Métodos auxiliares privados
    std::vector<Donor> loadDonorsFromFile() const;
    
public:
    // Métodos públicos para mostrar menús y generar reportes
    void showReportsMenu();
    void generateAllReports() const;
    
    // Reportes específicos
    int getTotalPersons() const;
    void getSpecificCounts() const;
    void getAverageAges() const;
    
    // Métodos de utilidad
    static void clearConsole();
    static void waitForKeyPress();
};

#endif // REPORTSMODULE_H

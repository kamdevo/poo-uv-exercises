
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
#include "Donor.h"
#include <sstream>
#include <iostream>
#include <algorithm>

void Donor::donorDetails(const Donor& donor) const {
    std::cout << "Nombre del donante: " << donor.name << std::endl;
    std::cout << "Distrito del donante: " << donor.district << std::endl;
    std::cout << "Tipo de sangre del donante: " << donor.bloodType << std::endl;
    std::cout << "Número de contacto del donante: " << donor.number << std::endl;
    std::cout << "Dirección del donante: " << donor.address << std::endl;
    std::cout << "ID del donante: " << donorId << std::endl
                << "-----------------------------------" << std::endl;
}

Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    getline(ss, token, ','); d.donorId = std::stoi(trim(token));
    getline(ss, token, ','); d.name = trim(token);
    getline(ss, token, ','); d.address = trim(token);
    getline(ss, token, ','); d.district = trim(token);  // También cambiar district a string
    getline(ss, token, ','); d.bloodType = trim(token);
    getline(ss, token, ','); d.number = trim(token);    // Cambiar a string (sin stoi)

    return d;
}

std::string Donor::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// declaración setters
void Donor::setAddress(const std::string& newAddress) {
    this->address = newAddress;
}

void Donor::setBloodType(const std::string& type) {
    this->bloodType = type;
}

void Donor::setDistrict(const std::string& dist) {
    this->district = dist;
}

void Donor::setDonorId(const int id) {
    this->donorId = id;
}

void Donor::setNumber(const std::string& phone) {
    this->number = phone;
}

void Donor::setName(const std::string& newName) {
    this-> name = newName;
}


//declaración getters
int Donor::getDonorId() const{
    return donorId;
}

std::string Donor::getName() const {
    return name;
}
std::string Donor::getAddress() const {
    return address;
}
std::string Donor::getBloodType() const {
    return bloodType;
}
std::string Donor::getNumber() const {
    return number;
}
std::string Donor::getDistrict() const {
    return district;
}
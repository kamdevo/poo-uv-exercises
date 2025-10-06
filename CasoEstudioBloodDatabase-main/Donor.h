#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {

private:
    int donorId;
    int age;
    std::string name, address, bloodType, number, district;

 

    
   
    
public:
    Donor() = default;

    // Getters
    int getDonorId() const;
    int getAge() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getBloodType() const;
    std::string getNumber() const;
    std::string getDistrict() const;

    void setDonorId(int id);
    void setAge(int newAge);
    void setName(const std::string& newName);
    void setAddress(const std::string& newAddress);
    void setBloodType(const std::string& type);
    void setNumber(const std::string& phone);
    void setDistrict(const std::string& dist);

    // Mostrar datos
    void donorDetails(const Donor& donor) const;

    // Parsear línea CSV
    static Donor parseLine(const std::string& line);
    static std::string trim(const std::string& str);

};

#endif // DONOR_H
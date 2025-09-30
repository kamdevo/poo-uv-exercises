#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class InputHandler {
public:
    static int getValidatedInput(const std::string& prompt);
    static std::string validateBloodType();
    static std::string validateProvince();
    static std::string mapProvince(int choice);
}


#endif

;
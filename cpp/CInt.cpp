//
// Created by mclar16 on 2024-05-14.
//

#include "CInt.h"
#include <fstream>
#include <utility>

CInt::CInt() {
    this->name = "name";
    this->lineToReference = 0;
    this->value = 0;
}

CInt::CInt(std::string name, int lineToReference, int value, std::ifstream inFile) {
    this->name = std::move(name);
    this->lineToReference = lineToReference;
    this->value = value;
    this->inFile;
}

CInt::~CInt() {
    std::cout << "CInt destroyed." << std::endl;
}

void CInt::update() {

}




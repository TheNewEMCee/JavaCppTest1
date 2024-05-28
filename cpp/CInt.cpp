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

CInt::CInt(std::string name, std::string path, int lineToReference, int value) {
    this->name = std::move(name);
    this->path = std::move(path);
    this->lineToReference = lineToReference;
    this->value = value;
}

CInt::~CInt() {
    std::cout << "CInt destroyed." << std::endl;
}


void CInt::updateValue() {
    std::ifstream theFile;
    theFile.open(path);
    if (theFile.fail()) {
        std::cerr << "Thingy Failed" << std::endl; 
    }
}

void CInt::setName(std::string n) {
    this->name = n;
}

void CInt::setPath(std::string p) {
    this->path = p;
}

void CInt::setLineToReference(int l) {
    this->lineToReference = l;
}

void CInt::setValue(int n) {
    this->value = n;
}

std::string CInt::getName() {
    return this->name;
}

std::string CInt::getPath() {
    return this->path;
}

int CInt::getLineToReference() {
    return this->lineToReference;
}

int CInt::getValue() {
    return this->value;
}


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

CInt::CInt(std::string name, std::string path, int lineToReference, int value, std::ifstream inFile) {
    this->name = std::move(name);
    this->path = std::move(path);
    this->lineToReference = lineToReference;
    this->value = value;
    this->inFile;
}

CInt::~CInt() {
    std::cout << "CInt destroyed." << std::endl;
}

void CInt::updateAll() {
    int currentLine = 0;
    std::string line;
    this->inFile.open(this->path);
    while(!inFile.eof()) {
        currentLine++;
        getline(inFile, line);
        if (currentLine == this->lineToReference) {
            this->value = std::stoi(line);
            break;
        }
    }
    this->inFile.close();
}

void CInt::updateValue() {

}

void CInt::setName(std::string n) {

}

void CInt::setPath(std::string p) {

}

void CInt::setLineToReference(int l) {

}

void CInt::setValue(int n) {

}

void CInt::setInFile(std::ifstream infile) {

}



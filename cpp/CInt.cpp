//
// Created by mclar16 on 2024-05-14.
//

#include "CInt.h"
#include <fstream>
#include <string>
#include <utility>
#include <vector>

CInt::CInt() {
    this->name = "name";
    this->lineToReference = 0;
    this->value = 0;
}

CInt::CInt(std::string name, std::string path, int lineToReference, int value, bool getTextValue) {
    this->name = std::move(name);
    this->path = std::move(path);
    this->lineToReference = lineToReference;
    if (!getTextValue) {
        this->value = value;
    }
    std::ifstream inFile;
    inFile.open(path);
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed" << std::endl; 
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
    }
    
    std::ofstream outFile;
    outFile.open(this->getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
    inFile.close();
    }
    lineArray[lineToReference] = value;
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray[i];
    }
    if (getTextValue) {
        this->setValue(stoi(lineArray[lineToReference]));
    }
    inFile.close();
    outFile.close();

}
CInt::~CInt() {
    std::cout << "CInt destroyed." << std::endl;
}

void CInt::updateValue() {
    std::ifstream inFile;
    inFile.open(this->getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed" << std::endl; 
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
    }
    this->setValue(std::stoi(lineArray[this->getLineToReference()]));
    std::ofstream outFile;
    outFile.open(this->getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
    inFile.close();
    }
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray[i];
    }
    inFile.close();
    outFile.close();
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


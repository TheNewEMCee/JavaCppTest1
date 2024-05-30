//
// Created by mclar16 on 2024-05-14.
//

#include "CString.h"
#include "CVar.h"
#include <fstream>
#include <string>
#include <utility>
#include <vector>

CString::CString() {
    this->name = "name";
    this->lineToReference = 0;
    this->value = "";
}

CString::CString(std::string name, std::string path, int lineToReference, int value, bool getTextValue) {
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
        this->value = lineArray[lineToReference];
    }
    inFile.close();
    outFile.close();

}
CString::~CString() {
    std::cout << "CString destroyed." << std::endl;
}

void CString::updateValue() {
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
    this->setValue(lineArray[this->getLineToReference()]);
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

void CString::setName(std::string n) {
    this->name = n;
}

void CString::setPath(std::string p) {
    this->path = p;
}

void CString::setLineToReference(int l) {
    this->lineToReference = l;
}

void CString::setValue(std::string v) {
    this->value = v;
}

std::string CString::getName() {
    return this->name;
}

std::string CString::getPath() {
    return this->path;
}

int CString::getLineToReference() {
    return this->lineToReference;
}

std::string CString::getValue() {
    return this->value;
}
//
// Created by TheNewEMCee on 2024-05-14.
//

#include "CInt.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <filesystem>
#include <vector>

CInt::CInt() {
    this->name = "unnamed CInt";
    this->lineToReference = 0;
    this->value = 0;
}

CInt::CInt(std::string name, std::string path, int lineToReference, int value) {
    this->setName(std::move(name));
    this->setPath(std::move(path));
    this->setLineToReference(lineToReference);
    this->setValue(value);
    std::ifstream inFileTemp;
    int currentLine = 0;
    std::string line;
    inFileTemp.open(this->path);
    if (inFileTemp.fail()) {
        std::cerr << this->name << "'s inFileTemp has an invalid path, or has otherwise failed. please check your code to make sure it is a valid path." << std::endl;
    } else {
        while(!inFileTemp.eof()) {
            currentLine++;
            getline(inFileTemp, line);
            if (currentLine == this->lineToReference) {
                this->value = std::stoi(line);
                break;
            }
        }
        inFileTemp.close();
    }
}

CInt::~CInt() {
    std::cout << "CInt" << name << " destroyed." << std::endl;
}

void CInt::updateValue() {
    std::ifstream inFileTemp;
    int currentLine = 0;
    std::string line;
    inFileTemp.open(this->path);
    while(!inFileTemp.eof()) {
        currentLine++;
        getline(inFileTemp, line);
        if (currentLine == this->lineToReference) {
            this->setValue(std::stoi(line));
            inFileTemp.close();
            break;
        }
    }
    inFileTemp.close();
}

void CInt::setName(std::string n) {
    this->name = std::move(n);
}

void CInt::setPath(std::string p) {
    this->path = std::move(p);
}

void CInt::setLineToReference(int l) {
    this->lineToReference = l;
}

void CInt::setValue(int n) {
    this->value = n;
    int currentLine = 0;
    std::string line;
    std::vector<std::string> textFileArray {};
    std::ifstream inFileTemp;
    inFileTemp.open(this->getPath());
    while(!inFileTemp.eof()) {
        currentLine++;
        getline(inFileTemp, line);
        textFileArray.push_back(line);
    }
    textFileArray[this->getLineToReference()] = std::to_string(n);
    inFileTemp.close();
    //now open the file to write to it
    std::ofstream outFileTemp;
    outFileTemp.open(this->getPath());
    for (int i = 0; i < textFileArray.size(); i++) {
        outFileTemp << textFileArray[i];
    }
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
    this->updateValue();
    return this->value;
}



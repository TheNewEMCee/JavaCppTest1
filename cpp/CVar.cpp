//
// Created by mclar16 on 2024-05-14.
//

#include "CVar.h"
#include <fstream>
#include <string>
#include <utility>
#include <vector>

CVar::CVar() {
    this->name = "name";
    this->lineToReference = 0;
}

CVar::CVar(std::string name, std::string path, int lineToReference) {
    this->name = std::move(name);
    this->path = std::move(path);
    this->lineToReference = lineToReference;
}
CVar::~CVar() {
    std::cout << "CVar destroyed." << std::endl;
}

void CVar::setName(std::string n) {
    this->name = n;
}

void CVar::setPath(std::string p) {
    this->path = p;
}

void CVar::setLineToReference(int l) {
    this->lineToReference = l;
}

std::string CVar::getName() {
    return this->name;
}

std::string CVar::getPath() {
    return this->path;
}

int CVar::getLineToReference() {
    return this->lineToReference;
}
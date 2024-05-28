#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "CInt.h"
#include "CInt.cpp"
void enterDetector() {
    std::string enterDetector;
    do {
        getline(std::cin, enterDetector);
    } while (!enterDetector.empty());
}

int getInt() {
    int realIn;
    bool inputCompletionFlag = false;
    do {
        std::cin >> realIn;
        if (std::cin.fail()) {
            std::cin.clear();
        } else {
            inputCompletionFlag = true;
        }
    } while (!inputCompletionFlag);
    return realIn;
}

int main() {
    //Confirm functioning build
    std::cout << "main.cpp runtime initialized" << std::endl;
    //Try to see if CInt works... Hopefully!
    CInt CInt1("CInt1", "../text/CInts.txt", 2, 6);
    std::cout << "Hello!" << std::endl;
    std::cout << "Name: " << CInt1.getName() << std::endl;
    std::cout << "Stored at " << CInt1.getPath() << ", line " << CInt1.getLineToReference() << std::endl;
    std::cout << "Value is set to " << CInt1.getValue() << std::endl;
    //CInt1.updateValue();
    return 0;
}

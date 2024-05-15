#include <iostream>
#include <fstream>
#ifndef JAVACPPTEST1_CINT_H
#define JAVACPPTEST1_CINT_H


class CInt {
private:
    std::string name;
    int lineToReference;
    int value;
    std::ifstream inFile;
public:
    CInt();
    CInt(std::string name, int lineToReference, int value, std::ifstream inFile);
    ~CInt();
    void update();
};


#endif //JAVACPPTEST1_CINT_H

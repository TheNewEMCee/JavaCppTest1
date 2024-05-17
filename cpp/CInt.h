#include <iostream>
#include <fstream>
#ifndef JAVACPPTEST1_CINT_H
#define JAVACPPTEST1_CINT_H


class CInt {
private:
    std::string name;
    std::string path;
    int lineToReference;
    int value;
    std::ifstream inFile;
public:
    CInt();
    CInt(std::string name, std::string path, int lineToReference, int value, std::ifstream inFile);
    ~CInt();
    void updateAll();
    void updateValue();
    void setName(std::string n);
    void setPath(std::string p);
    void setLineToReference(int l);
    void setValue(int n);
    void setInFile(std::ifstream infile);
};


#endif //JAVACPPTEST1_CINT_H

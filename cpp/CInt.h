#include <iostream>
#include <fstream>
#include "CVar.h"
#ifndef JAVACPPTEST1_CINT_H
#define JAVACPPTEST1_CINT_H


class CInt : public CVar{
private:
    int value;
public:
    CInt();
    CInt(std::string name, std::string path, int lineToReference, int value, bool getTextValue = true);
    ~CInt();
    void updateValue();
    void setName(std::string n);
    void setPath(std::string p);
    void setLineToReference(int l);
    void setValue(int n);
    std::string getName();
    std::string getPath();
    int getLineToReference();
    int getValue();
};


#endif //JAVACPPTEST1_CINT_H

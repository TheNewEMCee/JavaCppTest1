#include <iostream>
#include <fstream>
#include "CVar.h"
#ifndef JAVACPPTEST1_CString_H
#define JAVACPPTEST1_CString_H


class CString : public CVar {
private:
    std::string value;
public:
    CString();
    CString(std::string name, std::string path, int lineToReference, int value, bool getTextValue = true);
    ~CString();
    void updateValue();
    void setName(std::string n);
    void setPath(std::string p);
    void setLineToReference(int l);
    void setValue(std::string n);
    std::string getName();
    std::string getPath();
    int getLineToReference();
    std::string getValue();
};


#endif //JAVACPPTEST1_CString_H
#include <iostream>
#include <fstream>
#ifndef JAVACPPTEST1_CINT_H
#define JAVACPPTEST1_CINT_H


class CInt {
private:
    std::string name;
    std::string path;
    int lineToReference{};
    int value;
public:
    CInt();
    CInt(std::string name, std::string path, int lineToReference, int value);
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

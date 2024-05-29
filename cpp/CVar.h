#include <iostream>
#include <fstream>
#ifndef JAVACPPTEST1_CVAR_H
#define JAVACPPTEST1_CVAR_H


class CVar {
private:
    std::string name;
    std::string path;
    int lineToReference;
public:
    CVar();
    CVar(std::string name, std::string path, int lineToReference);
    ~CVar();
    void updateValue();
    void setName(std::string n);
    void setPath(std::string p);
    void setLineToReference(int l);
    std::string getName();
    std::string getPath();
    int getLineToReference();
};


#endif //JAVACPPTEST1_CVAR_H

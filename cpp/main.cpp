#include <iostream>
#include <fstream>
#include <sstream>

void enterDetector() {
  std::string enterDetector = "";
  do {
    getline(std::cin, enterDetector);
  } while (enterDetector.length() != 0);
}

int getInt() {
 int realIn;
    bool inputCompletionFlag = true;
    do {
    std::cin >> realIn;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else {
            inputCompletionFlag = false;
        }
    } while (!inputCompletionFlag);
    return realIn;
}

int main() {
    //Confirm functioning build
    std::cout << "main.cpp runtime initialized" << std::endl;
    //Init files
    std::fstream ioFile;
    std::ifstream inFile;
    std::ofstream outFile;
    ioFile.open("../text/ioFile.txt", std::ios::in | std::ios::out);
    inFile.open("../text/inFile.txt");
    outFile.open("../text/outFile.txt");
    //Init vars
    std::string thingToWrite0 = "Apples!";
    std::string thingToRead0;
    std::string passIn;
    std::string password;
    bool goOn = false;

    std::string filename;
    int lineNumber;
    int fruitNumber;
    int currentLine = 0;
    std::string line;

    //Failsafe for .txt files
    if (ioFile.fail()) {
        std::cerr << "ioFile Failed" << std::endl;
        exit(1);
    }
    if (inFile.fail()) {
        std::cerr << "inFile Failed" << std::endl;
        exit(1);
    }
    if (outFile.fail()) {
        std::cerr << "outFile Failed" << std::endl;
        exit(1);
    }
    //Write thingToWrite0 to outFile
    std::cout << "input:" << std::endl;
    std::cin >> thingToWrite0;
    ioFile << thingToWrite0;
    outFile << thingToWrite0;
    std::cout << "Now go look to see if it's there" << std::endl;
    std::cout << "Enter Password: " << std::endl;
    std::cin >> password;
    std::cout << "Now for the fruit showcase:" << std::endl;
    std::cout << "Which fruit would you like to see?" << std::endl;
    fruitNumber = getInt();
    while(!inFile.eof()) {
        currentLine++;
        getline(inFile, line);
        if (currentLine == fruitNumber) {
            std::cout << line << std::endl;
            break;
        }
    }
    while (!goOn) {
        std::cin >> passIn;
        if (passIn == password) {
            goOn = true;
        }
    }
    //Close files
    ioFile.close();
    inFile.close();
    outFile.close();
    return 0;
}

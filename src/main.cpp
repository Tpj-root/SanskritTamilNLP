#include <iostream>
#include <fstream>
#include <sstream>
#include "engine/Translator.h"

/*
    Program flow:
    1. Read full content from Source.txt
    2. Translate using Translator
    3. Write translated output to Decode.txt
    4. Preserve spaces, tabs, and newlines exactly
*/

int main() {

    Translator translator;

    // ---------- OPEN INPUT FILE ----------
    std::ifstream inputFile("Source.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open Source.txt" << std::endl;
        return 1;
    }

    // ---------- READ FULL FILE (INCLUDING NEWLINES) ----------
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string inputText = buffer.str();
    inputFile.close();

    // ---------- TRANSLATE ----------
    std::string outputText = translator.translate(inputText);

    // ---------- WRITE OUTPUT FILE ----------
    std::ofstream outputFile("Decode.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create Decode.txt" << std::endl;
        return 1;
    }

    outputFile << outputText;
    outputFile.close();

    std::cout << "Translation completed successfully." << std::endl;
    std::cout << "Input  : Source.txt" << std::endl;
    std::cout << "Output : Decode.txt" << std::endl;

    return 0;
}

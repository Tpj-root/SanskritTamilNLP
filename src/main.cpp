#include <iostream>
#include "engine/Translator.h"

int main() {
    Translator translator;

    std::string input;
    std::cout << "Enter Sanskrit (IAST, simple): ";
    std::getline(std::cin, input);

    std::cout << "Tamil Output: "
              << translator.translate(input)
              << std::endl;

    return 0;
}

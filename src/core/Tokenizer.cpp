#include "Tokenizer.h"
#include <sstream>

std::vector<Token> Tokenizer::tokenize(const std::string& input) {
    std::stringstream ss(input);
    std::string word;
    std::vector<Token> tokens;

    while (ss >> word) {
        tokens.emplace_back(word);
    }
    return tokens;
}

#pragma once
#include <string>

/*
 Token represents the smallest meaningful unit
 Example:
   Sanskrit word → phonemes → Tamil output
*/
class Token {
public:
    std::string original;   // Input word
    std::string mapped;     // Tamil mapped word
    std::string pos;        // Part of speech (noun, verb, etc.)

    Token(const std::string& text)
        : original(text), mapped(""), pos("unknown") {}
};

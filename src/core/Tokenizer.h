#pragma once
#include <vector>
#include <string>
#include "Token.h"

/*
 Tokenizer:
 Splits input sentence into word-level tokens.
 Later upgrades:
  - Sandhi splitting
  - Morphological analysis
*/
class Tokenizer {
public:
    std::vector<Token> tokenize(const std::string& input);
};

#pragma once
#include "../core/Tokenizer.h"
#include "../phoneme/PhonemeMapper.h"
#include "../grammar/SimpleSOVRule.h"

/*
 Translator:
 Central pipeline controller.
*/
class Translator {
private:
    Tokenizer tokenizer;
    PhonemeMapper mapper;
    SimpleSOVRule grammarRule;

public:
    std::string translate(const std::string& input);
};

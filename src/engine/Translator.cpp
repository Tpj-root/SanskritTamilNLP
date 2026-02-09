#include "Translator.h"

/*
 Translation pipeline:
 1. Tokenize
 2. Apply grammar
 3. Map phonemes
 4. Generate output
*/
std::string Translator::translate(const std::string& input) {
    auto tokens = tokenizer.tokenize(input);

    grammarRule.apply(tokens);

    std::string output;
    for (auto& token : tokens) {
        token.mapped = mapper.mapWord(token.original);
        output += token.mapped + " ";
    }
    return output;
}

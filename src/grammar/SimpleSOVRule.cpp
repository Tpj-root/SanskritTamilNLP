#include "SimpleSOVRule.h"

/*
 Extremely basic POS assignment:
 Last word → verb
 Others → noun

 Later replaced by real morphology.
*/
void SimpleSOVRule::apply(std::vector<Token>& tokens) {
    if (tokens.empty()) return;

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (i == tokens.size() - 1)
            tokens[i].pos = "verb";
        else
            tokens[i].pos = "noun";
    }
}

#pragma once
#include "../core/GrammarRule.h"

/*
 Sanskrit: Subject Object Verb
 Tamil:    Subject Object Verb

 This rule just tags noun/verb positions.
 Later:
  - Morphology
  - Agreement
*/
class SimpleSOVRule : public GrammarRule {
public:
    void apply(std::vector<Token>& tokens) override;
};

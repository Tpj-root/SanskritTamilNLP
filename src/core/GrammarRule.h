#pragma once
#include <vector>
#include "Token.h"

/*
 GrammarRule (Abstract Base Class)

 All grammar logic must inherit this.
 This allows:
  - Rule chaining
  - Plug-and-play grammar modules
*/
class GrammarRule {
public:
    virtual void apply(std::vector<Token>& tokens) = 0;
    virtual ~GrammarRule() = default;
};

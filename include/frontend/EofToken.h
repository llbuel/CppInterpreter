#pragma once

#include "frontend/Source.h"
#include "frontend/Token.h"

namespace frontend {

class EofToken : public Token {
protected:
    void extract(Source source) {}

public:
    EofToken(Source source) : Token(source) {}
};

} // namespace frontend
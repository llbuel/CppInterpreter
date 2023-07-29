#pragma once

#include "frontend/Source.h"
#include "frontend/Token.h"

class EofToken : public Token {
protected:
    void extract(Source source) {}

public:
    EofToken(Source source) : Token(source) {}
};
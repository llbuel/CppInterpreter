#pragma once

#include "Source.h"
#include "Token.h"

class EofToken : public Token {
protected:
    void extract(Source source) {}

public:
    EofToken(Source source) : Token(source) {}
};
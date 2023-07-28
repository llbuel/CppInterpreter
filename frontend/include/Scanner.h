#pragma once

#include "Token.h"

class Scanner {
protected:
    Token extractToken();

public:
    Scanner();
    
    Token getCurrentToken() const;
    Token getNextToken() const;
    char getCurrentChar() const;
    char getNextChar() const;

};
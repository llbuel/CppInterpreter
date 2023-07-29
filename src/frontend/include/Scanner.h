#pragma once

#include <fstream>

#include "Source.h"
#include "Token.h"

class Scanner {
protected:
    Source m_source;

    virtual Token extractToken() = 0;

private:
    Token m_currentToken;

public:
    Scanner(Source source);
    
    Token getCurrentToken() const;
    Token getNextToken();
    char getCurrentChar();
    char getNextChar();
};
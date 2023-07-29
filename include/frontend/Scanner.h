#pragma once

#include <fstream>

#include "frontend/Source.h"
#include "frontend/Token.h"

namespace frontend {

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

} // namespace frontend
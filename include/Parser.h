#pragma once

#include "ICode.h"
#include "SymTab.h"
#include "Token.h"

class Parser {
protected:
    ICode m_ICode;
    SymTab m_symTab;

public:
    Parser();
    
    void parse();
    int getErrorCount() const;
    Token getCurrentToken() const;
    Token getNextToken() const;
};
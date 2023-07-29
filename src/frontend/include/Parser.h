#pragma once

#include "SymTab.h"
#include "ICode.h"
#include "Scanner.h"
#include "Token.h"

#include <memory>
#include <exception>

class Parser {
protected:
    static SymTab m_symTab;
    std::unique_ptr<ICode> m_ICode;
    Scanner m_scanner;

public:
    Parser(Scanner scanner);
    
    virtual void parse();
    virtual int getErrorCount() const = 0;

    Token getCurrentToken() const;
    Token getNextToken() const;
    std::unique_ptr<ICode> createICode();
};
#pragma once

#include <memory>
#include <exception>

#include "intermediate/SymTab.h"
#include "intermediate/ICode.h"
#include "frontend/Scanner.h"
#include "frontend/Token.h"

namespace frontend {

class Parser {
protected:
    static intermediate::SymTab m_symTab;
    std::unique_ptr<intermediate::ICode> m_ICode;
    Scanner& m_scanner;

public:
    Parser(Scanner& scanner);
    
    virtual void parse();
    virtual int getErrorCount() const;

    Token getCurrentToken() const;
    Token getNextToken() const;
    std::unique_ptr<intermediate::ICode> createICode();
};

} // namespace frontend
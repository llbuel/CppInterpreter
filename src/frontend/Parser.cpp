#include "frontend/Parser.h"

#include <iostream>

namespace frontend {

intermediate::SymTab Parser::m_symTab{ nullptr };

Parser::Parser(Scanner& scanner) : m_scanner(scanner), m_ICode(createICode()) {}

void Parser::parse() {
    throw std::logic_error("Base Parse class does not support parsing. Implement language-specific class for parsing.");
}

int Parser::getErrorCount() const {
    throw std::logic_error("Base Parse class does not support error checking. Implement language-specific class for error checking.");
}

std::unique_ptr<intermediate::ICode> Parser::createICode() {
    try {
        return std::make_unique<intermediate::ICode>();
    } catch (const std::exception& e) {
        std::cout << "ICode instance failed: " << e.what() << "\n";
        return nullptr;
    }
}

Token Parser::getCurrentToken() const {
    return this->m_scanner.getCurrentToken();
}

Token Parser::getNextToken() const {
    try {
        return this->m_scanner.getNextToken();
    } catch (const std::exception& e) {
        std::cout << "Scanner failed to extract next token: " << e.what() << "\n";
        return Token(nullptr);
    }
}

} // namespace frontend
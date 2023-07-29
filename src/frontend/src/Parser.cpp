#include "Parser.h"

#include <iostream>

SymTab Parser::m_symTab{ nullptr };

Parser::Parser(Scanner scanner) : m_scanner(scanner), m_ICode(createICode()) {}

std::unique_ptr<ICode> Parser::createICode() {
    try {
        return std::make_unique<ICode>();
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
    }
}
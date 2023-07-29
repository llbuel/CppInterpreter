#include <iostream>
#include <exception>

#include "Scanner.h"

Scanner::Scanner(Source source) : m_source(source) {}

Token Scanner::getCurrentToken() const {
    return m_currentToken;
}

Token Scanner::getNextToken() {
    try {
        m_currentToken = extractToken();
        
        return m_currentToken;
    }
    catch (std::exception& e) {
        std::cout << "Could not scan the next token: " << e.what() << "\n";
    }
}

char Scanner::getCurrentChar() {
    try {
        return m_source.getCurrentChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not scan the current character: " << e.what() << "\n";
    }
}

char Scanner::getNextChar() {
    try {
        return m_source.getNextChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not scan the next character: " << e.what() << "\n";
    }
}
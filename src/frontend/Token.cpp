#include <iostream>
#include <exception>

#include "frontend/Token.h"

Token::Token(Source source) : m_source(source), m_lineNumber(source.getLineNumber()), m_position(source.getPosition()) {
    extract();
}

void Token::extract() {
    try {
        m_text = std::string(1, getCurrentChar());
        m_value = nullptr;

        getNextChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not extract the token: " << e.what() << "\n";
    }
}

char Token::getCurrentChar() {
    try {
        return m_source.getCurrentChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not tokenize current character: " << e.what() << "\n";
        return Source::m_EOF;
    }
}

char Token::getNextChar() {
    try {
        return m_source.getNextChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not tokenize next character: " << e.what() << "\n";
        return Source::m_EOF;
    }
}

char Token::peekChar() {
    try {
        return m_source.peekChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not peek the next token character: " << e.what() << "\n";
        return Source::m_EOF;
    }
}
#pragma once

class Token;

class TokenType {
public:
    virtual void processToken(Token token) = 0;
};
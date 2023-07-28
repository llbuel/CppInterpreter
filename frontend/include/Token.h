#pragma once

#include <string>

class TokenType;

class Token {
protected:
	std::string m_text;
	int m_value;

	void extract();
	char getCurrentChar() const;
	char getNextChar() const;
	char peekChar() const;

private:
	int m_lineNumber;
	int m_position;

public:
	Token();

	TokenType* getType() const;
};
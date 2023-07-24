#pragma once

#include <string>

#include "Token.h"

class Interpreter {
private:
	std::string m_text;
	int m_pos;
	Token m_currentToken;

public:
	Interpreter(std::string input);

	Token getNextToken();
	void eat();
	std::string expr();
};
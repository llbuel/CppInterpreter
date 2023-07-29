#pragma once

#include <string>
#include <memory>

#include "frontend/Source.h"
#include "frontend/TokenValue.h"

namespace frontend {

class TokenType;

class Token {
protected:
	TokenType* m_type;
	std::string m_text;
	TokenValue* m_value;
	Source m_source;
	int m_lineNumber;
	int m_position;

	void extract();
	char getCurrentChar();
	char getNextChar();
	char peekChar();

public:
	Token(Source source);
};

} // namespace frontend
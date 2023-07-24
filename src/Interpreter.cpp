#include <iostream>
#include <string>

#include "Token.h"
#include "Interpreter.h"

Interpreter::Interpreter(std::string input) : m_text(input), m_pos(0) {}

Token Interpreter::getNextToken() {
	Token temp;

	return temp;
}

void Interpreter::eat() {

}

std::string Interpreter::expr() {
	return m_text;
}
#include <iostream>
#include <string>

#include "Interpreter.h"

int main() {
	bool runLoop = true;
	
	while (runLoop) {
		std::string text;
		
		std::cout << "=>> ";
		std::cin >> text;

		if (text == "\n") {
			continue;
		}
		else if (text == "quit") {
			runLoop = false;

			std::cout << "\nGoodbye!" << "\n";

			break;
		}

		Interpreter interpreter(text);
		std::string result = interpreter.expr();

		std::cout << "  " << text << " = " << result << "\n";
	}

	return 0;
}
#include <iostream>
#include <string>

bool checkForQuit() {
	bool quitBool{ false };

	while(!quitBool) {
		std::string quitInput;
		
		std::cout << "\nQuit program? [Y/N]: ";
		std::cin >> quitInput;

		if (quitInput == "Y" || quitInput == "y") {
			std::cout << "\nGoodbye!\n\n";
			quitBool = true;
			return true;
		}
		else if (quitInput == "N" || quitInput == "n") {
			std::cout << "\nReturning to program.\n'quit' is a reserved name in CLAB.\n\n";
			quitBool = false;
			return false;
		}
		else {
			quitBool = false;
		}
	}

	return false;
}

bool consoleInteraction() {
	std::string text;
	
	std::cout << "CLAB>> ";
	std::cin >> text;
	
	if (text == "quit") {
		bool quitBool = checkForQuit();

		if (quitBool) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		std::cout << "\n" << text << " = " << "\n\n    " << text << "\n\n";

		return true;
	}
}

int main() {
	bool runLoop{ true };
	
	while (runLoop) {
		runLoop = consoleInteraction();
	}

	return 0;
}
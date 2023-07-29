#include "App/App.h"

void App::run() {
	consoleInteraction();
}

bool App::checkForQuit() {
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
			std::cout << "\n";
			
			quitBool = false;

			return false;
		}
		else {
			quitBool = false;
		}
	}

	return false;
}

void App::consoleInteraction() {
	std::string text;

	std::cout << "CLAB>> ";
	std::cin >> text;
	
	if (text == "\\quit" || text == "\\q") {
		m_quitApp = checkForQuit();
	}
	else {
		std::cout << "\n" << text << " = " << "\n\n    " << text << "\n\n";
	}
}
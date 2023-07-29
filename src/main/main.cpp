#include "ConsoleFunctions/ConsoleFunctions.h"

int main() {
	bool runLoop{ true };
	
	while (runLoop) {
		runLoop = consoleInteraction();
	}

	return 0;
}
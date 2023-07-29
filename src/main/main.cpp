#include "App/App.h"

int main() {
	App application;
	
	while (!application.quit()) {
		application.run();
	}

	return 0;
}
#include "App.h"
#include "RootWindowFrame.h"

// Application entry point
wxIMPLEMENT_APP(App);

bool App::OnInit() {
	RootWindowFrame* mainFrame = new RootWindowFrame();
	mainFrame->Show();

	return true;
}


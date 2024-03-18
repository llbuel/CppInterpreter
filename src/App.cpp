#include "App.h"
#include "MainWindow.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainWindowFrame* mainFrame = new MainWindowFrame();
	wxInitAllImageHandlers();
	mainFrame->Show();

	return true;
}


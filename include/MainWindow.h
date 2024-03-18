#pragma once
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class MainWindowFrame : public wxFrame
{
public:
	MainWindowFrame();

private:
	bool m_bypassCloseCheck = false;
	bool m_workSaved = false;

	wxMenuBar* m_menuBar = new wxMenuBar();
	wxMenu* m_fileMenu = new wxMenu();
	wxMenu* m_editMenu = new wxMenu();
	wxToolBar* m_toolBar = CreateToolBar();
	
	void drawMainWindow();
	
	void buildMenuBar();
	void buildRibbonBar();
	void buildWorkspace();

	void OnNew(wxCommandEvent& evt);
	void OnOpen(wxCommandEvent& evt);
	void OnSave(wxCommandEvent& evt);
	void OnSaveAs(wxCommandEvent& evt);
	void OnImport(wxCommandEvent& evt);
	void OnExport(wxCommandEvent& evt);
	void OnUndo(wxCommandEvent& evt);
	void OnRedo(wxCommandEvent& evt);
	void OnRun(wxCommandEvent& evt);

	void OnExit(wxCommandEvent& evt);
	void OnWindowClose(wxCloseEvent& evt);
	void closeWindowCheck();
	void OnExitConfirm();
};
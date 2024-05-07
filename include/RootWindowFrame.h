#pragma once

#include <wx/wxprec.h>
#include <wx/splitter.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "Workspace.h"
#include "ThemeManager.h"

class RootWindowFrame : public wxFrame
{
public:
	RootWindowFrame();
	~RootWindowFrame();

private:
	bool m_bypassCloseCheck = false;
	bool m_workSaved = false;

	wxPanel* m_toolbarPanel = new wxPanel(this, wxID_ANY);
	wxPanel* m_workspacePanel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* m_toolbarSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* m_workspaceSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* m_baseSizer = new wxBoxSizer(wxVERTICAL);

	wxMenuBar* m_menuBar = new wxMenuBar();
	wxMenu* m_fileMenu = new wxMenu();
	wxMenu* m_editMenu = new wxMenu();
	wxMenu* m_optionsMenu = new wxMenu();

	ThemeManager* m_themeManager = new ThemeManager(this);
	wxDialog* m_themeDialog = new wxDialog(this, wxID_ANY, "Change Appearance", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP);

	wxToolBar* m_toolBar = new wxToolBar(m_toolbarPanel, wxID_ANY);

	Workspace* m_workspace = new Workspace(m_workspacePanel);
	CommandWindow* m_commandWindow = m_workspace->GetCommandWindow();
	
	void drawMainWindow();
	
	void buildMenuBar();
	void buildToolBar();
	void buildWorkspace();

	void OnNew(wxCommandEvent& evt);
	void OnOpen(wxCommandEvent& evt);
	void OnSave(wxCommandEvent& evt);
	void OnSaveAs(wxCommandEvent& evt);
	void OnImport(wxCommandEvent& evt);
	void OnExport(wxCommandEvent& evt);
	void OnUndo(wxCommandEvent& evt);
	void OnRedo(wxCommandEvent& evt);
	void OnThemeChange(wxCommandEvent& evt);

	void OnRun(wxCommandEvent& evt);
	void OnGlobalTextEntry(wxKeyEvent& evt);

	void OnExit(wxCommandEvent& evt);
	void OnWindowClose(wxCloseEvent& evt);
	void closeWindowCheck();
	void OnExitConfirm();
};
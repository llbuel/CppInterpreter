#pragma once
#include <wx/wxprec.h>
#include <vector>
#include <random>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class MainFrame : public wxFrame
{
public:
	MainFrame();

private:
	void buildMenuBar();
	void buildRibbonBar();

	void OnNew(wxCommandEvent& evt);
	void OnOpen(wxCommandEvent& evt);
	void OnSave(wxCommandEvent& evt);
	void OnSaveAs(wxCommandEvent& evt);
	void OnImport(wxCommandEvent& evt);
	void OnExport(wxCommandEvent& evt);
	void OnUndo(wxCommandEvent& evt);
	void OnRedo(wxCommandEvent& evt);
	void OnExit(wxCommandEvent& evt);
	void OnExitConfirm(wxCommandEvent& evt);
};
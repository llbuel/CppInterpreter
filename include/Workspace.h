#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/aui/aui.h>
#include <wx/splitter.h>

#include "CommandWindow.h"

class Workspace : public wxFrame {
public:
    Workspace(wxWindow* parent);

    void OnShow(wxShowEvent& evt);
    void DrawWorkspaceFrame();
    CommandWindow* GetCommandWindow() const { return m_commandWindow; }

private:
    wxWindow* m_parent;

    wxAuiManager* m_panelManager;

    wxPanel* m_directoryPanel;
    wxAuiNotebook* m_editorNotebook;
    wxPanel* m_editorPanel;
    CommandWindow* m_commandWindow;
    wxPanel* m_variablePanel;

    void OnPaneFloat(wxAuiManagerEvent& evt);
};
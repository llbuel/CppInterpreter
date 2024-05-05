#include "CommandWindow.h"
#include "Workspace.h"

const wxColour CLAB_DARK_COLOR = wxColor(0x25, 0x25, 0x25); 

Workspace::Workspace(wxWindow* parent) : m_parent(parent), 
                                         m_directoryPanel(new wxPanel(parent)),
                                         m_editorNotebook(new wxAuiNotebook(parent)), 
                                         m_editorPanel(new wxPanel(parent)), 
                                         m_commandWindow(new CommandWindow(parent)),
                                         m_variablePanel(new wxPanel(parent)) {
    m_panelManager = new wxAuiManager(parent);
    m_commandWindow->InitCommandWindow();
}

void Workspace::DrawWorkspaceFrame() {
    m_directoryPanel->SetBackgroundColour(CLAB_DARK_COLOR);
    m_editorPanel->SetBackgroundColour(CLAB_DARK_COLOR);
    m_variablePanel->SetBackgroundColour(CLAB_DARK_COLOR);

    int parentWidth = m_parent->GetClientSize().GetWidth();
    int parentHeight = m_parent->GetClientSize().GetHeight();

    m_editorNotebook->AddPage(m_editorPanel, "*Untitled", true);
    
    m_panelManager->AddPane(m_directoryPanel, wxAuiPaneInfo().Name("directory-pane").Caption("Directory Explorer").Left().Layer(2).BestSize(wxSize(parentWidth / 4, -1)).MinSize(wxSize(parentWidth / 4, 200)).CloseButton(true).Floatable(true));
    m_panelManager->AddPane(m_editorNotebook, wxAuiPaneInfo().Name("editor-pane").Caption("Text Editor").Center().Layer(1).Position(1).BestSize(wxSize(parentWidth * (1/2), parentHeight * (2/3))).MinSize(wxSize(parentWidth / 4, 200)).CloseButton(true).Floatable(true));
    m_panelManager->AddPane(m_commandWindow, wxAuiPaneInfo().Name("command-pane").Caption("Command Window").Bottom().Layer(1).Position(2).BestSize(wxSize(parentWidth * (1/2), parentHeight / 3)).MinSize(wxSize(parentWidth / 4, 200)).CloseButton(true).Floatable(true));
    m_panelManager->AddPane(m_variablePanel, wxAuiPaneInfo().Name("variable-pane").Caption("Variable Explorer").Right().Layer(2).BestSize(wxSize(parentWidth / 4, -1)).MinSize(wxSize(parentWidth / 4, 200)).CloseButton(true).Floatable(true));

    m_panelManager->Update();
}

void Workspace::OnPaneFloat(wxAuiManagerEvent& evt) {
    wxAuiPaneInfo* pane = evt.GetPane();
    pane->Float();
}
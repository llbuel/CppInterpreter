#include <wx/artprov.h>
#include <wx/splitter.h>

#include "RootWindowFrame.h"

enum ELEMENT_IDs {
    NEW_FILE_MENU_ID = 1,
    OPEN_FILE_MENU_ID,
    SAVE_FILE_MENU_ID,
    SAVE_AS_FILE_MENU_ID,
    IMPORT_FILE_MENU_ID,
    EXPORT_FILE_MENU_ID,
    EXIT_FILE_MENU_ID,
    UNDO_EDIT_MENU_ID,
    REDO_EDIT_MENU_ID,

    THEME_OPTION_MENU_ID,

    NEW_TOOL_ID,
    OPEN_TOOL_ID,
    SAVE_TOOL_ID,
    SAVE_AS_TOOL_ID,
    UNDO_TOOL_ID,
    REDO_TOOL_ID,
    RUN_TOOL_ID,

    COMMAND_ENTRY_ID,
};

RootWindowFrame::RootWindowFrame() : wxFrame(nullptr, wxID_ANY, "C++ Laboratory") {
    drawMainWindow();
    
    buildMenuBar();

    CreateStatusBar();
    SetStatusText("Ready!");
    
    buildToolBar();
    buildWorkspace();

    Bind(wxEVT_CLOSE_WINDOW, &RootWindowFrame::OnWindowClose, this);
}

RootWindowFrame::~RootWindowFrame() {
    delete m_themeManager;
    delete m_workspace;
}

void RootWindowFrame::drawMainWindow() {
    this->Maximize(true);
	this->Center();
	this->SetMinSize(wxSize(800, 600));
}

void RootWindowFrame::buildMenuBar() {
    wxMenuItem* newMenuItem = new wxMenuItem(m_fileMenu, NEW_FILE_MENU_ID, "&New\tCtrl+N");
    wxMenuItem* openMenuItem = new wxMenuItem(m_fileMenu, OPEN_FILE_MENU_ID, "&Open\tCtrl+O");
    wxMenuItem* saveMenuItem = new wxMenuItem(m_fileMenu, SAVE_FILE_MENU_ID, "&Save\tCtrl+S");
    wxMenuItem* saveAsMenuItem = new wxMenuItem(m_fileMenu, SAVE_AS_FILE_MENU_ID, "Save &As...\tCtrl+Shift+S");

    wxMenuItem* importMenuItem = new wxMenuItem(m_fileMenu, IMPORT_FILE_MENU_ID, "&Import...");
    wxMenuItem* exportMenuItem = new wxMenuItem(m_fileMenu, EXPORT_FILE_MENU_ID, "&Export...");

    wxMenuItem* exitMenuItem = new wxMenuItem(m_fileMenu, EXIT_FILE_MENU_ID, "Exit\tCtrl+Q");

    m_fileMenu->Append(newMenuItem);
    m_fileMenu->Append(openMenuItem);
    m_fileMenu->Append(saveMenuItem);
    m_fileMenu->Append(saveAsMenuItem);
    m_fileMenu->AppendSeparator();
    m_fileMenu->Append(importMenuItem);
    m_fileMenu->Append(exportMenuItem);
    m_fileMenu->AppendSeparator();
    m_fileMenu->Append(exitMenuItem);

    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnNew, this, NEW_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnOpen, this, OPEN_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnSave, this, SAVE_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnSaveAs, this, SAVE_AS_FILE_MENU_ID);

    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnImport, this, IMPORT_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnExport, this, EXPORT_FILE_MENU_ID);

    m_fileMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnExit, this, EXIT_FILE_MENU_ID);

    wxMenuItem* undoMenuItem = new wxMenuItem(m_editMenu, UNDO_EDIT_MENU_ID, "&Undo\tCtrl+Z");
    wxMenuItem* redoMenuItem = new wxMenuItem(m_editMenu, REDO_EDIT_MENU_ID, "&Redo\tCtrl+Y");

    m_editMenu->Append(undoMenuItem);
    m_editMenu->Append(redoMenuItem);

    m_editMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnUndo, this, UNDO_EDIT_MENU_ID);
    m_editMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnRedo, this, REDO_EDIT_MENU_ID);
    
    wxMenuItem* themeMenuItem = new wxMenuItem(m_optionsMenu, THEME_OPTION_MENU_ID, "Change Appearance...");
    
    m_optionsMenu->Append(themeMenuItem);
    m_optionsMenu->Bind(wxEVT_MENU, &RootWindowFrame::OnThemeChange, this, THEME_OPTION_MENU_ID);

    m_menuBar->Append(m_fileMenu, "&File");
    m_menuBar->Append(m_editMenu, "&Edit");
    m_menuBar->Append(m_optionsMenu, "&Options");

    SetMenuBar(m_menuBar);
}

void RootWindowFrame::buildToolBar() {
    wxInitAllImageHandlers();

    wxImage newToolImg("art/dark/new-project.png", wxBITMAP_TYPE_PNG);
    wxImage openToolImg("art/dark/open-project.png", wxBITMAP_TYPE_PNG);
    wxImage saveToolImg("art/dark/save-project.png", wxBITMAP_TYPE_PNG);
    wxImage undoToolImg("art/dark/undo.png", wxBITMAP_TYPE_PNG);
    wxImage redoToolImg("art/dark/redo.png", wxBITMAP_TYPE_PNG);
    wxImage runToolImg("art/dark/run-project.png", wxBITMAP_TYPE_PNG);

    newToolImg.Rescale(22, 22);
    openToolImg.Rescale(22, 22);
    saveToolImg.Rescale(22, 22);
    undoToolImg.Rescale(22, 22);
    redoToolImg.Rescale(22, 22);
    runToolImg.Rescale(22, 22);

    wxBitmap newToolBitmap(newToolImg);
    wxBitmap openToolBitmap(openToolImg);
    wxBitmap saveToolBitmap(saveToolImg);
    wxBitmap undoToolBitmap(undoToolImg);
    wxBitmap redoToolBitmap(redoToolImg);
    wxBitmap runToolBitmap(runToolImg);

    m_toolBar->AddTool(NEW_TOOL_ID, "New", newToolBitmap);
    m_toolBar->AddTool(OPEN_TOOL_ID, "Open", openToolBitmap);
    m_toolBar->AddSeparator();
    m_toolBar->AddTool(SAVE_TOOL_ID, "Save", saveToolBitmap);
    m_toolBar->AddSeparator();
    m_toolBar->AddTool(UNDO_TOOL_ID, "Undo", undoToolBitmap);
    m_toolBar->AddTool(REDO_TOOL_ID, "Redo", redoToolBitmap);
    m_toolBar->AddSeparator();
    m_toolBar->AddTool(RUN_TOOL_ID, "Run", runToolBitmap);

    m_toolBar->SetToolShortHelp(NEW_TOOL_ID, "New Project");
    m_toolBar->SetToolShortHelp(OPEN_TOOL_ID, "Open Project");
    m_toolBar->SetToolShortHelp(SAVE_TOOL_ID, "Save Current Project");
    m_toolBar->SetToolShortHelp(UNDO_TOOL_ID, "Undo Last Action");
    m_toolBar->SetToolShortHelp(REDO_TOOL_ID, "Redo Last Action");
    m_toolBar->SetToolShortHelp(RUN_TOOL_ID, "Build and Run Project");

    m_toolBar->Bind(wxEVT_TOOL, &RootWindowFrame::OnNew, this, NEW_TOOL_ID);

    m_toolBar->Bind(wxEVT_TOOL, &RootWindowFrame::OnOpen, this, OPEN_TOOL_ID);
    m_toolBar->Bind(wxEVT_TOOL, &RootWindowFrame::OnSave, this, SAVE_TOOL_ID);

    m_toolBar->Bind(wxEVT_TOOL, &RootWindowFrame::OnUndo, this, UNDO_TOOL_ID);
    m_toolBar->Bind(wxEVT_TOOL, &RootWindowFrame::OnRedo, this, REDO_TOOL_ID);

    m_toolBar->Bind(wxEVT_TOOL, &RootWindowFrame::OnRun, this, RUN_TOOL_ID);

    m_toolBar->Realize();

    m_toolbarSizer->Add(m_toolBar, 0, wxEXPAND);
    m_toolbarPanel->SetSizer(m_toolbarSizer);

    m_baseSizer->Add(m_toolbarPanel, 0, wxEXPAND);
}

void RootWindowFrame::buildWorkspace() {
    m_workspaceSizer->Add(m_workspace, 1, wxEXPAND);
    m_workspacePanel->SetSizer(m_workspaceSizer);

    m_baseSizer->Add(m_workspacePanel, 1, wxEXPAND);

    this->SetSizer(m_baseSizer);
    
    m_workspace->DrawWorkspaceFrame();
}

void RootWindowFrame::OnNew(wxCommandEvent& evt) {
    m_bypassCloseCheck = false;
    m_workSaved = false;

    m_menuBar->Enable(SAVE_FILE_MENU_ID, true);
    m_menuBar->Enable(SAVE_AS_FILE_MENU_ID, true);
    m_toolBar->EnableTool(SAVE_TOOL_ID, true);
    m_toolBar->EnableTool(SAVE_AS_TOOL_ID, true);

    wxLogStatus("MainFrame::onNew(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnOpen(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnOpen(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnSave(wxCommandEvent& evt) {
    m_bypassCloseCheck = true;
    m_workSaved = true;

    m_menuBar->Enable(SAVE_FILE_MENU_ID, false);
    m_toolBar->EnableTool(SAVE_TOOL_ID, false);
    
    wxLogStatus("MainFrame::OnSave(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnSaveAs(wxCommandEvent& evt) {
    m_bypassCloseCheck = true;
    m_workSaved = true;

    m_menuBar->Enable(SAVE_FILE_MENU_ID, false);
    m_toolBar->EnableTool(SAVE_TOOL_ID, false);

    wxLogStatus("MainFrame::OnSaveAs(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnImport(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnImport(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnExport(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnExport(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnUndo(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnUndo(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnRedo(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnRedo(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnThemeChange(wxCommandEvent& evt) {
    m_themeDialog->ShowModal();

    wxLogStatus("MainFrame::OnThemeChange(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnRun(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnRun(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnGlobalTextEntry(wxKeyEvent& evt) {
    wxLogStatus("MainFrame::OnGlobalTextEntry(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnExit(wxCommandEvent& evt) {
    closeWindowCheck();
    wxLogStatus("MainFrame::OnExit(); evt: %d", evt.GetId());
}

void RootWindowFrame::OnWindowClose(wxCloseEvent& evt) {
    if (m_bypassCloseCheck) {
        evt.Skip();
    } else {
        closeWindowCheck();
    }
}

void RootWindowFrame::closeWindowCheck() {
    int dialogReturnValue = wxNO;
    wxMessageDialog* exitDlg = new wxMessageDialog(this, "Are you sure you want to exit? Any unsaved works will be lost.", "Save before exiting?", wxYES_NO | wxCANCEL | wxICON_EXCLAMATION);
    exitDlg->SetYesNoCancelLabels("Close Without Saving", "Save", "Cancel");

    dialogReturnValue = exitDlg->ShowModal();

    wxCommandEvent evt;

    switch (dialogReturnValue) {
        case wxID_YES:
            m_bypassCloseCheck = true;
            OnExitConfirm();
            break;
        case wxID_NO:
            OnSave(evt);
            m_bypassCloseCheck = true;
            break;
        case wxID_CANCEL:
            m_bypassCloseCheck = false;
            break;
        default:
            m_bypassCloseCheck = false;
            break;
    }
}

void RootWindowFrame::OnExitConfirm() {
    if (m_bypassCloseCheck) {
        Close(true);
    }
}
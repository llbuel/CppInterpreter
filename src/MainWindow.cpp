#include <wx/artprov.h>
#include <wx/splitter.h>

#include "MainWindow.h"

enum ELEMENT_IDs {
    NEW_FILE_MENU_ID,
    OPEN_FILE_MENU_ID,
    SAVE_FILE_MENU_ID,
    SAVE_AS_FILE_MENU_ID,
    IMPORT_FILE_MENU_ID,
    EXPORT_FILE_MENU_ID,
    EXIT_FILE_MENU_ID,
    UNDO_EDIT_MENU_ID,
    REDO_EDIT_MENU_ID,

    NEW_TOOL_ID,
    OPEN_TOOL_ID,
    SAVE_TOOL_ID,
    SAVE_AS_TOOL_ID,
    UNDO_TOOL_ID,
    REDO_TOOL_ID,
    RUN_TOOL_ID,
};

MainWindowFrame::MainWindowFrame() : wxFrame(nullptr, wxID_ANY, "C++ Laboratory") {
    drawMainWindow();
    
    buildMenuBar();
    buildRibbonBar();
    buildWorkspace();

    CreateStatusBar();
    SetStatusText("Ready!");

    Bind(wxEVT_CLOSE_WINDOW, &MainWindowFrame::OnWindowClose, this);
}

void MainWindowFrame::drawMainWindow() {
    this->Maximize(true);
	this->Center();
	this->SetMinSize(wxSize(800, 600));
}

void MainWindowFrame::buildMenuBar() {
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

    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnNew, this, NEW_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnOpen, this, OPEN_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnSave, this, SAVE_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnSaveAs, this, SAVE_AS_FILE_MENU_ID);

    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnImport, this, IMPORT_FILE_MENU_ID);
    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnExport, this, EXPORT_FILE_MENU_ID);

    m_fileMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnExit, this, EXIT_FILE_MENU_ID);

    wxMenuItem* undoMenuItem = new wxMenuItem(m_editMenu, UNDO_EDIT_MENU_ID, "&Undo\tCtrl+Z");
    wxMenuItem* redoMenuItem = new wxMenuItem(m_editMenu, REDO_EDIT_MENU_ID, "&Redo\tCtrl+Y");

    m_editMenu->Append(undoMenuItem);
    m_editMenu->Append(redoMenuItem);

    m_editMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnUndo, this, UNDO_EDIT_MENU_ID);
    m_editMenu->Bind(wxEVT_MENU, &MainWindowFrame::OnRedo, this, REDO_EDIT_MENU_ID);
    
    m_menuBar->Append(m_fileMenu, "&File");
    m_menuBar->Append(m_editMenu, "&Edit");

    m_menuBar->Enable(SAVE_FILE_MENU_ID, false);
    m_menuBar->Enable(SAVE_AS_FILE_MENU_ID, false);
    
    SetMenuBar(m_menuBar);
}

void MainWindowFrame::buildRibbonBar() {
    wxBitmap newToolBitmap("art/new-tool32x32.png", wxBITMAP_TYPE_PNG);
    wxBitmap openToolBitmap("art/open-tool32x32.png", wxBITMAP_TYPE_PNG);
    wxBitmap saveToolBitmap("art/save-tool32x32.png", wxBITMAP_TYPE_PNG);
    wxBitmap saveAsToolBitmap("art/save-as-tool32x32.png", wxBITMAP_TYPE_PNG);
    // wxBitmap undoToolBitmap("art/undo-tool32x32.png", wxBITMAP_TYPE_PNG);
    // wxBitmap redoToolBitmap("art/redo-tool32x32.png", wxBITMAP_TYPE_PNG);
    wxBitmap runToolBitmap("art/run-tool32x32.png", wxBITMAP_TYPE_PNG);

    m_toolBar->AddTool(NEW_TOOL_ID, "New", newToolBitmap);
    m_toolBar->AddTool(OPEN_TOOL_ID, "Open", openToolBitmap);
    m_toolBar->AddSeparator();
    m_toolBar->AddTool(SAVE_TOOL_ID, "Save", saveToolBitmap);
    m_toolBar->AddTool(SAVE_AS_TOOL_ID, "Save As", saveAsToolBitmap);
    m_toolBar->AddSeparator();
    // m_toolBar->AddTool(UNDO_TOOL_ID, "Undo", undoToolBitmap);
    // m_toolBar->AddTool(REDO_TOOL_ID, "Redo", redoToolBitmap);
    // m_toolBar->AddSeparator();
    m_toolBar->AddTool(RUN_TOOL_ID, "Run", runToolBitmap);

    m_toolBar->EnableTool(SAVE_TOOL_ID, false);
    m_toolBar->EnableTool(SAVE_AS_TOOL_ID, false);

    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnNew, this, NEW_TOOL_ID);

    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnOpen, this, OPEN_TOOL_ID);
    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnSave, this, SAVE_TOOL_ID);
    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnSaveAs, this, SAVE_AS_TOOL_ID);

    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnUndo, this, UNDO_TOOL_ID);
    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnRedo, this, REDO_TOOL_ID);

    m_toolBar->Bind(wxEVT_TOOL, &MainWindowFrame::OnRun, this, RUN_TOOL_ID);

    m_toolBar->Realize();
}

void MainWindowFrame::buildWorkspace() {
    wxSplitterWindow* vert_splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DBORDER | wxSP_LIVE_UPDATE);

    wxSplitterWindow* horz_splitter = new wxSplitterWindow(vert_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DBORDER | wxSP_LIVE_UPDATE);

    wxPanel* directoryPanel = new wxPanel(vert_splitter);
    wxPanel* editorPanel = new wxPanel(horz_splitter);
    wxPanel* commandPanel = new wxPanel(horz_splitter);

    directoryPanel->SetMinSize(wxSize(200, 100));
    directoryPanel->SetBackgroundColour(wxColour(*wxWHITE));
    editorPanel->SetMinSize(wxSize(400, 100));
    editorPanel->SetBackgroundColour(wxColour(*wxWHITE));
    commandPanel->SetMinSize(wxSize(100, 100));
    commandPanel->SetBackgroundColour(wxColour(*wxWHITE));

    vert_splitter->SplitVertically(directoryPanel, horz_splitter);
    horz_splitter->SplitHorizontally(editorPanel, commandPanel);

    wxTextCtrl* commandWindow = new wxTextCtrl(commandPanel, wxID_ANY, " >> ", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    commandWindow->SetBackgroundColour(wxColour(*wxWHITE));
    commandWindow->SetForegroundColour(wxColour(*wxBLACK));
    commandWindow->SetMargins(wxPoint(5,10));

    wxBoxSizer* commandWindowSizer = new wxBoxSizer(wxVERTICAL);
    commandWindowSizer->Add(commandWindow, 1, wxEXPAND);
    commandPanel->SetSizer(commandWindowSizer);
}

void MainWindowFrame::OnNew(wxCommandEvent& evt) {
    m_bypassCloseCheck = false;
    m_workSaved = false;

    m_menuBar->Enable(SAVE_FILE_MENU_ID, true);
    m_menuBar->Enable(SAVE_AS_FILE_MENU_ID, true);
    m_toolBar->EnableTool(SAVE_TOOL_ID, true);
    m_toolBar->EnableTool(SAVE_AS_TOOL_ID, true);

    wxLogStatus("MainFrame::onNew()");
}

void MainWindowFrame::OnOpen(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnOpen()");
}

void MainWindowFrame::OnSave(wxCommandEvent& evt) {
    m_bypassCloseCheck = true;
    m_workSaved = true;

    m_menuBar->Enable(SAVE_FILE_MENU_ID, false);
    m_toolBar->EnableTool(SAVE_TOOL_ID, false);
    
    wxLogStatus("MainFrame::OnSave()");
}

void MainWindowFrame::OnSaveAs(wxCommandEvent& evt) {
    m_bypassCloseCheck = true;
    m_workSaved = true;

    m_menuBar->Enable(SAVE_FILE_MENU_ID, false);
    m_toolBar->EnableTool(SAVE_TOOL_ID, false);

    wxLogStatus("MainFrame::OnSaveAs()");
}

void MainWindowFrame::OnImport(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnImport()");
}

void MainWindowFrame::OnExport(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnExport()");
}

void MainWindowFrame::OnUndo(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnUndo()");
}

void MainWindowFrame::OnRedo(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnRedo()");
}

void MainWindowFrame::OnRun(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnRun()");
}

void MainWindowFrame::OnExit(wxCommandEvent& evt) {
    closeWindowCheck();
}

void MainWindowFrame::OnWindowClose(wxCloseEvent& evt) {
    if (m_bypassCloseCheck) {
        evt.Skip();
    } else {
        closeWindowCheck();
    }
}

void MainWindowFrame::closeWindowCheck() {
    int dialogReturnValue = wxNO;
    wxMessageDialog* exitDlg = new wxMessageDialog(this, "Are you sure you want to exit? Any unsaved files will be lost.", "Confirm Exit", wxYES_NO | wxCANCEL | wxICON_EXCLAMATION);
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

void MainWindowFrame::OnExitConfirm() {
    if (m_bypassCloseCheck) {
        Close(true);
    }
}
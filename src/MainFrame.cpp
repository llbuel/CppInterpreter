#include "MainFrame.h"
#include <wx/artprov.h>

enum MENU_IDs {
    NEW_FILE_MENU_ID = 2,
    OPEN_FILE_MENU_ID = 3,
    SAVE_FILE_MENU_ID = 4,
    SAVE_AS_FILE_MENU_ID = 5,
    IMPORT_FILE_MENU_ID = 6,
    EXPORT_FILE_MENU_ID = 7,
    EXIT_FILE_MENU_ID = 8,
    UNDO_EDIT_MENU_ID = 9,
    REDO_EDIT_MENU_ID = 10
};

enum TOOL_IDs {
    NEW_TOOL_ID = 11,
    OPEN_TOOL_ID = 12,
    SAVE_TOOL_ID = 13,
    SAVE_AS_TOOL_ID = 14,
    UNDO_TOOL_ID = 15,
    REDO_TOOL_ID = 16
};

MainFrame::MainFrame(): wxFrame(nullptr, wxID_ANY, "C++ Interpreter") {
    buildMenuBar();
    buildToolBar();

    CreateStatusBar();
    SetStatusText("Ready!");

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(wxColor(*wxLIGHT_GREY));
}

void MainFrame::buildMenuBar() {
    wxMenuBar* menuBar = new wxMenuBar();

    wxMenu* fileMenu = new wxMenu();

    wxMenuItem* newMenuItem = new wxMenuItem(fileMenu, NEW_FILE_MENU_ID, "&New\tCtrl+N");
    wxMenuItem* openMenuItem = new wxMenuItem(fileMenu, OPEN_FILE_MENU_ID, "&Open\tCtrl+O");
    wxMenuItem* saveMenuItem = new wxMenuItem(fileMenu, SAVE_FILE_MENU_ID, "&Save\tCtrl+S");
    wxMenuItem* saveAsMenuItem = new wxMenuItem(fileMenu, SAVE_AS_FILE_MENU_ID, "Save &As...\tCtrl+Shift+S");

    wxMenuItem* importMenuItem = new wxMenuItem(fileMenu, IMPORT_FILE_MENU_ID, "&Import...");
    wxMenuItem* exportMenuItem = new wxMenuItem(fileMenu, EXPORT_FILE_MENU_ID, "&Export...");

    wxMenuItem* exitMenuItem = new wxMenuItem(fileMenu, EXIT_FILE_MENU_ID, "Exit Optimum Odyssey\tCtrl+Q");

    fileMenu->Append(newMenuItem);
    fileMenu->Append(openMenuItem);
    fileMenu->Append(saveMenuItem);
    fileMenu->Append(saveAsMenuItem);
    fileMenu->AppendSeparator();
    fileMenu->Append(importMenuItem);
    fileMenu->Append(exportMenuItem);
    fileMenu->AppendSeparator();
    fileMenu->Append(exitMenuItem);

    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnNew, this, NEW_FILE_MENU_ID);
    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnOpen, this, OPEN_FILE_MENU_ID);
    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnSave, this, SAVE_FILE_MENU_ID);
    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnSaveAs, this, SAVE_AS_FILE_MENU_ID);

    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnImport, this, IMPORT_FILE_MENU_ID);
    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnExport, this, EXPORT_FILE_MENU_ID);

    fileMenu->Bind(wxEVT_MENU, &MainFrame::OnExit, this, EXIT_FILE_MENU_ID);

    wxMenu* editMenu = new wxMenu();

    wxMenuItem* undoMenuItem = new wxMenuItem(editMenu, UNDO_EDIT_MENU_ID, "&Undo\tCtrl+Z");
    wxMenuItem* redoMenuItem = new wxMenuItem(editMenu, REDO_EDIT_MENU_ID, "&Redo\tCtrl+Y");

    editMenu->Append(undoMenuItem);
    editMenu->Append(redoMenuItem);

    editMenu->Bind(wxEVT_MENU, &MainFrame::OnUndo, this, UNDO_EDIT_MENU_ID);
    editMenu->Bind(wxEVT_MENU, &MainFrame::OnRedo, this, REDO_EDIT_MENU_ID);
    
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(editMenu, "&Edit");
    SetMenuBar(menuBar);
}

void MainFrame::buildToolBar() {
    wxToolBar* toolBar = CreateToolBar();

    toolBar->AddTool(NEW_TOOL_ID, "New", wxArtProvider::GetBitmap("wxART_NEW"));
    toolBar->AddSeparator();
    toolBar->AddTool(OPEN_TOOL_ID, "Open", wxArtProvider::GetBitmap("wxART_FILE_OPEN"));
    toolBar->AddTool(SAVE_TOOL_ID, "Save", wxArtProvider::GetBitmap("wxART_FILE_SAVE"));
    toolBar->AddTool(SAVE_AS_TOOL_ID, "Save As", wxArtProvider::GetBitmap("wxART_FILE_SAVE_AS"));
    toolBar->AddSeparator();
    toolBar->AddTool(UNDO_TOOL_ID, "Undo", wxArtProvider::GetBitmap("wxART_UNDO"));
    toolBar->AddTool(REDO_TOOL_ID, "Redo", wxArtProvider::GetBitmap("wxART_REDO"));

    toolBar->Bind(wxEVT_TOOL, &MainFrame::OnNew, this, NEW_TOOL_ID);

    toolBar->Bind(wxEVT_TOOL, &MainFrame::OnOpen, this, OPEN_TOOL_ID);
    toolBar->Bind(wxEVT_TOOL, &MainFrame::OnSave, this, SAVE_TOOL_ID);
    toolBar->Bind(wxEVT_TOOL, &MainFrame::OnSaveAs, this, SAVE_AS_TOOL_ID);

    toolBar->Bind(wxEVT_TOOL, &MainFrame::OnUndo, this, UNDO_TOOL_ID);
    toolBar->Bind(wxEVT_TOOL, &MainFrame::OnRedo, this, REDO_TOOL_ID);

    toolBar->Realize();
}

void MainFrame::OnNew(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::onNew()");
}

void MainFrame::OnOpen(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnOpen()");
}

void MainFrame::OnSave(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnSave()");
}

void MainFrame::OnSaveAs(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnSaveAs()");
}

void MainFrame::OnImport(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnImport()");
}

void MainFrame::OnExport(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnExport()");
}

void MainFrame::OnUndo(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnUndo()");
}

void MainFrame::OnRedo(wxCommandEvent& evt) {
    wxLogStatus("MainFrame::OnRedo()");
}

void MainFrame::OnExit(wxCommandEvent& evt) {
    int dialogReturnValue = wxNO;
    wxMessageDialog* exitDlg = new wxMessageDialog(this, "Are you sure you want to exit? Any unsaved files will be lost.", "Confirm Exit", wxYES_NO | wxCANCEL | wxICON_EXCLAMATION);
    exitDlg->SetYesNoCancelLabels("Exit", "Save", "Cancel");

    exitDlg->Bind(wxEVT_BUTTON, &MainFrame::OnExitConfirm, this);
    exitDlg->Bind(wxEVT_BUTTON, &MainFrame::OnSave, this);

    dialogReturnValue = exitDlg->ShowModal();
}

void MainFrame::OnExitConfirm(wxCommandEvent& evt) {
    Close(true);
}
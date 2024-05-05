#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class CommandWindow : public wxPanel {
public:
    CommandWindow(wxWindow* parent) : wxPanel(parent) {};
    
    void InitCommandWindow();

    wxString GetText() const;
    wxString GetLastLine() const;
    void AppendText(const wxString& text);
    void SetEntryPoint(int newLines);

    void ClearCommandWindow();

private:
    wxPanel* m_commandWindowLeft = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
    wxPanel* m_commandWindowRight = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
    wxBoxSizer* m_commandWindowSizer = new wxBoxSizer(wxHORIZONTAL);
    wxTextCtrl* m_commandWindowEntryPoint = new wxTextCtrl(m_commandWindowLeft, wxID_ANY, "  >> ", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxTEXT_ALIGNMENT_RIGHT | wxNO_BORDER);
    wxTextCtrl* m_commandWindowTextEntry = new wxTextCtrl(m_commandWindowRight, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_PROCESS_ENTER | wxNO_BORDER);
	wxBoxSizer* m_entryPointSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* m_textEntrySizer = new wxBoxSizer(wxVERTICAL);
    wxString m_setChars = " >> ";
    wxSize m_charSize = m_commandWindowEntryPoint->GetTextExtent(m_setChars);
    std::vector<int> m_commandWindowLines = {0};
    bool m_newCommandEntrySet = false;
    int m_startPosition;

    void HandleKeyEvent(wxKeyEvent& evt);

};
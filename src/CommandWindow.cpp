#include "CommandWindow.h"

void CommandWindow::InitCommandWindow() {
    m_commandWindowLeft->SetBackgroundColour(wxColour(0x25, 0x25, 0x25));
    m_commandWindowRight->SetBackgroundColour(wxColour(0x25, 0x25, 0x25));
    
    m_commandWindowSizer->Add(m_commandWindowLeft, 0, wxEXPAND, 0);
    m_commandWindowSizer->Add(m_commandWindowRight, 1, wxEXPAND, 0);
    this->SetSizer(m_commandWindowSizer);

    m_commandWindowEntryPoint->SetBackgroundColour(wxColour(0x25, 0x25, 0x25));
    m_commandWindowEntryPoint->SetForegroundColour(wxColour(*wxWHITE));
    
    m_commandWindowTextEntry->SetBackgroundColour(wxColour(0x25, 0x25, 0x25));
    m_commandWindowTextEntry->SetForegroundColour(wxColour(*wxWHITE));
    m_commandWindowTextEntry->Bind(wxEVT_KEY_DOWN, &CommandWindow::HandleKeyEvent, this);

    m_entryPointSizer->Add(0, 10);
    m_entryPointSizer->Add(m_commandWindowEntryPoint, 1, wxEXPAND, 0);
    m_commandWindowLeft->SetSizer(m_entryPointSizer);

    m_textEntrySizer->Add(0, 10);
    m_textEntrySizer->Add(m_commandWindowTextEntry, 1, wxEXPAND, 0);
    m_commandWindowRight->SetSizer(m_textEntrySizer);

    m_commandWindowEntryPoint->SetMinSize(wxSize(m_charSize.GetWidth()+10, -1));
    m_commandWindowEntryPoint->SetMaxSize(wxSize(m_charSize.GetWidth()+10, -1));

    m_startPosition = m_commandWindowTextEntry->GetLastPosition();
}

void CommandWindow::HandleKeyEvent(wxKeyEvent& evt) {
    if (evt.GetKeyCode() == WXK_RETURN && !evt.ShiftDown()) {
        int totalLines = m_commandWindowTextEntry->GetNumberOfLines();
        
        if (m_commandWindowTextEntry->GetLineText(totalLines).IsEmpty()) {
            // Do nothing and discard event
        } else if (this->GetLastLine() == "clear") {
            this->ClearCommandWindow();
        } else {
            m_commandWindowTextEntry->AppendText("\n");
            m_startPosition = m_commandWindowTextEntry->GetLastPosition();
            
            wxString entry = this->GetText();
            int numNewLines = totalLines - m_commandWindowLines.back();
            m_commandWindowLines.push_back(totalLines);

            this->SetEntryPoint(numNewLines-1);
        }
    } else if (evt.GetKeyCode() == WXK_BACK && m_commandWindowTextEntry->GetInsertionPoint() <= m_startPosition) {
        // Do nothing and discard event
    } else if (evt.GetKeyCode() >= 32 && evt.GetKeyCode() <= 126) {
        if (m_commandWindowTextEntry->GetInsertionPoint() <= m_startPosition) {
            m_commandWindowTextEntry->SetInsertionPointEnd();
        }
        
        evt.Skip();
    } else {
        evt.Skip();
    }
}

wxString CommandWindow::GetText() const {
    return m_commandWindowTextEntry->GetValue();
}

wxString CommandWindow::GetLastLine() const {
    int numTextLines = m_commandWindowTextEntry->GetNumberOfLines();
    int startLastLine = m_commandWindowTextEntry->XYToPosition(0, numTextLines-1);
    int endLastLine = m_commandWindowTextEntry->GetLastPosition();

    wxString lastLine = m_commandWindowTextEntry->GetRange(startLastLine, endLastLine);

    return lastLine;
}

void CommandWindow::AppendText(const wxString& text) {
    m_commandWindowTextEntry->AppendText(text);
}

void CommandWindow::SetEntryPoint(int newLines) {
    for (int i = 0; i < newLines; i++) {
        m_commandWindowEntryPoint->AppendText("\n");
    }

    m_commandWindowEntryPoint->AppendText("\n  >> ");
}

void CommandWindow::ClearCommandWindow() {
    m_commandWindowEntryPoint->Clear();
    m_commandWindowTextEntry->Clear();

    m_commandWindowEntryPoint->AppendText("  >> ");
    m_commandWindowTextEntry->AppendText("");

    m_commandWindowLines = {0};
    m_startPosition = 0;

    m_commandWindowTextEntry->SetInsertionPoint(0);
}
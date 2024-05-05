#pragma once

#include <wx/wxprec.h>
#include <wx/artprov.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class ThemeArtProvider : public wxArtProvider {
public:
    ThemeArtProvider(const wxString& themePath) : m_themePath(themePath) {};

    wxBitmap CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size) override {
        (void)client;
        (void)size;
        
        if (id == wxART_NEW) {
            return wxBitmap(m_themePath + "16x16/document-new.png", wxBITMAP_TYPE_PNG);
        }

        return wxNullBitmap;
    }

private:
    wxString m_themePath;

};
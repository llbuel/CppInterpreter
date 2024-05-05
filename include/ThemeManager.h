#pragma once

#include <string>
#include <vector>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "ThemeArtProvider.h"

enum ThemeType {
    ENVIRONMENT,
    ICON
};

class ThemeManager {
public:
    ThemeManager(wxFrame* parent) : m_parent(parent) {};
    ~ThemeManager() = default;

    std::vector<std::string> GetEnvThemes() const;
    std::vector<std::string> GetIconThemes() const;
    void SetIconTheme(wxString& theme);

private:
    wxFrame* m_parent;

    std::vector<std::string> GetThemes(ThemeType type) const;
};
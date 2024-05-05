#include "ThemeManager.h"

#include <wx/artprov.h>
#include <wx/dir.h>

enum THEME_MENU_IDs {
    ENV_THEME_MENU_ID,
    ICON_THEME_MENU_ID,
};

std::vector<std::string> ThemeManager::GetEnvThemes() const {
    return GetThemes(ThemeType::ENVIRONMENT);
}

std::vector<std::string> ThemeManager::GetIconThemes() const {
    return GetThemes(ThemeType::ICON);
}

std::vector<std::string> ThemeManager::GetThemes(ThemeType type) const {
    std::vector<std::string> themes;
    std::string root;

    if (type == ThemeType::ENVIRONMENT) {
        root = "/usr/share/themes/";
    } else if (type == ThemeType::ICON) {
        root = "/usr/share/icons/";
    }

    wxDir dir(root);
    wxString filename;

    bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
    while (cont) {
        themes.push_back(filename.ToStdString());
        cont = dir.GetNext(&filename);
    }

    return themes;
}

void ThemeManager::SetIconTheme(wxString& themePath) {
    wxArtProvider::Push(new ThemeArtProvider(themePath));
}
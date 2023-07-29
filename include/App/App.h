#include <iostream>
#include <string>

class App {
private:
    bool m_quitApp;

    bool checkForQuit();
    void consoleInteraction();

public:
    App() : m_quitApp{ false } {}

    void run();
    bool quit() const { return m_quitApp; }
};
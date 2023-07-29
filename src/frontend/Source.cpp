#include <iostream>
#include <exception>

#include "frontend/Source.h"

namespace frontend {

char Source::m_EOL = '\n';
char Source::m_EOF = (char)0;

Source::Source(std::ifstream* reader) : m_lineNumber(0), m_currentPosition(-2), m_reader(reader) {}

char Source::getCurrentChar() {
    try {
        if (m_currentPosition == -2) {
            readLine();
            return getNextChar();
        }
        else if (m_line.empty()) {
            return m_EOF;
        }
        else if ((m_currentPosition == -1) || (m_currentPosition == m_line.length())) {
            return m_EOL;
        }
        else if (m_currentPosition > m_line.length()) {
            readLine();
            return getNextChar();
        }
        else {
            return m_line.at(m_currentPosition);
        }
    }
    catch (std::exception& e) {
        std::cout << "Could not get the current character: " << e.what() << "\n";
        return m_EOF;
    }

}

char Source::getNextChar() {
    try {
        m_currentPosition++;
        return getCurrentChar();
    }
    catch (std::exception& e) {
        std::cout << "Could not get the next character: " << e.what() << "\n";
        return m_EOF;
    }
}

char Source::peekChar() {
    try {
        getCurrentChar();

        if (m_line.empty()) {
            return m_EOF;
        }

        int nextPosition = m_currentPosition + 1;

        if (nextPosition < m_line.length()) {
            return m_line.at(nextPosition);
        }
        else {
            return m_EOL;
        }
    }
    catch (std::exception& e) {
        std::cout << "Could not peek the next character: " << e.what() << "\n";
        return m_EOF;
    }
}

void Source::readLine() {
    try {
        std::getline(*m_reader, m_line);
        m_currentPosition = -1;

        if (!m_line.empty()) {
            m_lineNumber++;
        }
    }
    catch (std::exception& e) {
        std::cout << "Could not read the next line in the file: " << e.what() << "\n";
    }
}

void Source::closeSource() {
    if (m_reader->is_open()) {
        try {
            m_reader->close();
        }
        catch (std::exception& e) {
            std::cout << "Could not close the source file: " << e.what() << "\n";
        }
    }
}

} // namespace frontend
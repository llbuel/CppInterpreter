#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Source {
private:
    std::ifstream& m_reader;
    std::string m_line;
    int m_lineNumber;
    int m_currentPosition;

    void readLine();

public:
    static char m_EOL;
    static char m_EOF;
    
    Source(std::ifstream& reader);

    char getCurrentChar();
    char getNextChar();
    char peekChar();
    void closeSource();
};

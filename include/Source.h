#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Source {
private:
    std::ifstream m_reader;
    std::string m_line;
    int m_lineNumber;
    int m_currentPosition;

public:
    Source();
    
    char getCurrentChar() const;
    char getNextChar() const;
};

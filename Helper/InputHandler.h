#ifndef InputHandler_HPP_
#define InputHandler_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>

class InputHandler
{
public:
    InputHandler() = default;
    InputHandler(const std::string& rFilePath);

    bool GetLine(std::string& rLine);
    bool IsOpen()const;

    std::vector<std::string> SplitString(const std::string& rInput, const char *rSeperator);

    void Close();

private:
    std::fstream m_file;
};

#endif // InputHandler_HPP_
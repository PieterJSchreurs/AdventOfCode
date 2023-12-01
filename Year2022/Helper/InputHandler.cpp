#include "InputHandler.h"

InputHandler::InputHandler(const std::string& rFilePath): m_file(rFilePath)
{
}

bool InputHandler::GetLine(std::string& rLine)
{
    if(!IsOpen())
        throw std::runtime_error("File is not open!");
    
    return std::getline(m_file, rLine) ? true : false;
}

std::vector<std::string> InputHandler::SplitString(const std::string& rInput, const char *rSeperator)
{
    std::vector<std::string> returnVector;
    const int length = rInput.length();
    char* charArray = new char[length];
    strcpy(charArray, rInput.c_str());
    
    char *token = strtok(charArray, rSeperator);

    while(token) {
        returnVector.push_back(token);
        token = strtok(NULL,rSeperator);
    }
    
    return returnVector;
}

bool InputHandler::IsOpen() const
{
    return m_file.is_open();
}

void InputHandler::Close()
{
    if(IsOpen())
        m_file.close();
}
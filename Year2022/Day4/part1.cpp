#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include <InputHandler.h>

using namespace std;

bool isBetweenValues(int min, int max, int value) 
{
    cout << "\nchecking min" << min << " max:" << max << " : " << value << "\n";
    if(value <= max && value >= min)
    {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    std::string filePath = "../Day4/input.txt";
    std::string line;
    InputHandler inputHandler(filePath);
    const char* splitComma = ",";
    const char* splitDash = "-";
    int count = 0;
    bool contains = false;

    if(inputHandler.IsOpen())
    {
        while(inputHandler.GetLine(line))
        {
         std::vector<std::string> LeftRight = inputHandler.SplitString(line, ",");
           std::vector<std::string> FirstNumbers = inputHandler.SplitString(LeftRight[0], splitDash);
           std::vector<std::string> SecondNumbers = inputHandler.SplitString(LeftRight[1], splitDash);
           contains = false;

           if(isBetweenValues(stoi(FirstNumbers[0]), stoi(FirstNumbers[1]), stoi(SecondNumbers[0])))
           {
                if(isBetweenValues(stoi(FirstNumbers[0]), stoi(FirstNumbers[1]), stoi(SecondNumbers[1])))
                {
                    count++;
                    contains = true;
                }
           } 
           if(!contains) 
           {
                if(isBetweenValues(stoi(SecondNumbers[0]), stoi(SecondNumbers[1]), stoi(FirstNumbers[0])))
                {
                    if(isBetweenValues(stoi(SecondNumbers[0]), stoi(SecondNumbers[1]), stoi(FirstNumbers[1])))
                    {
                        count++;
                    }
                } 
           }
        }      

        cout << count;
    } else {
        std::cout << "could not open file";
    }
}



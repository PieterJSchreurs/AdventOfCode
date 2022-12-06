#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

std::vector<std::string> SplitString(const std::string& rInput, const char *rSeperator)
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

int main(int argc, char const *argv[])
{
   
    std::vector<string> opponentPick;
    std::vector<string> myPick;
    std::string filePath = "C:\\Users\\piete\\Documents\\Repositories\\AdventOfCode\\Day2\\input.txt";
    uint32_t points = 0;
    std::ifstream fileStream;

    fileStream.open(filePath);
    

    if(fileStream.is_open())
    {
        while(fileStream)
        {
            string line;
            const char* splitCharacter = " ";
            getline(fileStream, line);
            if(line.size() > 1) {
            std::vector<std::string> splitString = SplitString(line, splitCharacter);
            opponentPick.push_back(splitString[0]);
            myPick.push_back(splitString[1]);
            }
        }

        cout << "size is " << opponentPick.size() << " and " << myPick.size();

        for(int i = 0; i < opponentPick.size(); i++)
        {
            if(myPick[i] == "X")
            {
                points+=1;
                if(opponentPick[i] == "A")
                {
                    points += 3;
                } else if (opponentPick[i] == "C")
                {
                    points +=6;
                }
            } else if(myPick[i] == "Y")
            {
                points+=2;
                 if(opponentPick[i] == "B")
                {
                    points +=3;
                } else if (opponentPick[i] == "A")
                {
                    points +=6;
                }
            } else if(myPick[i] == "Z")
            {
                points+=3;
                if(opponentPick[i] == "C")
                {
                    points += 3;
                } else if (opponentPick[i] == "B")
                {   
                    points +=6;
                }
            }
        }
    } else {
        std::cout << "could not open file";
    }

    cout << "total is " << points;
}



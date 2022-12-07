#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int GetCharValue(string rFirstString, string rSecondString, string rThirdString)
{
    char commonletter;
    std::vector<char> commonLetters;
    for(int i = 0; i < rFirstString.size(); i++)
    {
        for (int j = 0; j <= rSecondString.size(); j++)
        {
            if(rFirstString[i] == rSecondString[j])
            {
                commonLetters.push_back(rFirstString[i]);
            }            
        }
    }

    for (int i = 0; i < commonLetters.size(); i++)
    {
        for (int j = 0; j < rThirdString.size(); j++)
        {
            if(commonLetters[i] == rThirdString[j])
            {
            commonletter = commonLetters[i];
            return (int)commonletter;
            }
        }
    }
    commonLetters.clear();
    

    return 0;
}

int main(int argc, char const *argv[])
{
   
    std::vector<string> opponentPick;
    std::vector<string> myPick;
    std::string filePath = "C:\\Users\\piete\\Documents\\Repositories\\AdventOfCode\\Day3\\input.txt";
    uint32_t points = 0;
    std::ifstream fileStream;

    fileStream.open(filePath);
    

    if(fileStream.is_open())
    {
        while(fileStream)
        {
            string line;
            std::vector<string> groupOfElves;
            while(groupOfElves.size() <= 2)
            {
                getline(fileStream, line);
                groupOfElves.push_back(line);
            }
            
            int charValue = GetCharValue(groupOfElves[0],groupOfElves[1],groupOfElves[2]);
            groupOfElves.clear();
            int lineSize = line.size();
            
            if(charValue > 96 && charValue > 0)
            {
                charValue -= 96;
            } else if(charValue > 0){
                charValue += 26; 
                charValue -= 64;
            } else {
                charValue = 0;
            }

            points += charValue;
        }

       
    } else {
        std::cout << "could not open file";
    }

    cout << "Points total is " << points;

}



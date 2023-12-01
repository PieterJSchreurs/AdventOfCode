#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int GetCharValue(string rFirstHalf, string rSecondHalf)
{
    char commonletter;
    for(int i = 0; i < rFirstHalf.size(); i++)
    {
        for (int j = 0; j <= rSecondHalf.size(); j++)
        {
            if(rFirstHalf[i] == rSecondHalf[j])
            {
                commonletter = rFirstHalf[i];
                cout << "found commmon letter " << commonletter << " with value "<< (int)commonletter << "\n";
                return (int)commonletter;
            }
        }
    }

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
            getline(fileStream, line);
            int lineSize = line.size();
            string firstHalf = line.substr(0,lineSize/2);
            string secondHalf = line.substr(lineSize/2, lineSize/2);
            
            int charValue = GetCharValue(firstHalf,secondHalf);

            cout << "Character value is " << charValue << "\n";
            if(charValue > 96 && charValue > 0)
            {
                charValue -= 96;
            } else if(charValue > 0){
                charValue += 26; 
                charValue -= 64;`
            } else {
                charValue = 0;
            }

            cout << "Letter value is " << charValue << "\n";

            points += charValue;
        }

       
    } else {
        std::cout << "could not open file";
    }

    cout << "Points total is " << points;

}



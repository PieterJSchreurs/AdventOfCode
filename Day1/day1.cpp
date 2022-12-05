#include <iostream>
#include <fstream>
#include <string>

using namespace std;
  
int main(int argc, char const *argv[])
{
    std::string line;
    std::string filePath = "input.txt";
    std::ifstream fileStream;

    int totalCarryingCapacity = 0;
    int highestCarryingCapacity = 0;

    fileStream.open(filePath);

    if(fileStream.is_open())
    {
        while(fileStream)
        {
            std::getline(fileStream, line);
            if(!line.empty()) {            
                int num = stoi(line);
                totalCarryingCapacity += num;
            }
            //Detect for new elf
            if(line.empty())
            {
                if(totalCarryingCapacity > highestCarryingCapacity)
                {
                    highestCarryingCapacity = totalCarryingCapacity;
                }
                totalCarryingCapacity = 0;
            }
        }
        std::cout << "Highest is " << highestCarryingCapacity;
        fileStream.close();
    }
    
    else {
        std::cout << "Could not open file";
    }
  
    return 0;
}
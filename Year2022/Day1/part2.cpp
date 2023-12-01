#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
  
int main(int argc, char const *argv[])
{
    std::string line;
    std::string filePath = "input.txt";
    std::ifstream fileStream;

    std::vector<int> total;

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
               total.push_back(totalCarryingCapacity);
               totalCarryingCapacity = 0;
            }
        }
        std::sort(total.begin(), total.end());
        std::reverse(total.begin(), total.end());

        std::cout << "Total in top three is " << total[0] + total[1] + total[2];
        fileStream.close();
    }
    
    else {
        std::cout << "Could not open file";
    }
  
    return 0;
}
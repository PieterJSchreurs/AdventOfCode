#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include <InputHandler.h>

using namespace std;

int main(int argc, char const *argv[])
{
    std::string filePath = "../Day5/input.txt";
    std::string line;
    InputHandler inputHandler(filePath);
    const char* splitSpace = " ";
     std::vector<std::vector<char>> boxes;

    if(inputHandler.IsOpen())
    {
        int row = 0;
        boxes.resize(36);
        while(inputHandler.GetLine(line))
        {
            if(line.find("move"))
            {
                string LineCopy = line;
                for (int i = 0; i < LineCopy.size(); i++)
                {
                    if(LineCopy[i] == '[')
                    {
                        int index = i/4;
                        boxes[index].insert(boxes[index].begin(), LineCopy[i+1]);
                    }
                }
            } else {
                string LineCopy = line;
               std::vector<std::string> command = inputHandler.SplitString(LineCopy,splitSpace);

               int amount = stoi(command[1]);
               int from = stoi(command[3])-1;
               int to = stoi(command[5])-1;

               for (int i = 0; i < amount; i++)
               {
                    char test = boxes[from][boxes[from].size()-1];
                    boxes[from].pop_back();
                    boxes[to].insert(boxes[to].end(), test);
                   
               }
               

            }
            
        }      

        for (int i = 0; i < boxes.size(); i++)
        {
            for (int j = 0; j < boxes[i].size(); j++)
            {
                cout << boxes[i][j] << "\t";
            }
            cout << "\n";
        }
    } else {
        std::cout << "could not open file";
    }
}



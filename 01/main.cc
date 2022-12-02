#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    int currentElfCalories = 0;
    int maxElfCalories = 0;
    int elfNumber = 0;
    int index = 0;
    int calories = 0;
    ifstream dataFile("./data.txt");
    
    while( getline(dataFile, line) )
    {
        if (line.empty())
        {
            if (currentElfCalories > maxElfCalories)
            {
                maxElfCalories = currentElfCalories;
                elfNumber = index;
            }
            currentElfCalories = 0;
            ++index;
        }
        else
        {
            calories = stoi(line);
            currentElfCalories += calories;
        }
    }
    cout << "Elf carrying the most calories is Elf nb: " << elfNumber << "\n";
    cout << "This elf carries " << maxElfCalories << " calories in total." << "\n";
    dataFile.close();

    return 0;
}
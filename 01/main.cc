#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    int currentElfCalories = 0;
    int firstMaxElfCalories = 0;
    int secondMaxElfCalories = 0;
    int thirdMaxElfCalories = 0;
    int firstElfNumber = 0;
    int secondElfNumber = 0;
    int thirdElfNumber = 0;
    int index = 0;
    int calories = 0;
    ifstream dataFile("./data.txt");
    
    while( getline(dataFile, line) )
    {
        if (line.empty())
        {
            if (currentElfCalories >          thirdMaxElfCalories &&
                currentElfCalories > secondMaxElfCalories &&
                currentElfCalories >
                firstMaxElfCalories)
            {
                thirdMaxElfCalories = secondMaxElfCalories;
                secondMaxElfCalories = firstMaxElfCalories;
                firstMaxElfCalories = currentElfCalories;
                thirdElfNumber = secondElfNumber;
                secondElfNumber = firstElfNumber;
                firstElfNumber = index;
            }
            else if (currentElfCalories > thirdMaxElfCalories &&
            currentElfCalories > secondMaxElfCalories)
            {
                thirdMaxElfCalories = secondMaxElfCalories;
                secondMaxElfCalories = currentElfCalories;
                thirdElfNumber = secondElfNumber;
                secondElfNumber = index;
            }
            else if (currentElfCalories > thirdMaxElfCalories)
            {
                thirdMaxElfCalories = currentElfCalories;
                thirdElfNumber = index;
            }
            currentElfCalories = 0;
            ++index;
        }
        else
        {
            calories = stoi(line);
            cout << calories << "\n";
            currentElfCalories += calories;
        }
    }
    if (currentElfCalories > thirdMaxElfCalories &&
        currentElfCalories > secondMaxElfCalories &&
        currentElfCalories > firstMaxElfCalories)
    {
        thirdMaxElfCalories = secondMaxElfCalories;
        secondMaxElfCalories = firstMaxElfCalories;
        firstMaxElfCalories = currentElfCalories;
        thirdElfNumber = secondElfNumber;
        secondElfNumber = firstElfNumber;
        firstElfNumber = index;
    }
    else if (currentElfCalories > thirdMaxElfCalories &&
    currentElfCalories > secondMaxElfCalories)
    {
        thirdMaxElfCalories = secondMaxElfCalories;
        secondMaxElfCalories = currentElfCalories;
        thirdElfNumber = secondElfNumber;
        secondElfNumber = index;
    }
    else if (currentElfCalories > thirdMaxElfCalories)
    {
        thirdMaxElfCalories = currentElfCalories;
        thirdElfNumber = index;
    }
    cout << "The elf carrying the most calories is Elf nb: " << firstElfNumber << " with " << firstMaxElfCalories << " calories in total." << "\n";
    cout << "The second elf carrying the most calories is Elf nb: " << secondElfNumber << " with " << secondMaxElfCalories << " calories in total." << "\n";
    cout << "The third elf carrying the most calories is Elf nb: " << thirdElfNumber << " with " << thirdMaxElfCalories << " calories in total." << "\n";
    int totalMaxCalories = firstMaxElfCalories + secondMaxElfCalories + thirdMaxElfCalories;
    cout << "These three elves carry " << totalMaxCalories << " calories in total." << "\n";
    dataFile.close();

    return 0;
}
// for i = 0 to size, for j  i+1 to size
#include <iostream>
#include <string>
#include <algorithm>

const int ARR_SIZE = 10;

int main()
{
    string defaultValue = "( , )"
    string orderedPairs [ARR_SIZE][ARR_SIZE];
    std::fill(orderedPairs[0], orderedPairs[0] + ARR_SIZE * ARR_SIZE, defaultValue); // Fill all in double array with "( , )"
    for(int i = 0; i < ARR_SIZE; i++)
    {
        for(int j = i + 1; j < ARR_SIZE; j++)
        {
            orderedPairs[i][j] = "(" + std::to_string(i) + "," + std::to_string(j) + ")";
        }
    }

    for(int i = 0; i < ARR_SIZE; i++)
    {
        for(int j = 0; i < ARR_SIZE; j++)
        {
            std::cout << orderedPairs[i][j] + " ";
        }
        std::cout << "\n";
    }
}
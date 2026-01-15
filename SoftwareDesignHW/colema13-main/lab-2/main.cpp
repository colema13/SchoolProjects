#include "IntVector.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    bool finished;
    std::string answer;
    IntVector vector;
    std::cout << "Welcome This Vector!" << std::endl;

    while(!finished)
    {
        std::cout << "Add an Integer: ";
        std::cin >> answer;
        std::cout << std::endl;

        char* end;
        long value = strtol(answer.c_str(), &end, 0);

        if (*end != '\0')
        {
            finished = true;
        }
        else
        {
            vector.append(value);
        }


    }

    int total = 0;
    for (int i = 0; i < vector.getSize(); ++i)
    {
        total += vector.get_value(i);
    }

    std::cout << "Sum of values in Vector: " << total << std::endl;

    int presetValues[] = {0, 1, 2, 3, 4};
    int presetSize = 5;
    IntVector presetVector(presetSize, presetValues);

    int presetSum = 0;
    for (int i = 0; i < presetVector.getSize(); ++i)
    {
        presetSum += presetVector.get_value(i);
    }

    std::cout << "Sum of values in presetVector: " << presetSum << std::endl;



    return 0;
}
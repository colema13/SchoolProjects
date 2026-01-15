#include "IntVector.hpp"
#include <iostream>

IntVector::IntVector()
{
    values = new int[1];
    capacity = 1;
    size = 0;
}

IntVector::IntVector(int startingCapacity)
{
    values = new int[startingCapacity];
    capacity = startingCapacity;
    size = 0;

}

IntVector::IntVector(int startingCapacity, int* intitValues)
{
    values = new int[startingCapacity];
    capacity = startingCapacity;
    size = startingCapacity;

    for(int i = 0; i < size; i++)
    {
        values[i] = intitValues[i];
    }

}

IntVector::~IntVector()
{
    delete[] values;
}

int IntVector::getCapacity()
{
    return capacity;
}

int IntVector::getSize()
{
    return size;
}

void IntVector::append(int newValue)
{
    if(size < capacity)
    {
        values[size] = newValue;
        size++;
        std::cout << "Item Added" << std::endl;
    }

    else
    {
        int newCapacity = capacity * 2;
        int* newValues = new int[newCapacity];
        copy(values, newValues);

        delete[] values;

        values = newValues;
        capacity = newCapacity;
        values[size] = newValue;
        size++;
        std::cout << "Item Added" << std::endl;

    }
}

int IntVector::get_value(int index)
{
    if(index < size)
    {
        return values[index];
    }
    else
    {
        std::cout << "Index not within size" << std::endl;
        return -1;

    }
}

void IntVector::copy(int* oldArray, int* newArray)
{
    for(int i = 0; i < size; i++)
    {
        newArray[i] = oldArray[i];
    }
}
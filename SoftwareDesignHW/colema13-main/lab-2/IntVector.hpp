#ifndef INTVECTOR_HPP
#define INTVECTOR_HPP

class IntVector
{
    public:
    IntVector();

    IntVector(int startingCapacity);

    IntVector(int startingCapacity, int* intitValues);

    ~IntVector();

    int getCapacity();

    int getSize();
   
    void append(int newValue);

    int get_value(int index);




    private:
        int capacity;
        int size;
        int* values;

        void copy(int* oldArray, int* newArray);



};

#endif
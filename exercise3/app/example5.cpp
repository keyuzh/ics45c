#include "example5.hpp"


void addAll(int* target, int* source, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        target[i] += source[i];
    }
}


int findMax(int* a, unsigned int size)
{
    int result = a[0];

    for (unsigned int i = 1; i < size; ++i)
    {
        if (a[i] > result)
        {
            result = a[i];
        }
    }

    return result;
}


int* allocateAndFill(unsigned int size, int value)
{
    int* a = new int[size];

    for (unsigned int i = 0; i < size; ++i)
    {
        a[i] = value;
    }

    return a;
}


void runExample5()
{
    int* a1 = allocateAndFill(10, 3);
    int* a2 = allocateAndFill(5, 9);
    int* a3 = new int[10];
    int* a4 = a2;

    addAll(a1, a2, 10);
    a1[0] = findMax(a3, 10);
    addAll(a1, a3, 10);

    delete[] a2;
    delete[] a4;
}


#include "array_operations.hh"
#include <iostream>
using namespace std;

int greatest_v1(int *itemptr, int size)
{
    int greatest = 0;
    while(*itemptr <= (size) )
    {
        if(greatest < *itemptr)
            greatest = *itemptr;
        ++itemptr;
    }
    return greatest;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int greatest = 0;
    while (itemptr < endptr)
    {
        if(greatest < *itemptr)
            greatest = *itemptr;
        ++itemptr;
    }
    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    int count = 0;
    while (itemptr < endptr)
    {
        *(targetptr + count) = *itemptr;
        ++count;
        ++itemptr;
    }
}

void reverse(int *leftptr, int *rightptr)
{
    --rightptr;
    while(leftptr < rightptr)
    {
        int temp = *leftptr;
        *leftptr = *rightptr;
        *rightptr = temp;
        ++leftptr;
        --rightptr;
    }
}

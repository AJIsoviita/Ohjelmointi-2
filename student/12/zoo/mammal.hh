#ifndef MAMMAL_HH
#define MAMMAL_HH
#include "animal.hh"
#include <iostream>
#include <fstream>

using namespace std;

class Mammal: public Animal
{
public:
    Mammal();
    void suckle(ostream& output);
};

#endif // MAMMAL_HH

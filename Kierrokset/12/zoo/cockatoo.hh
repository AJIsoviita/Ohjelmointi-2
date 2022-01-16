#ifndef COCKATOO_HH
#define COCKATOO_HH
#include "bird.hh"
#include <fstream>
#include <iostream>

using namespace std;

class Cockatoo: public Bird
{
public:
    Cockatoo();
    void sing(ostream& output);
};

#endif // COCKATOO_HH

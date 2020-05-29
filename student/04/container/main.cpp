#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; i++)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(vector<int> integers)
{
    for (int i : integers)
    {
    if (integers.at(i) == integers.at(0))
        return true;
    else
        return false;
    }
    return 0;
}

bool is_ordered_non_strict_ascending(vector<int> integers)
{
    for (int i : integers)
    {
        if (integers.at(i) <= integers.at(i+1))
            return true;
        else
            return false;
    }
    return 0;
}

bool is_arithmetic_series(vector<int> integers)
{
    int i = 0;
    int size = integers.size();
    int difference = integers.at(i + 1) - integers.at(i);
    int difference2 = 0;
    int x = 0;
    int a = 1;
    for (int i : integers)
    {
        a++;
        if ( a < size)
        {
        difference2 = integers.at(i+1) - integers.at(i);
        if ( difference == difference2)
        {
            x++;
        }
        else
            return false;
        }
    }
    if (x == (size - 2))
        return true;
    else
        return false;
}

bool is_geometric_series(vector<int> integers)
{
    int amount = 0;
    int size = integers.size();
    for (int i : integers)
    {
    if (i == 0)
        amount++;
    }
    if (amount == size)
        return false;
    int i = 0;
    int q = integers.at(i+ 1) / integers.at(i);
    int q2 = 0;
    int x = 0;
    int a = 1;
    for (int i : integers)
    {
        a++;
        if (a < size)
        {
        q2 = integers.at(i + 1) / integers.at(i);
        if ( q == q2)
        {
            x++;
        }
        else
            return false;
        }
    }
    if (x == (size - 2))
        return true;
    else
        return false;
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(vector<int> integers)
{
    int last_value = 0;
       int size = integers.size();
       for(int i = 0; i < size; ++i){
           if( i > 0 && integers.at(i) != last_value){
               return false;
           }
           last_value = integers.at(i);
       }
       return true;
}

bool is_ordered_non_strict_ascending(vector<int> integers)
{
    int size = integers.size();
    int last_value = 0;
    for (int i = 0; i < size; ++i )
    {
        if( i > 0 && integers.at(i) < last_value){
                    return false;
                    }
                last_value = integers.at(i);
            }
            return true;
}

bool is_arithmetic_series(vector<int> integers)
{
    int size = integers.size();
        int last_value = 0;
        int current_value;
        int summa = 0;
        for(int i = 0; i < size; ++i)
        {
            current_value = integers.at(i);
            if (i == 1){
                summa = integers.at(i) - last_value;
            }
            if( i > 1 && (last_value + summa) != current_value ){
                return false;

            }

            last_value = integers.at(i);
        }
        return true;
}

bool is_geometric_series(vector<int> integers)
{
    int size = integers.size();
       int last_value = 0;
       int current_value;
       float divide_and_conquer = 0;
       for(int i = 0; i < size; ++i){
           current_value = integers.at(i);
           if (current_value == 0){
               return false;
           }
           if( i == 1 ){
               divide_and_conquer = integers.at(i) / last_value;
           }
           if ( i > 0 && (last_value * divide_and_conquer) != current_value){
               return false;
           }

           last_value = integers.at(i);
       }
       return true;
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

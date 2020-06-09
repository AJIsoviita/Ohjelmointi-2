/* Game15 (or puzzle 15) : Template code
 *
 * Class: Board
 *
 * Program author
 * Name: Antti-Jussi Isoviita
 * Student number: 283435
 * UserID: isoviita
 * E-Mail: antti-jussi.isoviita@tuni.fi
 *
 * Notes:
 *
 * */

#include "board.hh"
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <string>

using namespace std;

const int EMPTY = 16;
const unsigned int PRINT_WIDTH = 5;

Board::Board(vector< unsigned int>& numbers, bool suffle, int seed)
{
    if (suffle)
    {
    Board::my_shuffle(numbers, seed);
    }
    grid_ = Board::D1_to_D2(numbers);
}

vector<vector<unsigned int>> Board::D1_to_D2(vector <unsigned int> numbers)const
{
vector<vector<unsigned int> > D2;
vector<unsigned int> tempvector;
int i = 0;
for (auto number : numbers)
{
    tempvector.push_back(number);
    i++;
    if (i == 4)
    {
        D2.push_back(tempvector);
        i = 0;
        tempvector = {};
    }
}
return D2;
}

void Board::print()
{
    for(unsigned int x = 0; x < SIZE; ++x)
    {
        cout << string(PRINT_WIDTH * SIZE + 1, '-') << endl;
        for(unsigned int y = 0; y < SIZE; ++y)
        {
            cout << "|" << setw(PRINT_WIDTH - 1);
            if(grid_.at(x).at(y) != EMPTY)
            {
                cout << grid_.at(x).at(y);
            }
            else
            {
                cout << ".";
            }
        }
        cout << "|" << endl;
    }
    cout << string(PRINT_WIDTH * SIZE + 1, '-') << endl;
}

void Board::my_shuffle(vector<unsigned int> &numbers, int seed)
{
    default_random_engine randomEng(seed);
    uniform_int_distribution<int> distr(0, numbers.size() - 1);
    for(unsigned int i = 0; i < numbers.size(); ++i)
    {
        unsigned int random_index = distr(randomEng);
        unsigned int temp = numbers.at(i);
        numbers.at(i) = numbers.at(random_index);
        numbers.at(random_index) = temp;
    }
}


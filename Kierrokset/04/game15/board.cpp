/* Game15 (or puzzle 15) : Template code
 *
 * Class: Board
 *
 * Program author
 * Name: Antti-Jussi Isoviita
 * Student number: 283435
 * UserID: isoviita
 * E-Mail: antti-jussi.isoviita@tuni.fi
 */

#include "board.hh"
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

const int EMPTY = 16;
const unsigned int PRINT_WIDTH = 5;

Board::Board(vector< unsigned int>& numbers, bool suffle, int seed)
/* Turns one dimensional vector into 2 dimensional vector and
 * shuffles the vector if the second parameter is true
 */
{
    if (suffle)
    {
    Board::my_shuffle(numbers, seed);
    }
    grid_ = Board::D1_to_D2(numbers);
}

vector<vector<unsigned int>> Board::D1_to_D2(vector <unsigned int> numbers)const
/* Turns one dimensional vector into vector with two dimensions
 * return vector with 4 vectors in it
 */
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

void Board::move(string direction, int index)
/* Direction = where number moves, index = the value of the number being moved.
 * Method locates wanted number and calls another method to move it
 */
{
    unsigned int y = 0;
    unsigned int x = 0;
    bool spot = false;
    for (auto item: grid_)
    {
        for(unsigned int number : item)
        {
            if (index == (int) number)
            {
                spot = true;
                break;
            }
            x++;
        }
        if (spot)
            break;

    x = 0;
    y++;
    }
    if (Board::is_move_allowed(y, x, direction))
    {
        Board::swap(y, x, direction, index);
    }
    else
        cout << "Impossible direction: " << direction << endl;
}

void Board::swap(unsigned int y, unsigned int x, string direction, int index)
/* Method takes y and x coordinates, wanted direction and numeric value of number as
 * parameters. Swaps the location of two numbers.
 */
{
    if ( direction == "a" )
    {
           grid_[y][x-1] = index;
           grid_[y][x] = EMPTY;
    }

    if ( direction == "d" )
    {
           grid_[y][x+1] = index;
           grid_[y][x] = EMPTY;
    }

   if ( direction == "w" )
    {
           grid_[y-1][x] = index;
           grid_[y][x] = EMPTY;
    }

    if ( direction == "s" )
    {
           grid_[y+1][x] = index;
           grid_[y][x] = EMPTY;
    }
}

bool Board::is_move_allowed(unsigned int y, unsigned int x, string direction)
// Checks if the move is allowed. Return true if move is allowed, false if not
{
    if (direction == "a")
    {
        if (x == 0) return false;
        return (grid_[y][x-1] == EMPTY);
    }
    else if (direction == "d")
    {
        if ( x == 4 ) return false;
        return (grid_[y][x+1] == EMPTY);

    }
    else if (direction == "w")
    {
        if (y == 0) return false;
        return (grid_[y-1][x] == EMPTY);

    }
    else
    {
        if (y == 4) return false;
        return (grid_[y+1][x] == EMPTY);
    }
}

bool Board::solvable()
/* Checks if board is solvable or not
 * Returns true if board is solvable, false if not
 */
{
 unsigned int y = 0;
 unsigned int x = 0;
 int inversions = 0;
 vector < vector<unsigned int> > original = grid_;
 bool spot = false;
 // To get empty spot to the bottom row
 for (auto item : grid_)
 {
     for(unsigned int number : item)
     {
         if (EMPTY == (int) number)
         {
             spot = true;
             break;
         }
         x++;
     }
     if (spot) break;
     x=0;
     y++;
 }
 while (y < 3)
 {
     Board::swap(y+1, x, "w", grid_[y+1][x]);
     y++;
 }

 // To check if the board is solvable
 for ( unsigned int D1 = 0; D1 < 4; D1++)
 {
     for ( unsigned int D2 = 0; D2 < 4; D2++)
     {
         for ( unsigned int D3 = 0 + D1; D3 < 4; D3++)
         {
             for ( unsigned int D4 = 0; D4 < 4; D4++)
             {
                 if (D3 == D1 and D2 > D4)
                 {
                     D4 = D2;
                 }
                 if (grid_.at(D1).at(D2) > grid_.at(D3).at(D4) and
                     grid_.at(D1).at(D2) != 16 and
                     grid_.at(D3).at(D4))
                     inversions += 1;
             }
         }
     }
 }
 if (inversions % 2 == 0)
 {
     grid_ = original;
     return true;
 }
 else return false;
}

bool Board::is_won()
// Checks if the numbers are in correct order to win the game
{
    unsigned int i = 1;
    for(auto item : grid_)
    {
        for(unsigned int number : item)
        {
            if (i != number)
                return false;
        i++;
        }
    }
    return true;
}

void Board::print()
// Prints the gameboard
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
// Randomizes the number order in vector
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


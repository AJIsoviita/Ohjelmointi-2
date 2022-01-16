/* Game15 (or puzzle 15) : Template code
 *
 * Class: Board
 *  Describes a two-dimensional grid for puzzle 15 with necessary functions.
 *
 * Program author
 * Name: Antti-Jussi Isoviita
 * Student number: 283435
 * UserID: isoviita
 * E-Mail: antti-jussi.isoviita@tuni.fi
 * */

#ifndef BOARD_HH
#define BOARD_HH
#include <vector>
#include <string>
#include <time.h>

using namespace std;

const int SIZE = 4;

class Board
{
public:
    // Constructor
    Board(vector<unsigned int>& numbers, bool suffle = false, int seed = time(NULL));

    // Prints the game grid
    void print();

    // Checks if the game is solveable
    bool solvable();

    // Checks if the game has been won
    bool is_won();

    // Checks if the move is allowed and performs it if it is allowed
    void move(string direction, int index);

private:
    // Shuffles the numbers vector by using seed as a seed value
    void my_shuffle(vector<unsigned int>& numbers, int seed);

    // Game grid for the 15 puzzle
    vector< vector<unsigned int> > grid_;

    // Turns 1 dimensional vector into 2 dimensional
    vector< vector<unsigned int> > D1_to_D2(vector <unsigned int> numbers) const;

    // Part of method move. Checks if the move is possible
    bool is_move_allowed(unsigned int y, unsigned int x, string direction);

    // Performs the move
    void swap(unsigned int y, unsigned int x, string direction, int index);
};

#endif // BOARD_HH

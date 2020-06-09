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
 * Notes:
 *
 * */

#ifndef BOARD_HH
#define BOARD_HH
#include <vector>
#include <string>

using namespace std;

const int SIZE = 4;

class Board
{
public:
    // Constructor
    Board(vector<unsigned int>& numbers, bool suffle = false, int seed = time(NULL));

    // Initializes the grid randomly based on the seed
    void init(int seed);

    // Initialized the grid with the values of numbers vector
    // Returns false, if the given vector does not contain all the numbers [1..16],
    // otherwise returns true
    bool init(const vector<unsigned int>& numbers);

    // Prints the game grid
    void print();

    // Checks if the game is solveable
    bool solveable();

    // Checks if the game has been won
    bool won();

    // Checks if the move is allowed and performs it if it is allowed
    void move();

private:
    // Shuffles the numbers vector by using seed as a seed value
    void my_shuffle(vector<unsigned int>& numbers, int seed);

    // Game grid for the 15 puzzle
    vector< vector<unsigned int> > grid_;

    // Turns 1 dimensional vector into 2 dimensional
    vector< vector<unsigned int> > D1_to_D2(vector <unsigned int> numbers) const;

    bool is_move_allowed();

    void swap();
};

#endif // BOARD_HH

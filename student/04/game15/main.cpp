/* Game15 (or puzzle 15) : Template code
 *
 * Desc:
 *  This program generates a 15 puzzle. The board is SIZE x SIZE,
 * (original was 4x4) and every round the player chooses a direction and
 * a number tile, making the given tile to be moved to the given direction.
 *  Game will end when the numbers 1-15 (1-16) are in the ascending order,
 * starting from top left and proceeding row by row.
 * Empty space is represented by the number 16 in the code (constant EMPTY)
 * and by dot when printing the game board.
 *
 * Program author
 * Name: Antti-Jussi Isoviita
 * Student number: 283435
 * UserID: isoviita
 * E-Mail: antti-jussi.isoviita@tuni.fi
 *
 * Notes about the program and it's implementation:
 *
 * */

#include "board.hh"
#include <iostream>
#include <algorithm>

using namespace std;
    
Board randominit()
{
    vector<unsigned int> numbers {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    string random = "";
    string seed = "";

    cout << "Give a seed value or an empty line: ";
    getline(cin, seed);
    if (seed != "")
    {
        Board game = Board(numbers, true, stoi(seed));
        return game;
    }
    else
    {
        Board game = Board(numbers, true);
        return game;
    }
}

bool choseninit(vector<unsigned int>& numbers)
{
    unsigned int item;

    cout << "Enter the numbers 1-16 in a desired order (16 means empty):" << endl;
    for (int i = 0; i < 16; i++)
    {
        cin >> item;
        numbers.push_back(item);
    }

    vector <int> line {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int missing_number = 0;

    for (int number : line)
    {
     if(count(numbers.begin(), numbers.end(), number));
     else missing_number = number;
    }

    if (missing_number != 0)
    {
        cout << "Number " << missing_number << " is missing" << endl;
        return false;
    }
    return true;
}

Board start_board(vector<unsigned int> numbers)
{
    Board game = Board(numbers, false);
    return game;
}

int main()
{
    vector<unsigned int> numbers = {};
    bool containsall = true;
    string input = "";
    cout << "Random initialization (y/n): ";
    getline(cin, input);

    if (input == "y" or input == "Y")
    {
        Board game = randominit();
    }

    else if (input == "n" or input == "N")
    {
        containsall = choseninit(numbers);
        if (!containsall)
            return EXIT_FAILURE;
        else
        {
            Board game = start_board(numbers);
            game.print();
        }

    }

    else
    {
        cout << "Unknown choice: " << input << endl;
        return main();
    }
    return EXIT_SUCCESS;
}

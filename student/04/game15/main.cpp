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
 * */

#include "board.hh"
#include <iostream>
#include <algorithm>

using namespace std;
    
Board randominit()
/* Prompts user to give seed value and returns created Board class with
 * given seed value. If seed value is not given, function returns Board class
 * with a random seed.
 */
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
/* Takes numbers 1-16 as user input. If user input value is other than 1-16
 * function returns false. Otherwise function returns true
 */
{
    unsigned int item;

    cout << "Enter the numbers 1-16 in a desired order (16 means empty):" << endl;
    for (int i = 0; i < 16; i++)
    {
        cin >> item;
        numbers.push_back(item);
    }
    cin.ignore();
    vector <unsigned int> checknumbers;
    checknumbers = numbers;
    unsigned int valuecheck = 1;


    // Checks that input numbers include 1-16
    sort(checknumbers.begin(), checknumbers.end());
    for (unsigned int i : checknumbers)
    {
        if (i != valuecheck)
        {
            cout << "Number " << valuecheck << " is missing" << endl;
            return false;
        }
        valuecheck++;
    }
    return true;
}

Board start_board(vector<unsigned int> numbers)
// Generates game board with user given values. Returns Board class
{
    Board game = Board(numbers, false);
    return game;
}

void control(Board game)
// Takes user input and acts upon it
{
    if( game.solvable() )
    {
        cout << "Game is solvable: Go ahead!" << endl;
        while (true)
        {
            game.print();
            if ( game.is_won() )
            {
                cout << "You won!" << endl;
                break;
            }

            string input;
            string index;
            cout << "Dir (command, number): ";
            getline(cin, input);
            string direction = input.substr(0, input.find(" "));

            if (direction == "a" or
                direction == "d" or
                direction == "w" or
                direction == "s")
            {
                index = input.substr(2);
                if(stoi(index) <= 15 and 1 <= stoi(index))
                    game.move(direction, stoi(index));
                else
                    cout << "Invalid number: " << index << endl;
            }

            else if (direction == "q")
                break;

            else
                cout << "Unknown command: " << direction << endl;

            if (game.is_won())
            {
                game.print();
                cout << "You won!" << endl;
                break;
            }
        }
    }
    else
        cout << "Game is not solvable. What a pity." << endl;

}

int main()
/* Prompts user to choose board type
 * returns EXIT_FAILURE if user gives wrong value in choseinit
 * returns EXIT_SUCCESS if game ends
 */
{
    vector<unsigned int> numbers = {};
    bool containsall = true;
    string input = "";
    cout << "Random initialization (y/n): ";
    getline(cin, input);

    if (input == "y" or input == "Y")
    {
        Board game = randominit();
        control(game);
    }

    else if (input == "n" or input == "N")
    {
        containsall = choseninit(numbers);
        if (!containsall)
            return EXIT_FAILURE;

        else
        {
            Board game = start_board(numbers);
            control(game);
        }

    }

    else
    {
        cout << "Unknown choice: " << input << endl;
        return main();
    }
    return EXIT_SUCCESS;
}

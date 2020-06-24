#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdexcept>

using namespace std;

struct Book{string title; string author; int reservations;};

bool fieldcheck(ifstream& file)
{
    string row = "";
    string delimiter = ";";

    while(getline(file, row))
    {
        int count = 0;
        while(row.find(delimiter) != string::npos)
        {
            string new_part = row.substr(0, row.find(delimiter));
            row = row.substr(row.find(delimiter)+1, row.size());
            if(not (new_part.empty() or new_part == ""))
                count++;
        }

        if (not(row.empty() or row == ""))
        {
            if(row == "on-the-shelf")
                count++;

            else
            {
                try
                {
                    stoi(row);
                    count++;
                }

                catch(const invalid_argument&)
                {
                    return false;
                }
            }
        }
        if (count != 4)
            return false;
    }
    return true;
}

vector<string> split(string& row)
{
    vector<string> result;
    string delimiter = ";";
        while(row.find(delimiter) != string::npos)
        {
            string new_part = row.substr(0, row.find(delimiter));
            row = row.substr(row.find(delimiter)+1, row.size());
            if(not (new_part.empty()))
            {
                result.push_back(new_part);
            }
        }
        if(not (row.empty()))
        {
            result.push_back(row);
        }
        return result;
    }

int main()
{
    unordered_map <string, vector<Book>> library;

    cout << "Input file: ";
    string inputf = "";
    getline(cin, inputf);

    ifstream input(inputf);
    if(!input)
    {
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }
    else if(!fieldcheck(input))
    {
        cout << "Error: empty field " << endl;
        return EXIT_FAILURE;
    }
    while(true)
    {
        string prompt;
        cout << "> ";
        getline(cin, prompt);
        vector<string> parts = split(prompt);
        string command = parts.at(0);

        if (command == "libraries")
            continue;

        else if(command == "material")
            if(parts.size != 2)
                continue;
            else
                cout << "Error: error in command "<< command;

        else if(command == "books")
            if(parts.size != 3)
                continue;
            else
                cout << "Error: error in command "<< command;

        else if(command == "reservable")
            if(parts.size != 2)
                continue;
            else
                cout << "Error: error in command "<< command;

        else if(command == "loanable")
            continue;

        else if(command == "quit")
            return EXIT_SUCCESS;
        else
            cout << "Error: Unknown command: " << command << endl;
    }
    return 0;


    // collector(library, input);
    cout << "good" << endl;
}

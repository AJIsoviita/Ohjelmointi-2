#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct Book{string title; string author; int reservations;};
using Map = map <string, vector<Book> >;

vector<string> split(const string& s, const char delimiter, bool ignore_empty = false)
{
    vector<string> result;
    string tmp = s;

    while(tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

map<string, vector<Book> > readfile(ifstream& file)
{
    string row;
    Map library;
    Map failure;

    while (getline(file, row))
    {
        vector<string> splitrow = split(row, ';', true);
        int amount;

        if(splitrow.size() == 4)
        {
            istringstream(splitrow[3]) >> amount;
            Book info = {splitrow[2], splitrow[1], amount};

            Map::iterator iter = library.find(splitrow[0]);
            if (iter == library.end() )
                library.insert({splitrow[0], {info}});
            else
                library.at(splitrow[0]).push_back(info);
        }
        else
        {
            cout <<"Error: empty field" << endl;
            return failure;
        }
    }
    return library;
}

void print(Map library)
{
    for (auto i : library)
        cout << i.first << endl;
}

int menu(Map library)
{
    while(true)
    {
        string prompt;
        cout << "> ";
        getline(cin, prompt);
        vector<string> parts = split(prompt, ';', true);
        string command = parts.at(0);

        if (command == "libraries")
            print(library);

        else if(command == "material")
        {
            if(parts.size() != 2)
                continue;
            else
                cout << "Error: error in command "<< command << endl;;
        }
        else if(command == "books")
        {
            if(parts.size() != 3)
                continue;
            else
                cout << "Error: error in command "<< command << endl;
        }
        else if(command == "reservable")
        {
            if(parts.size() != 2)
                continue;
            else
                cout << "Error: error in command "<< command << endl;
        }
        else if(command == "loanable")
            continue;

        else if(command == "quit")
            return EXIT_SUCCESS;
        else
            cout << "Error: Unknown command: " << command << endl;
    }
    return 0;
}


int main()
{
    map <string, vector<Book>> library;

    cout << "Input file: ";
    string inputf = "";
    getline(cin, inputf);

    ifstream input(inputf);
    if(!input)
    {
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }
    else
    {
        library = readfile(input);

        if(library.empty())
            return EXIT_FAILURE;
    }

    menu(library);


    return EXIT_SUCCESS;
}

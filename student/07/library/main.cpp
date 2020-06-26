/*
 * Kirjasto Projekti
 * Isoviita Antti-Jussi
 * antti-jussi.isoviita@tuni.fi 283435
 *
 * Description;
 * Program reads input from a given file (csv-format) and
 * creates datastructure from it (Place, Book(title, author, reservation).
 *
*/
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
//Splits a row of strings into a vector
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
//Reads given input file and creates datastructure if possible
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

void libraries(Map library)
// Couts available libraries
{
    for (auto i : library)
        cout << i.first << endl;
}

void material(Map library, string place)
// Couts available books at requested location (author:book)
{
    if(library.find(place) != library.end())
    {
        vector<pair<string, string>> list;

        for(auto i : library.at(place))
        {
            pair<string, string> ab;
            ab.first = i.author;
            ab.second = i.title;
            list.push_back(ab);
        }
        sort(list.begin(), list.end());
        for(auto a : list)
            cout << a.first << ": " << a.second << endl;
    }
    else
        cout << "Error: unknown library name" << endl;
}

void books(Map library, string place, string author)
// Couts available books at requested location, author and reservation queue
{
    int count = 0;
    for(auto i : library.at(place))
    {
        if(i.author == author)
        {
            count++;
            if(i.reservations == 0)
                cout<< i.title << " --- on the shelf" <<endl;
            else
                cout<< i.title << " --- " << i.reservations << " reservations" <<endl;
        }
    }
    if (count == 0)
        cout << "Error: unknown author" << endl;
}

bool sortByVal(const pair<string, int> &a, const pair<string, int> &b)
// Sorts parameters by value
{
    return(a.second < b.second);
}

void reservable(Map library, string book)
// Couts shortest queue and location for requested book
{
    Map::iterator iter = library.begin();
    vector< pair<string, int> > list;
    pair<string, int> pr;
    while(iter != library.end())
    {
        string place = iter->first;
        for(auto b : library.at(place))
        {
            if(b.title == book)
            {

                pr.first = place;
                pr.second = b.reservations;
                list.push_back(pr);
            }
        }
        iter++;
    }

    sort(list.begin(), list.end(), sortByVal);

    if(list.empty())
        cout << "Book is not a library book." << endl;

    else if(list[0].second > 99)
        cout << "The book is not reservable from any library." << endl;
    else
    {
        for(auto v : list)
        {
            if (list[0].second < v.second)
                list.pop_back();
        }
        if(list[0].second == 0)
        {
            cout<< "on the shelf" << endl;
            for (auto i : list)
                cout << "--- " << i.first << endl;
        }
        else
        {
            cout<< list[0].second <<" reservations" << endl;
            for (auto i : list)
                cout << "--- " << i.first << endl;
        }
    }
}

void loanable(Map library)
// Couts all instantly available books at all libraries
{
    Map::iterator iter = library.begin();
    vector< pair<string, string> > list;
    pair<string, string> ab;

    while(iter != library.end())
    {
        string place = iter->first;
        for(auto b : library.at(place))
        {
            if(b.reservations == 0)
            {
                ab.first = b.author;
                ab.second = b.title;
                list.push_back(ab);
            }
        }
        iter++;
    }
    sort(list.begin(), list.end());
    for(auto pair : list)
        cout << pair.first << ": " << pair.second << endl;
}

int menu(Map library)
// User interface that prompts user for commands
{
    while(true)
    {
        string prompt;
        cout << "> ";
        getline(cin, prompt);
        vector<string> parts = split(prompt, ' ', true);
        string command = parts[0];

        if (command == "libraries")
            libraries(library);

        else if(command == "material")
        {
            if(parts.size() == 2)
               material(library, parts[1]);
            else
                cout << "Error: error in command "<< command << endl;;
        }
        else if(command == "books")
        {
            if(parts.size() != 3)
                cout << "Error: error in command "<< command << endl;
            else
            {
                if(library.find(parts[1]) != library.end())
                {
                    books(library, parts[1], parts[2]);
                }
                else
                    cout << "Error: unknown library name " << endl;

            }
        }
        else if(command == "reservable")
        {
            if(parts.size() > 1)
            {
                unsigned int i = 1;
                string book;

                while(i < parts.size())
                {
                    book += parts[i] + " ";
                    i++;
                }
                if (parts[1][0] == '"')
                    book = book.substr(1, book.size() - 3);
                else
                    book = book.substr(0, book.size() - 1);

                reservable(library, book);


            }
            else
                cout << "Error: error in command "<< command << endl;
        }
        else if(command == "loanable")
            loanable(library);

        else if(command == "quit")
            return EXIT_SUCCESS;
        else
            cout << "Error: Unknown command: " << command << endl;
    }
    return 0;
}

int main()
// Checks given input file and starts user interface
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

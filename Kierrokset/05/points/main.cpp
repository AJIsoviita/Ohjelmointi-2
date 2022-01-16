#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>


using namespace std;

int main()
{
    cout << "Input file: ";
    string input;
    string line;
    string name;
    int score;
    map<string, int> points;

    getline(cin, input);

    ifstream finput(input);
    if (!finput)
    {
        cout << "Error! The file " << input << " cannot be opened." << endl;
        return EXIT_FAILURE;
    }
    else
    {
        while( getline(finput, line) )
        {
           stringstream row;
           row << line;
           getline(row, name, ':');
           int pos = line.find(":");
           line.erase(0, pos + 1);
           score = stoi(line);

           if (points.find(name) != points.end())
               points.at(name) += score;
           else
               points.insert({name, score});
        }

        cout << "Final scores: " << endl;
        for(auto pair : points)
        {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
}

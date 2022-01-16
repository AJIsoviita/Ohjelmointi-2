#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


// TODO: Implement split function here
// Do not change main function
vector<string> split(string input, char separator, bool value = false)
{
    stringstream line(input);
    vector<string> list;
    string letter;
    string part;
    char n = 0;
    if (value == false)
    {

        for (char & c : input)
        {
            if (c != separator)
                part += c;
            else
            {
                list.push_back(part);
                part = "";
            }
            if ((n && c) == separator)
                list.push_back(" ");
            n = c;
        }
        list.push_back(part);
    }
    else
    {
    while(getline(line, letter, separator))
    {
    list.push_back(letter);
    if (letter == "")
        list.pop_back();
    }
    }
    return list;
}



int main()
{
    string line = "";
    cout << "Enter a string: ";
    getline(cin, line);
    cout << "Enter the separator character: ";
    char separator = getchar();

    vector< string > parts  = split(line, separator);
    cout << "Splitted string including empty parts: " << endl;
    for( auto part : parts ) {
        cout << part << endl;
    }

    vector< string > parts_no_empty  = split(line, separator, true);
    cout << "Splitted string ignoring empty parts: " << endl;
    for( auto part : parts_no_empty ) {
        cout << part << endl;
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


vector<string> split(const string& s, const char delimiter, bool ignore_empty = false){
    vector<string> result;
    string tmp = s;

    while(tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());

        if(not (ignore_empty and new_part.empty()))
            result.push_back(new_part);
    }

    if(not (ignore_empty and tmp.empty()))
        result.push_back(tmp);

    return result;
}

void print(unordered_map<string, vector<string> > names, string name, int i)
{
    for(int a = 0; i > a; ++a)
        cout << "..";

    cout << name << endl;
    i++;

    for(int b=0; b<(int) names.at(name).size(); ++b)
        print(names, names.at(name)[b], i);
}

int count(unordered_map<string, vector<string> > names, string name, int i)
{
    for(int a = 0; a < (int)names.at(name).size(); a++)
        i = count(names, names.at(name)[a], ++i);
    return i;
}

vector<int> depth(unordered_map<string, vector<string> > names, string name, int i, vector<int> max)
{
    ++i;
    for(int a=0; a <(int) names.at(name).size(); ++a)
    {
        max =  depth(names, names.at(name)[a], i , max);
    }
    max.push_back(i);
    return max;
}

int main()
{
    unordered_map <string, vector<string> > library;

    while(true){
        string line;
        cout << "> ";
        getline(cin, line);
        vector<string> parts = split(line, ' ', true);

        string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id1 = parts.at(1);
            string id2 = parts.at(2);

            if(library.find(id1) != library.end())
            {
                library[id1].push_back(id2);
                library.insert( {id2, {} });
            }
            else
            {
                library.insert( {id1, {id2} });
                library.insert( {id2, {} });
            }

        }

        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }

            string id = parts.at(1);

            print(library, id, 0);
    }

        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            cout << count(library, id, 0) << endl;
        }

        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                cout << "Erroneous parameters!" << endl << HELP_TEXT;
                continue;
            }
            string id = parts.at(1);

            vector<int> max;
            max = depth(library, id, 0, max);
            sort(max.begin(), max.end());
            cout << max.at(max.size() - 1) << endl;

        }

        else if(command == "Q" or command == "q")
           return EXIT_SUCCESS;

        else
            cout << "Erroneous command!" << endl << HELP_TEXT;
    }
}

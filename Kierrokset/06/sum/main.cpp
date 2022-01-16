#include <iostream>
#include <string>
#include <vector>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

using namespace  std;

vector<string> split(const string& s, const char delimiter, bool ignore_empty = false){
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

int sum_recursive(vector<int> v){
    RECURSIVE_FUNC
    // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
    // ------------
    int sum = v.at(v.size() - 1);

    if (v.size() > 1)
    {
        v.pop_back();
        if(v.size() > 1)
            sum += sum_recursive(v);
        else
        {
            sum += v.at(0);
            return sum;
        }
    }
    return sum;
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    cout << "Enter integers separated by spaces: ";
    string line;
    getline(cin, line);
    vector<string> strings = split(line, ' ', true);
    vector<int> integers;
    for(auto s : strings){
        integers.push_back(stoi(s));
    }

    cout << "Sum: " << sum_recursive(integers) << endl;
}
#endif

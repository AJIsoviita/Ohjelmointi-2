#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Input file: ";
    string input = "";
    getline(cin, input);
    cout << "Output file: ";
    string output = "";
    getline(cin, output);

    ifstream input_file(input);
    ofstream output_file(output);

    if (not input_file)
    {
        cout << "Error! The file "<< input << " cannot be opened." << endl;
        exit(1);
    }

    else
    {
        string row = "";
        int number = 1;
        while( getline(input_file, row))
        {
            output_file << number << " " << row << endl;
            number++;
        }
        input_file.close();
        output_file.close();
    }
}

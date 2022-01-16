#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Input file: ";
    string input;
    int i = 1;

    map <string, vector<int> > library;

    getline(cin, input);
    ifstream finput(input);

    if (!finput)
    {
        cout << "Error! The file " << input << " cannot be opened.";
        return EXIT_FAILURE;
    }
    else
    {
        string rivi;
        while(getline(finput, rivi))
        {
            istringstream iss(rivi);
            string word;
            while(iss >> word) {
                if ( library.find(word) != library.end()){
                    library[word].push_back(i);
                }
                else{
                    library[word] = {i};
                }

            }

            i++;
        }
          for (auto pair: library){
              vector<int> dab = pair.second;
              dab.erase(unique(dab.begin(), dab.end()), dab.end());
              cout << pair.first << " " << dab.size() << ": ";

              for (int i = 0; i < (int) dab.size(); i++){
                  if (i >= 1){
                      cout << ", ";
                  }
                  cout << dab.at(i);
              }
              cout << endl;

              }

          return EXIT_SUCCESS;
    }
}


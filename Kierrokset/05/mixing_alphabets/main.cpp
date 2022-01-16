#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    minstd_rand gen;

    cout << "Enter some text. Quit by entering the word \"END\"." << endl;
    string word;
    string sana;
    string first;
    string last;
    int len;

    while (cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        else
        {
            len = word.length();
            if(len > 3)
            {
               first = "";
               last = "";
               first = word.at(0);
               last = word.at(len - 1);
               sana = word.substr(1, len -2);
               shuffle(sana.begin(), sana.end(), gen);
               word = sana;
               cout << first + word + last << endl;
            }
            else
                cout << word << endl;
        }

    }
}

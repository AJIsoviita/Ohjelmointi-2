#include <iostream>

using namespace std;

int main()
{
    cout << "How many numbers would you like to have? ";
    int number = 0;
    cin >> number;
    int n = 1;
    while (n != number)
    {
        if (n % 3 == 0)
        {
            if (n % 7 == 0)
                cout << "zip boing" << endl;
            else
                cout << "zip" << endl;
        }

        else if (n % 7 == 0)
        {
            if (n % 3 == 0)
                cout << "zip boing" << endl;
            else
                cout << "boing" << endl;
        }

        else
        {
            cout << n << endl;
        }

        ++n;

    }
}

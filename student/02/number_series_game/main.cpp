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
            cout << "zip" << endl;

        }
        else
        {
            cout << n << endl;
        }
        ++n;

    }
}

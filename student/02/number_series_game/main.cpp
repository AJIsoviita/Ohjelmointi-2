#include <iostream>

using namespace std;

int main()
{
    cout << "How many numbers would you like to have? ";
    int number = 0;
    cin >> number;
    int n = 0;
    while (n != number)
    {
        cout << ++n << endl;
    }
}

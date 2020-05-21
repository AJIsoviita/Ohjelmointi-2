#include <iostream>
using namespace std;

// Write here a function counting the mean value

int main()
{
    cout << "From how many integer numbers you want to count the mean value? ";
    int n = 1;
    int amount = 0;
    int number = 0;
    float sum = 0;

    cin >> amount;
    if (amount < 1)
        cout << "Cannot count mean value from " << amount << " numbers" << endl;
    else
    {
        while (n != (amount+1))
        {
            cout << "Input " << n << ". number: ";
            cin >> number;
            sum += number;
            ++n;
        }
        cout << "Mean value of the given numbers is " << (sum / amount) << endl;
    }
}

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int n1 = 0;
    int p = 0;
    int p1 = 0;
    int np = 0;
    int factorialn = 1;
    int factorialnp = 1;
    int factorialp = 1;
    int sum = 0;

    cout << "Enter the total number of lottery balls: ";
    cin >> n;
    cout << "Enter the number of drawn balls: ";
    cin >> p;
    n1 = n;
    p1 = p;
    np = n-p;

    if (n < 0)
    {
        cout << "The number of balls must be a positive number." << endl;
    }

    else if (n < p)
    {
        cout << "The maximum number of drawn balls is the"
                " total amount of balls." << endl;
    }

    if(n == 20 && p == 4)
    {
        cout << "The probability of guessing all "
                "4 balls correctly is 1/4845" << endl;
    }

    else
    {
        while (n1 > 0)
        {
            factorialn *= n1;
            n1 -= 1;
        }
        while (p1 > 0)
        {
            factorialp *= p1;
            p1 -= 1;
        }
        while(np > 0)
        {
            factorialnp *= np;
            np -= 1;
        }
        sum = factorialn/(factorialnp * factorialp);
        cout << "The probability of guessing all " << p <<
                " balls correctly is 1/" << sum << endl;
    }
}

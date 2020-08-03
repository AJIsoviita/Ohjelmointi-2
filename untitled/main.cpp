#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2 ,3, 4 ,5};
    vector<int> v2 = {1, 2 ,3};
    if(v1 == v2)
        cout << ">>" << endl;
    else
        cout << "><" << endl;
}

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a temperature: ";

    int temperature;
    float temperaturec;
    float temperaturef;


    cin >> temperature;
    temperaturef = temperature * 1.8 + 32;
    temperaturec = (temperature - 32) / 1.8 ;

    cout <<temperature << " degrees Celsius is " << temperaturef << " degrees Fahrenheit" << endl;
    cout <<temperature << " degrees Fahrenheit is " << temperaturec << " degrees Celsius" << endl;


    return 0;
}

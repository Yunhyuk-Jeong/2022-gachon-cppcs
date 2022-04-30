//* 202131230 정윤혁 2022.04.16

#include <iostream>

using namespace std;

//? INPUT : 22 / 5
//? INPUT : 5 / 25
//? INPUT : 5 / 28

int main()
{
    int base, exponent;
    unsigned long int power, temp;
    bool overflow;

    do
    {
        cout << "Enter a non-negative integer value for b : ";
        cin >> base;
    } while (base < 0);

    do
    {
        cout << "Enter a non-negative integer value for n : ";
        cin >> exponent;
    } while (exponent < 0);

    power = 1;
    temp = power;
    overflow = false;

    for (int i = 1; (i <= exponent) && (!overflow); i++)
    {
        power *= base;
        if (power / base != temp)
            overflow = true;
        temp = power;
    }

    if (overflow)
        cout << "Overflow occurred! Try again with smaller b or n.";
    else
        cout << base << "^" << exponent << " = " << power;

    return 0;
}
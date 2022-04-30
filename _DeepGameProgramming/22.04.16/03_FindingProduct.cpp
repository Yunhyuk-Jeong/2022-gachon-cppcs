//* 202131230 정윤혁 2022.04.16

#include <iomanip>
#include <iostream>

using namespace std;

//? INPUT : 6 / 12 / 13.45 / 15 / 22.10 / 11.34 / 14
//@ OUTPUT : 87.89 / 8494310.92

int main()
{
    int size;
    long double number;
    long double sum, product;

    do
    {
        cout << "Enter a non-negative integer value for size : ";
        cin >> size;
    } while (size < 0);

    sum = 0;
    product = 1;

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter the next integer : ";
        cin >> number;
        sum += number;
        product *= number;
    }

    cout << fixed << setprecision(2);
    cout << "sum = " << sum << endl;
    cout << "product = " << product;

    return 0;
}
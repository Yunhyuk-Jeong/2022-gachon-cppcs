//* 202131230 정윤혁 2022.04.16

#include <cmath>
#include <iostream>

using namespace std;

//? INPUT : 3 / 5 / 4
//? INPUT : 1 / 2 / 1
//? INPUT : 4 / -9 / 2

int main()
{
    int a, b, c;
    double term;

    cout << "Enter the value of coefficient a : ";
    cin >> a;

    cout << "Enter the value of coefficient b : ";
    cin >> b;

    cout << "Enter the value of coefficient c : ";
    cin >> c;

    term = pow(b, 2) - 4 * a * c;

    if (term < 0)
        cout << "There is no root!" << endl;
    else if (term == 0)
    {
        cout << "The two roots are equal." << endl;
        cout << "x1 = x2 = " << -b / (2 * a) << endl;
    }
    else
    {
        cout << "There are two distinct roots: " << endl;
        cout << "x1 = " << (b + sqrt(term)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(term)) / (2 * a) << endl;
    }

    return 0;
}
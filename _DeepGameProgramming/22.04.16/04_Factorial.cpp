//* 202131230 정윤혁 2022.04.09

#include <iostream>

using namespace std;

//? INPUT : 0 / 4 / 12 / 22 / 30

int main()
{
    int n;
    unsigned long long factorial;

    do
    {
        cout << "Enter the factorial size : ";
        cin >> n;
    } while (n < 0);

    factorial = 1;

    for (int i = 1; i < n + 1; i++)
    {
        factorial *= i;
    }

    cout << n << "! = " << factorial;

    return 0;
}
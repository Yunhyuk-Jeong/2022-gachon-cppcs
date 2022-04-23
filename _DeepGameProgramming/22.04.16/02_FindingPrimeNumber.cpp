//* 202131230 정윤혁 2022.04.09

#include <iostream>

using namespace std;

//? INPUT : 1 / 12 / 23 / 97

int main()
{
    int num;

    do
    {
        cout << "Enter a positive integer : ";
        cin >> num;
    } while (num <= 0);

    if (num == 1)
    {
        cout << "1 is not a composite nor a prime.";
        return 0;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << "is composite." << endl;
            cout << "The first divisor is " << i << endl;
            return 0;
        }
    }

    cout << num << " is a prime." << endl;

    return 0;
}
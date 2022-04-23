//* 202131230 정윤혁 2022.04.09

#include <iomanip>
#include <iostream>

using namespace std;

//? INPUT : 4
//? INPUT : 11 / 9

int main()
{
    int size;

    do
    {
        cout << "Enter table size (2 to 10) : ";
        cin >> size;
    } while (size < 2 || size > 10);

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    return 0;
}
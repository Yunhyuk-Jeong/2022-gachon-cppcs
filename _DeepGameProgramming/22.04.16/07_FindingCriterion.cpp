//* 202131230 정윤혁 2022.04.16

#include <iostream>

using namespace std;

//? INPUT : 5 / 12 / 32 / 28
//? INPUT : 5 / 6 / 12 / 15 / 17 / 22

int main()
{
    bool success;
    int size;
    int item;

    do
    {
        cout << "Enter the number of items in the list : ";
        cin >> size;
    } while (size < 0);

    for (int i = 0; (i < size) && (!success); i++)
    {
        cout << "Enter the next item : ";
        cin >> item;
        success = (item % 7 == 0);
    }
    if (success)
        cout << "The number " << item << " is divisible by 7." << endl;
    else
        cout << "None of the numbers is divisible by 7." << endl;

    return 0;
}
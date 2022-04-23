//* 202131230 정윤혁 2022.04.09

#include <iostream>
#include <limits>

using namespace std;

//? INPUT : 6 / 12 / -3 / 14 / 15 / 27 / -7
//? INPUT : 3 / 1 / 87 / 45

int main()
{
    int size;
    int number, smallest, largest;

    smallest = numeric_limits<int>::max();
    largest = numeric_limits<int>::min();

    do
    {
        cout << "Enter the size of the list (non-negative) : ";
        cin >> size;
    } while (size <= 0);

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter the next item : ";
        cin >> number;

        if (number < smallest)
            smallest = number;

        if (number > largest)
            largest = number;
    }

    cout << "The smallest item is : " << smallest << endl;
    cout << "The largest item is : " << largest << endl;

    return 0;
}
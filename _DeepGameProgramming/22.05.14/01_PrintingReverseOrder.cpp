//* 202131230 정윤혁 2022.05.14

#include <iostream>

using namespace std;

//?         ==INPUT01==
//?         Enter the size (1 to 10) : 10
//?         Enter 10 integer(s) : 2 3 4 5 6 7 8 9 10 11
//@         ==OUTPUT01==
//@         Integer(s) in reversed order : 11 10 9 8 7 6 5 4 3 2

//?         ==INPUT02==
//?         Enter the size (1 to 10) : 0
//?         Enter the size (1 to 10) : 11
//?         Enter the size (1 to 10) : 7
//?         Enter 10 integer(s) : 4 11 78 2 5 3 8 9 <- Last integer is ignored
//@         ==OUTPUT02==
//@         Integer(s) in reversed order : 8 3 5 2 78 11 4

int main()
{
    const int CAPACITY = 10;
    int numbers[CAPACITY];
    int size;

    do
    {
        cout << "Enter the size (1 and 10) : ";
        cin >> size;
    } while (size < 1 || size > CAPACITY);

    cout << "Enter " << size << " integer(s) : ";

    for (int i = 0; i < size; i++)
        cin >> numbers[i];

    cout << "Integer(s) in reversed order : ";

    for (int i = size - 1; i >= 0; i--)
        cout << numbers[i] << " ";

    return 0;
}
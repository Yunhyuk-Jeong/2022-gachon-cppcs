//* 202131230 정윤혁 2022.04.30

#include <iostream>

using namespace std;

//?     ==INPUT 01==
//?     56, 71
//@     ==OUTPUT 01==
//@     Larger : 71

//?     ==INPUT 02==
//?     -10, 8
//@     ==OUTPUT 02==
//@     Larger : 8

int larger(int first, int second)
{
    int max;

    if (first > second)
        max = first;
    else
        max = second;

    return max;
}

int main()
{
    int first, second;

    cout << "Enter the first number : ";
    cin >> first;
    cout << "Enter the second number : ";
    cin >> second;

    cout << "Larger : " << larger(first, second);

    return 0;
}
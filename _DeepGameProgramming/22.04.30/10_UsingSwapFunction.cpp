//* 202131230 정윤혁 2022.04.30

#include <iostream>

using namespace std;

//@     ==OUTPUT==
//@     Value of first in main : 20
//@     Value of second in main : 10

void swap(int &first, int &second)
{
    int temp = first;

    first = second;
    second = temp;

    return;
}

int main()
{
    int first = 10;
    int second = 20;

    swap(first, second);

    cout << "Value of first in main : " << first << endl;
    cout << "Value of second in main : " << second;

    return 0;
}
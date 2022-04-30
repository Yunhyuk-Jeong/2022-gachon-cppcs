//* 202131230 정윤혁 2022.04.30

#include <iostream>

using namespace std;

//@     ==OUTPUT==
//@     false
//@     true

bool isEven(int y)
{
    return ((y % 2) == 0);
}

int main()
{
    cout << boolalpha << isEven(5) << endl;
    cout << boolalpha << isEven(10);

    return 0;
}
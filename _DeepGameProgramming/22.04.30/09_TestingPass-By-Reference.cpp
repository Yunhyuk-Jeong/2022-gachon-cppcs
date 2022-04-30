//* 202131230 정윤혁 2022.04.30

#include <iostream>

using namespace std;

//@     ==OUTPUT==
//@     Value of y in fun : 11
//@     Value of x in main : 11

void fun(int &y)
{
    y++;
    cout << "Value of y in fun : " << y << endl;

    return;
}

int main()
{
    int x = 10;

    fun(x);

    cout << "Value of x in main : " << x << endl;

    return 0;
}
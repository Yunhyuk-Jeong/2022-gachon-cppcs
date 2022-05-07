//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         count = 1
//@         count = 2
//@         count = 3

void fun();

int main()
{
    fun();
    fun();
    fun();

    return 0;
}

void fun()
{
    static int count = 0; // explicit static variable
    count++;
    cout << "count = " << count << endl;
}
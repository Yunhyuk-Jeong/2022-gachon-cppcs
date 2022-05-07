//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         maximum (5, 7) : 7
//@         maximum (7, 9, 8) : 9
//@         maximum (14, 3, 12, 11) : 14

int max(int num1, int num2);
int max(int num1, int num2, int num3);
int max(int num1, int num2, int num3, int num4);

int main()
{
    cout << "maximum (5, 7) : " << max(5, 7) << endl;
    cout << "maximum (7, 9, 8) : " << max(7, 9, 8) << endl;
    cout << "maximum (14, 3, 12, 11) : " << max(14, 3, 12, 11);

    return 0;
}

int max(int num1, int num2)
{
    int larger;
    if (num1 >= num2)
        larger = num1;
    else
        larger = num2;

    return larger;
}

int max(int num1, int num2, int num3)
{
    return max(max(num1, num2), num3);
}

int max(int num1, int num2, int num3, int num4)
{
    return max(max(num1, num2, num3), num4);
}
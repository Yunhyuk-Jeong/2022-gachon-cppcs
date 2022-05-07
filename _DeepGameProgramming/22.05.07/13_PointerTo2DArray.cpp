//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         23

int main()
{
    int arr[2][3] = {{11, 12, 13}, {21, 22, 23}};
    int(*pp)[3] = arr;
    cout << pp[1][2] << endl;

    return 0;
}
//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         1, 1

int main()
{
    int arr[2] = {1, 2};
    int *p = arr;
    cout << *p << ", " << *arr << endl;

    return 0;
}
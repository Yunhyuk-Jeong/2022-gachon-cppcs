//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         1, 2

int main()
{
    int arr[2] = {1, 2};
    int(*p)[2] = &arr;
    cout << (*p)[0] << ", " << (*p)[1] << endl;

    return 0;
}
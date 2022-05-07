//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         24
//@         12
//@         4

int main()
{
    int arr[2][3];

    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << sizeof(arr[0][0]) << endl;

    return 0;
}
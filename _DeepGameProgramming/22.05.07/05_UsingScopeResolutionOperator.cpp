//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         Value of Global num : 5
//@         Value of Local num : 25

int num = 5;

int main()
{
    int num = 25;

    cout << "Value of Global num : " << ::num << endl;
    cout << "Value of Local num : " << num << endl;

    return 0;
}
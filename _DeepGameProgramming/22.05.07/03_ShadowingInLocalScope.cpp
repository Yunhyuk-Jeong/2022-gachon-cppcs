//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         5
//@         3
//@         5

int main()
{
    int sum = 5;

    cout << sum << endl;
    {
        int sum = 3;
        cout << sum << endl;
    }
    cout << sum << endl;

    return 0;
}
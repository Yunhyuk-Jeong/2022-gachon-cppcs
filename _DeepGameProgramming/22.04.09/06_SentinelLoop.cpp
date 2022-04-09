//* 202131230 정윤혁 2022.04.09

#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;

    for (; n != -1;)
    {
        cout << "Enter an inteager (-1 to stop) : ";
        cin >> n;
        sum += n;
    }

    sum += 1;

    cout << "The sum is : " << sum << endl;

    return 0;
}
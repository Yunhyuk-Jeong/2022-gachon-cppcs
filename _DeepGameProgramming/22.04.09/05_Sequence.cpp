//* 202131230 정윤혁 2022.04.09

#include <cmath>
#include <iostream>

using namespace std;

//? INPUT : 5
//? INPUT : 15

int main()
{
    int sum[3] = {
        0,
    };

    int n;

    cout << "Enter the value of n : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        sum[0] += pow(i, 1);
        sum[1] += pow(i, 2);
        sum[2] += pow(i, 3);
    }

    cout << "Value of n : " << n << endl;
    cout << "Value of sum1 : " << sum[0] << endl;
    cout << "Value of sum2 : " << sum[1] << endl;
    cout << "Value of sum3 : " << sum[2] << endl;

    return 0;
}
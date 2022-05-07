//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         Emplyee 1 pay : 880
//@         Emplyee 2 pay : 225

double calcEarnings(double rate, double hours = 40);

int main()
{
    cout << "Emplyee 1 pay : " << calcEarnings(22.0) << endl;
    cout << "Emplyee 2 pay : " << calcEarnings(12.50, 18);

    return 0;
}

double calcEarnings(double rate, double hours)
{
    double pay;
    pay = hours * rate;

    return pay;
}
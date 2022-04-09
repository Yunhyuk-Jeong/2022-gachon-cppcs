//* 202131230 정윤혁 2022.04.09

#include <iostream>

using namespace std;

//? INPUT : 14500 -5 12300

int main()
{
    double income, tax;
    bool check[4];
    double limit[3] = {10000.00, 50000.00, 100000.00};
    double rate[4] = {0.05, 0.10, 0.15, 0.20};

    cout << "Enter income in dollars: ";
    cin >> income;

    check[0] = (income <= limit[0]) && (income >= 0);
    check[1] = (income > limit[0]) && (income <= limit[1]);
    check[2] = (income > limit[1]) && (income <= limit[2]);
    check[3] = (income > limit[2]);

    if (check[0])
        tax = income * rate[0];

    else if (check[1])
        tax = limit[0] * rate[0] + (income - limit[0]) * rate[1];

    else if (check[2])
        tax = limit[0] * rate[0] + (limit[1] - limit[0]) * rate[1] + (income - limit[1]) * rate[2];

    else if (check[3])
        tax = limit[0] * rate[0] + (limit[1] - limit[0]) * rate[1] + (limit[2] - limit[1]) * rate[2] +
              (income - limit[2]) * rate[3];

    else
    {
        cout << "Error! Invalid income!";
        return 0;
    }

    cout << "Income : " << income << endl;
    cout << "Tax due : " << tax;

    return 0;
}
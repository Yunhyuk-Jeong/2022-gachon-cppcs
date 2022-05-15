//* 202131230 정윤혁 2022.05.14

#include <iostream>

using namespace std;

//?         ==INPUT01==
//?         Enter the month number (1 to 12): 1
//@         ==OUTPUT01==
//@         There are 31 days in this month.

//?         ==INPUT02==
//?         Enter the month number (1 to 12): 6
//@         ==OUTPUT02==
//@         There are 30 days in this month.

//?         ==INPUT03==
//?         Enter the month number (1 to 12): 0
//?         Enter the month number (1 to 12): 13
//?         Enter the month number (1 to 12): 3
//@         ==OUTPUT03==
//@         There are 31 days in this month.

int main()
{
    int numberOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month;

    do
    {
        cout << "Enter the month number (1 to 12) : ";
        cin >> month;
    } while (month < 1 || month > 12);

    cout << "There are " << numberOfDays[month];
    cout << " days in this month.";

    return 0;
}
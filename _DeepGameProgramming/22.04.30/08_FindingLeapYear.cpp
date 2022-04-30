//* 202131230 정윤혁 2022.04.30

#include <iostream>

using namespace std;

//?     ==INPUT 01==
//?     1900
//@     ==OUTPUT 01==
//@     Year 1900 is not a leap year

//?     ==INPUT 02==
//?     1500, 1600
//@     ==OUTPUT 02==
//@     The value is out of range.
//@     Year 1600 is a leap year.

int input()
{
    int year;

    while (true)
    {
        cout << "Enter a year after 1582 : ";
        cin >> year;
        if (year > 1582)
            break;
        cout << "The value is out of range." << endl;
    }

    return year;
}

bool process(int year)
{
    bool criteria1 = (year % 4 == 0);
    bool criteria2 = (year % 100 != 0) || (year % 400 == 0);

    return (criteria1) && (criteria2);
}

void output(int year, bool result)
{
    if (result)
        cout << "Year " << year << " is a leap year.";
    else
        cout << "Year " << year << " is not a leap year.";

    return;
}

int main()
{
    int year = input();
    bool result = process(year);

    output(year, result);

    return 0;
}
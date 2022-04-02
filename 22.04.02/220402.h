
//* 202131230 정윤혁
//* 2022.04.02 Sat
//* Source Code
#include <iomanip>
#include <iostream>

using namespace std;

#define SWAP(a, b)                                                                                                     \
    a ^= b;                                                                                                            \
    b ^= a;                                                                                                            \
    a ^= b;

class Header
{
  public:
    void _20220402_01();
    int NOT(int arg);
    void _20220402_02();
    void _20220402_03();
    void _20220402_04();
    void _20220402_05();
    void _20220402_06();
    void _20220402_07();
    void _20220402_08();
    void _20220402_09();
    int Add(int a, int b);
    void _20220402_10();
    void _20220402_11();
    void _20220402_12(int a);
    void _20220402_13(double a, double b);
    void _20220402_14(int a);
    void _20220402_15(int a, int b);
    void _20220402_16(int a);
    void _20220402_17(int a);
};

void _20220402_01()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 01

    char c; //* signed type

    c = 2;      //* [0000,0010] 2
    c = c >> 1; //* [0000,0001] 1
    cout << +c << endl;

    c = -126;   //* [1000,0010] -126
    c = c >> 1; //* [1100,0001] -63
    cout << +c << endl;
}

int NOT(int arg)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 02

    return arg ? 0 : 1;
}

void _20220402_02()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 02

    cout << NOT(3) << " " << NOT(0) << endl;
}

void _20220402_03()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 03

    cout << sizeof(char) << endl;   //* 1
    cout << sizeof(int) << endl;    //* 4
    cout << sizeof(double) << endl; //* 4

    char c;
    int i;
    double d;
    int arr[4];

    cout << sizeof(c) << endl;   //* 1
    cout << sizeof(i) << endl;   //* 4
    cout << sizeof(d) << endl;   //* 4
    cout << sizeof(arr) << endl; //* 16
}

void _20220402_04()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 04

    cout << fixed;
    cout.precision(0);

    int i = 3.141592;   //* 3
    float f = 67100870; //* 6710872

    cout << i << " " << f << endl;
}

void _20220402_05()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 05

    cout << 1 / 2 << endl;
    cout << (double)1 / 2 << endl;
}

void _20220402_06()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 06

    if (0)                 //* if문 시작
        cout << 1 << endl; //* if문 종료
    cout << 2 << endl;

    cout << 3 << endl;
}

void _20220402_07()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 07

    //* if문 시작
    if (0)
    {
        cout << 1 << endl;
        cout << 2 << endl;
    }
    //* if문 종료

    cout << 3 << endl;
}

void _20220402_08()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 08

    int a = 0;
    int b = 1;

    if (0)
        SWAP(a, b);

    cout << a << " " << b << endl;
}

void _20220402_09()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 09

    int a = 0;
    int b = 1;

    if (0)      //* if문 시작
        a ^= b; //* if문 종료
    b ^= a;
    a ^= b;

    cout << a << " " << b << endl;
}

int Add(int a, int b)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 10

    return a + b;
}

void _20220402_10()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 10

    int a, b;

    switch (Add(1, 2))
    {
    case 0:
    case 1:
    case 2:
    case 3:
        a = 3; //* 할당문
        b = 7; //* 할당문
        if (1) //* if문
            cout << Add(a, b) << endl;
    case 4:
        a = 30; //* 할당문
        b = 70; //* 할당문
        if (1)  //* if문
            cout << Add(a, b) << endl;
    }
}

void _20220402_11()
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 11

    switch (1)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        cout << 3 << endl;
        break;
    case 4:
        cout << 4 << endl;
        break;
    }
}

void _20220402_12(int a)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 12

    //? TEST CASE : 10 / -10

    int number = a;

    //@ cout << "Enter an integer : ";
    //@ cin >> number;
    cout << "Enter an integer : " << number << endl;

    if (number < 0)
        number = -number;

    cout << "Avsolute value of the number you entered is : " << number << endl;
}

void _20220402_13(double a, double b)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 13

    //? TEST CASE : 30, 22 / 45, 25

    double hours = a;
    double rate = b;
    double regularPay;
    double overPay;
    double totalPay;

    //@ cout << "Enter hours worked : ";
    //@ cin >> hours;
    //@ cout << "Enter pay rate : ";
    //@ cin >> rate;
    cout << "Enter hours worked : " << a << endl;
    cout << "Enter pay rate : " << b << endl;

    regularPay = hours * rate;
    overPay = 0.0;

    if (hours > 40.0)
    {
        overPay = (hours - 40.0) * rate * 0.30;
    }

    totalPay = regularPay + overPay;

    cout << fixed << showpoint;
    cout << "Regular pay = " << setprecision(2) << regularPay << endl;
    cout << "Over time pay = " << setprecision(2) << overPay << endl;
    cout << "Total pay = " << setprecision(2) << totalPay << endl;
}

void _20220402_14(int a)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 14

    //? TEST CASE : 65 / 92

    int score = a;

    //@ cout << "Enter a score between 0 and 100 : ";
    //@ cin >> score;
    cout << "Enter a score between 0 and 100 : " << score << endl;

    if (score >= 70)
        cout << "Grade is pass" << endl;
    else
        cout << "Grade is nopass" << endl;
}

void _20220402_15(int a, int b)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 15

    //? TEST CASE : 42, 32 / 12, 12 / 12, 28

    int num1 = a, num2 = b;

    //@ cout << "Enter the first number : ";
    //@ cin >> num1;
    //@ cout << "Enter the second number : ";
    //@ cin >> num2;
    cout << "Enter the first number : " << num1 << endl;
    cout << "Enter the second number : " << num2 << endl;

    if (num1 >= num2)
    {
        if (num1 > num2)
            cout << num1 << " > " << num2;
        else
            cout << num1 << " == " << num2;
    }
    else
        cout << num1 << " < " << num2;
}

void _20220402_16(int a)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 16

    //? TEST CASE : 83 / 65 / 95

    int score = a;
    char grade;

    //@ cout << "Enter a score between 0 and 100 : ";
    //@ cin >> score;
    cout << "Enter a score between 0 and 100 : " << score << endl;

    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';

    cout << "The grade is : " << grade;
}

void _20220402_17(int a)
{
    //* 202131230 정윤혁
    //* 2022.04.01 Sat
    //* Source Code 17

    //? TEST CASE : 73 / 63 / 82

    int temperature = a;
    bool hot;
    bool cold;

    //@ cout << "Enter the temperature : ";
    //@ cin >> temperature;
    cout << "Enter the temperature : " << temperature << endl;

    hot = temperature >= 75;
    cold = temperature <= 65;

    if (hot || cold)
    {
        cout << "The air condition system is turned on!" << endl;
        if (hot)
            cout << "The cooler is working!" << endl;
        else
            cout << "The heater is working!" << endl;
    }
    else
        cout << "The air condition system is turned off!" << endl;
}

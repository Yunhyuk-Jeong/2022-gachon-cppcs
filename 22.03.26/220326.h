
//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code
#include <iostream>
#include <vector>
using namespace std;

typedef int (*ARRAY2D_POINTER)[2][3];

int g_Arr[2][3];
int ga;     //* 0 init
int gb = 1; //* 1 init
/*
const int gc1; //! ERROR
*/
const int gc2 = 1;

ARRAY2D_POINTER func(int arg)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            g_Arr[i][j] * arg;
        }
    }

    return &g_Arr;
}

class Header
{
  public:
    void _20220326_01();
    void _20220326_02();
    void _20220326_03();
    void _20220326_04();
    void _20220326_05();
    void _20220326_06();
    void _20220326_07();
    double Divide(int a, int b);
    void _20220326_08();
    int Add(int a, int b);
    int &GetRef(int &arg);
    void _20220326_09();
    void _20220326_10();
    void _20220326_11();
    void _20220326_12();
    void _20220326_13();
    void _20220326_14();
    int Func();
    void _20220326_15();
    void _20220326_16();
    void _20220326_17();
    void _20220326_18();
};

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 01

void _20220326_01()
{
    cout << (*func(7)[0][0]) << endl;
    cout << (*func(7)[1][2]) << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code02

void _20220326_02()
{
    int a;     //* init
    int b = 2; //* 2 init

    cout << ga << endl;
    cout << gb << endl;
    cout << a << endl;
    cout << b << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 03

void _20220326_03()
{
    /*
    const int c1; //! ERROR
    c1 = 1;       //! ERROR
    */

    const int c2 = 1; //* OK

    cout << "ERROR\nERROR\nOK" << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 04

void _20220326_04()
{
    /*
    const int arr1[3]; //! ERROR
    */

    const int arr2[3] = {1, 2, 3}; //* OK

    /*
    arr[0] = 7;                    //! ERROR
    */

    cout << "ERROR\nOK\nERROR" << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 05

void _20220326_05()
{
    int a;

    const int *cp; //* OK
    cp = &a;
    /*
     *cp = 1; //! ERROR
     */

    a = 2; //* OK

    cout << "OK\nERROR\nOK" << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 06

void _20220326_06()
{
    auto a = 1; //* auto -> int
    cout << a << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 07

void _20220326_07()
{
    /*
    auto a; //! COMPILE ERROR
    a = 1;
    */
    cout << "COMPILE ERROR" << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 08

double Divide(int a, int b)
{
    return (double)a / b;
}

void _20220326_08()
{
    auto r = Divide(1, 2); //* auto -> double
    cout << r << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 09

const int Add(int a, int b)
{
    return a + b;
}

int &GetRef(int &arg)
{
    return arg;
}

void _20220326_09()
{
    auto s = Add(1, 2); //* Auto -> int
    s = 7;
    cout << s << endl;

    int a = 1;

    auto r1 = GetRef(a); //* auto -> int
    r1++;
    cout << a << endl;

    auto &r2 = GetRef(a); //* auto& -> int&
    r2++;
    cout << a << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 10

void _20220326_10()
{
    vector<int> v = {1, 2, 3};

    int Sum = 0;

    //* auto -> vector<int>::iterator
    for (auto it = v.begin(); it != v.end(); it++)
    {
        Sum += *it;
    }

    cout << Sum << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 11

void _20220326_11()
{
    int a, b;

    a = 1;
    cout << ++a << endl; //* 2

    a = 1;
    b = ++a;
    cout << b << endl; //* 2

    a = 1;
    cout << a++ << endl; //* 1

    a = 1;
    b = a++;
    cout << b << endl; //* 1

    a = 1;
    ++a;
    cout << a << endl; //* 2

    a = 1;
    a++;
    cout << a << endl; //* 2
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 12

void _20220326_12()
{
    int a = 0;
    ++a = 1; //* OK : L-Value
    /*
    a++ = 1; //! ERROR : R-Value
    */

    cout << "OK : L-Value\nERROR : R-Value" << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 13

void _20220326_13()
{
    int a = 0;

    if (a = 1)
    {
        cout << "a == 1" << endl;
    }
    else
    {
        cout << "a != 1" << endl;
    }
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 14

void _20220326_14()
{
    int a = 3;
    cout << !!a << endl; //* 1
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 15

int Func()
{
    cout << "Func" << endl;
    return 1;
}

void _20220326_15()
{
    if (0 && Func())
    {
        cout << "main" << endl;
    }

    cout << "Func() is 1, Print Noting" << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 16

void _20220326_16()
{
    int a = 3;
    int b = 7;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 17

void _20220326_17()
{
    float a = 3.7;
    float b = 7.3;

    *(int *)&a = *(int *)&a ^ *(int *)&b;
    *(int *)&b = *(int *)&a ^ *(int *)&b;
    *(int *)&a = *(int *)&a ^ *(int *)&b;
    cout << a << " " << b << endl;
}

//* 202131230 정윤혁
//* 2022.03.26 Sat
//* Source Code 18

void _20220326_18()
{
    char c = 1;

    c = c << 7;
    cout << +c << endl;

    c = c >> 7;
    cout << +c << endl;
}

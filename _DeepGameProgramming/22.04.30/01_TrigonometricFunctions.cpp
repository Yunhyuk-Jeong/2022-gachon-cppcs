//* 202131230 정윤혁 2022.04.30

#include <cmath>
#include <iostream>

using namespace std;

//@     ==OUTPUT==
//@     sin (45): 0.707107
//@     cos (45): 0.707107
//@     tan (45): 1

int main()
{
    const double PI = 3.141592653589793238462;
    double degree = PI / 4;

    cout << "sin (45) : " << sin(degree) << endl;
    cout << "cos (45) : " << cos(degree) << endl;
    cout << "tan (45) : " << tan(degree);

    return 0;
}
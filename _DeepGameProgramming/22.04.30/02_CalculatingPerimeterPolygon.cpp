//* 202131230 정윤혁 2022.04.30

#include <cmath>
#include <iostream>

using namespace std;

//?     ==INPUT 01==
//?     2, 3, 4, 5
//@     ==OUTPUT 01==
//@     Perimeter : 20
//@     Area : 25

//?     ==INPUT 02==
//?     5, 5
//@     ==OUTPUT 01==
//@     Perimeter : 25
//@     Area :  34.4095

int main()
{
    const double PI = 3.141592653589793238462;
    int n;
    double s, peri, area;

    for (;;)
    {
        cout << "Enter the number of sides (4 or more) : ";
        cin >> n;
        if (n >= 4)
            break;
    }

    for (;;)
    {
        cout << "Enter length of each side : ";
        cin >> s;
        if (s > 0.0)
            break;
    }

    peri = n * s;
    area = (n * pow(s, 2)) / (n * tan(PI / n));

    cout << "Perimeter : " << peri << endl;
    cout << "Area : " << area;

    return 0;
}
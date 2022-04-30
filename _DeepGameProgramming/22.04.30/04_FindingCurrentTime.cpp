//* 202131230 정윤혁 2022.04.30

#include <ctime>
#include <iostream>

using namespace std;

//@     ==OUTPUT==
//@     Current time : hh Hour mm Minute ss Seconds

int main()
{
    long elapsedSeconds = time(0);
    int currentSecond = elapsedSeconds % 60;

    long elpasedMinutes = elapsedSeconds / 60;
    int currentMinute = elpasedMinutes % 60;

    long elapsedHours = elpasedMinutes / 60;
    int currentHour = (elapsedHours % 24) + 9; //* Korea is UTC+09:00

    cout << "Current time : ";
    cout << currentHour << " Hour " << currentMinute << " Minute " << currentSecond << " Secounds";

    return 0;
}
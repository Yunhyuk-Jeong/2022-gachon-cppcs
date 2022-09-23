//* 202131230 정윤혁 2022.06.04

#include "../22.06.04/01_Queue.cpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <utility>

//@     ==OUTPUT==
//@     Arrive    Start     Delay     Leave     Serve time
//@     2         2         0         12        10
//@     7         12        5         19        7
//@     10        19        9         28        9
//@     13        28        15        37        9
//@     19        37        18        43        6
//@     20        43        23        53        10
//@     21        53        32        62        9
//@     24        62        38        71        9
//@     26        71        45        78        7
//@     29        78        49        86        8
//@     33        86        53        95        9
//@     39        95        56        104       9
//@     40        104       64        110       6
//@     42        110       68        119       9
//@     44        119       75        129       10
//@     ---------------------------------------------------
//@     Total serve time: 127
//@     Average Delay: 36.6667
//!     Number is Random

int randNum(int low, int high)
{
    int temp = rand();
    int num = temp % (high - low + 1) + low;
    return num;
}

int main()
{
    int size = 15;
    int arriveDelay;
    int serveTime;
    int arrive = 0;
    int start = 0;
    int leave = 0;
    int wait = 0;
    int totalServeTime = 0;
    int totalWait = 0;

    Queue<pair<int, int>> line;

    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        pair<int, int> p(randNum(1, 6), randNum(5, 10));
        line.push(p);
    }

    cout << left << setw(10) << "Arrive" << setw(10) << "Start";
    cout << left << setw(10) << "Delay" << setw(10) << "Leave";
    cout << left << setw(10) << "Serve time" << endl;

    while (line.size() > 0)
    {
        arriveDelay = line.front().first;
        serveTime = line.front().second;
        arrive = arrive + arriveDelay;

        if (arrive >= leave)
            start = arrive;
        else
            start = leave;

        leave = start + line.front().second;
        wait = start - arrive;

        cout << left << setw(10) << arrive << setw(10) << start;
        cout << left << setw(10) << wait;
        cout << setw(10) << leave;
        cout << left << setw(12) << serveTime << endl;

        totalServeTime += serveTime;
        totalWait += wait;

        line.pop();
    }

    double averageWait = static_cast<double>(totalWait) / size;

    cout << "---------------------------------------------------" << endl;
    cout << "Total serve time : " << totalServeTime << endl;
    cout << "Average Delay : " << averageWait << endl;

    return 0;
}
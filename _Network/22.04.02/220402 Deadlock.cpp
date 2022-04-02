//* 202131230 정윤혁
//* 2022.04.02 Sat
//* Source Code

#include "220402 Deadlock.h"

int a;
CriticalSection a_mutex;
int b;
CriticalSection b_mutex;

int main()
{
    //* Start t1 Thread
    thread t1([]() {
        while (1)
        {
            CriticalSectionLock lock(a_mutex);
            a++;
            CriticalSectionLock lock2(b_mutex);
            b++;
            cout << "t1 done." << endl;
        }
    });

    //* Start t2 Thread
    thread t2([]() {
        while (1)
        {
            CriticalSectionLock lock(b_mutex);
            b++;
            CriticalSectionLock lock2(a_mutex);
            a++;
            cout << "t2 done." << endl;
        }
    });

    t1.join();
    t2.join();

    return 0;
}
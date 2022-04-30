//* 202131230 정윤혁 2022.04.30

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    int low = 5;
    int high = 15;
    int tryLimit = 5;
    int guess;

    srand(time(0));
    int temp = rand();
    int num = temp % (high - low + 1) + low;
    int counter = 1;
    bool found = false;

    while (counter <= tryLimit && !found)
    {
        while (true)
        {
            cout << "Enter your guess between 5 to 15 (inclusive) : ";
            cin >> guess;
            if (guess >= 5 && guess <= 15)
                break;
            cout << "The value is out of range." << endl;
        }

        if (guess == num)
            found = true;
        else if (guess > num)
            cout << "Your guess was too high!" << endl;
        else
            cout << "Your guess was too low!" << endl;

        counter++;
    }

    if (found)
        cout << "Congratulation! You found it. The number was : " << num;
    else
        cout << "Sorry, you did not find it! The number was : " << num;

    return 0;
}
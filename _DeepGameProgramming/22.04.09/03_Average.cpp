//* 202131230 정윤혁 2022.04.09

#include <iostream>

using namespace std;

//? INPUT : 78 68 92 88
//? INPUT : 80 90 76 74

int main()
{
    int input[4];
    double avg = 0;

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the next score (Between 0 and 100) : ";
        cin >> input[i];
        avg += input[i];
    }

    avg /= 4;

    cout << "The average of score is : " << avg << endl;

    return 0;
}
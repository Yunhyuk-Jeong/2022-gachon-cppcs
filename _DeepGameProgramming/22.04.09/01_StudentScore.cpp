//* 202131230 정윤혁 2022.04.09

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

//? INPUT : 78 92 79
//@ OUTPUT : 78 92 79 / 78 92 / 85

//? INPUT : 65 93 60
//@ OUTPUT : 65 93 60 / 60 93 / 77

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return 1;
    else if (*(int *)first < *(int *)second)
        return -1;
    else
        return 0;
}

int main()
{
    int score[3];

    for (int i = 0; i < 3; i++)
        cin >> score[i];

    for (int i = 0; i < 3; i++)
        cout << score[i] << endl;

    qsort(score, 3, sizeof(int), compare);

    cout << score[0] << " " << score[2] << endl;

    float avg = score[0] + score[2];
    avg /= 2;
    avg = ceil(avg);

    cout << avg << endl;

    return 0;
}
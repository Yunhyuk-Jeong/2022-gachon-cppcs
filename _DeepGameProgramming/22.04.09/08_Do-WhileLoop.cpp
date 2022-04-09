//* 202131230 정윤혁 2022.04.09

#include <iostream>

using namespace std;

int main()
{
    int score;
    char grade;

    do
    {
        cout << "Enter a score between 0 and 100 : ";
        cin >> score;
    } while (score < 0 || score > 100);

    switch (score / 10)
    {
    case 10:
        grade = 'A';
        break;
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'B';
        break;
    case 7:
        grade = 'C';
        break;
    case 6:
        grade = 'D';
        break;
    default:
        grade = 'F';
    }

    cout << "The grade is " << grade << endl;

    return 0;
}
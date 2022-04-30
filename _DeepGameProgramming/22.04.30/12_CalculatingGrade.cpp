//* 202131230 정윤혁 2022.04.30

#include <iostream>

using namespace std;

//?     ==INPUT 01==
//?     87
//@     ==OUTPUT 01==
//@     Result of the test.
//@     Score : 87 out of 100
//@     Grade : B

//?     ==INPUT 02==
//?     93
//@     ==OUTPUT 02==
//@     Result of the test.
//@     Score : 93 out of 100
//@     Grade : A

int getScore()
{
    int score;
    while (true)
    {
        cout << "Enter a score between 0 and 100 : ";
        cin >> score;
        if (score >= 0 && score <= 100)
            break;
    }

    return score;
}

char findGrade(int score)
{
    char grade;
    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';

    return grade;
}

void printResult(int score, char grade)
{
    cout << endl << "Result of the test." << endl;
    cout << "Score : " << score << " out of 100" << endl;
    cout << "Grade : " << grade;
}

int main()
{
    int score;
    char grade;

    score = getScore();
    grade = findGrade(score);
    printResult(score, grade);

    return 0;
}
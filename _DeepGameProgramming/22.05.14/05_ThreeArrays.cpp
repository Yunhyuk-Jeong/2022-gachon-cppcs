//* 202131230 정윤혁 2022.05.14

#include <iomanip>
#include <iostream>

using namespace std;

//@                           ==OUTPUT01==
//@
//@                      Test Scores stdAver            stdAvr
//@                  ---------------------------       --------
//@                   82          65          72        73.00
//@                   73          70          80        74.33
//@                   91          67          40        66.00
//@                   72          72          68        70.67
//@                   65          90          80        78.33
//@         tstAver   73.00       74.33       66.00

void findStudentAverage(int const scores[][3], double stdAver[], int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        int sum = 0;

        for (int j = 0; j < colSize; j++)
            sum += scores[i][j];

        double average = static_cast<double>(sum) / colSize;
        stdAver[i] = average;
    }

    return;
}

void findTestAverage(int const scores[][3], double tstAver[], int rowSize, int colSize)
{
    for (int j = 0; j < colSize; j++)
    {
        int sum = 0;

        for (int i = 0; i < rowSize; i++)
            sum += scores[i][j];

        double average = static_cast<double>(sum) / rowSize;
        tstAver[j] = average;
    }
}

int main()
{
    const int rowSize = 5;
    const int colSize = 3;
    int scores[rowSize][colSize] = {{82, 65, 72}, {73, 70, 80}, {91, 67, 40}, {72, 72, 68}, {65, 90, 80}};
    double stdAver[rowSize];
    double tstAver[colSize];

    findStudentAverage(scores, stdAver, rowSize, colSize);
    findTestAverage(scores, tstAver, rowSize, colSize);

    cout << "             Test Scores stdAver            stdAvr" << endl;
    cout << "         ---------------------------       -------- " << endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
            cout << setw(12) << scores[i][j];
        cout << setw(8) << fixed << setprecision(2) << " " << stdAver[i] << endl;
    }

    cout << "tstAver   ";

    for (int j = 0; j < colSize; j++)
        cout << fixed << setprecision(2) << stdAver[j] << " " << setw(11);

    return 0;
}
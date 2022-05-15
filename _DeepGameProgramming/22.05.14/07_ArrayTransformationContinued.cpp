//* 202131230 정윤혁 2022.05.14

#include <iomanip>
#include <iostream>

using namespace std;

//@                                ==OUTPUT01==
//@           Original Array
//@            0   1   2   3
//@           10  11  12  13
//@
//@           Row-Transformed Array :      0   1   2   3  10  11  12  13
//@           Column-Transformed Array :   0  10   1  11   2  12   3  13

void rowTransform(const int originArray[][4], int rowSize, int rowArray[])
{
    int i = 0;
    int j = 0;

    for (int k = 0; k < 8; k++)
    {
        rowArray[k] = originArray[i][j];
        j++;
        if (j > 3)
        {
            i++;
            j = 0;
        }
    }
}

void colTransform(const int originArray[][4], int rowSize, int colArray[])
{
    int i = 0;
    int j = 0;

    for (int k = 0; k < 8; k++)
    {
        colArray[k] = originArray[i][j];
        i++;
        if (i > 1)
        {
            j++;
            i = 0;
        }
    }
}

void printTwoDimensional(const int twoDimensional[][4], int rowSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << setw(4) << twoDimensional[i][j];
        cout << endl;
    }
    cout << endl;
}

void printOneDimensional(const int oneDimensional[], int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << oneDimensional[i];
    cout << endl;
}

int main()
{
    int originArray[2][4] = {{0, 1, 2, 3}, {10, 11, 12, 13}};
    int rowArray[8];
    int colArray[8];

    rowTransform(originArray, 2, rowArray);
    colTransform(originArray, 2, colArray);

    cout << "  Original Array " << endl;
    printTwoDimensional(originArray, 2);

    cout << "  Row-Transformed Array :   ";
    printOneDimensional(rowArray, 8);

    cout << "  Column-Transformed Array :";
    printOneDimensional(colArray, 8);

    return 0;
}
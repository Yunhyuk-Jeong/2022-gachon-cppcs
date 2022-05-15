//* 202131230 정윤혁 2022.05.14

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    const int CAPACITY = 10;
    int frequencies[CAPACITY] = {0};

    ifstream integerFile;

    integerFile.open("integerFile.dat");

    if (!integerFile)
    {
        cout << "Error. Integer file cannot be opened." << endl;
        cout << "The program is terminated.";

        return 0;
    }

    int data;
    int size = 0;

    while (integerFile >> data)
    {
        if (data >= 0 && data <= 9)
        {
            size++;
            frequencies[data]++;
        }
    }

    integerFile.close();

    cout << " There are " << size << " valid data items." << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << " " << setw(1) << left << i << " ";
        for (int f = 1; f <= frequencies[i]; f++)
            cout << '*';
        cout << " " << frequencies[i] << endl;
    }

    return 0;
}
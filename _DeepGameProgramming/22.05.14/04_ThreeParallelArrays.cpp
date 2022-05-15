//* 202131230 정윤혁 2022.05.14

#include <iomanip>
#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         George   82   B
//@         John     73   C
//@         Luci     91   A
//@         Mary     72   C

string names[4] = {"George", "John", "Luci", "Mary"};
int scores[4] = {82, 73, 91, 72};
char grades[4];
int size_ = 5;

void findGrades()
{
    char temp[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

    for (int i = 0; i < size_; i++)
        grades[i] = temp[scores[i] / 10];

    return;
}

int main()
{
    findGrades();

    for (int i = 0; i < 4; i++)
    {
        cout << setw(8) << left << names[i] << " " << setw(4);
        cout << scores[i] << " " << setw(4) << grades[i] << endl;
    }

    return 0;
}
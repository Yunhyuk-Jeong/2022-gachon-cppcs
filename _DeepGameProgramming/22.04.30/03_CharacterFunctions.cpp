//* 202131230 정윤혁 2022.04.30

#include <cctype>
#include <iostream>

using namespace std;

//?     ==INPUT==
//?     This is a line made of more than 10 characters.
//?     ^Z
//@     ==OUTPUT==
//@     THIS IS A LINE MADE OF MORE THAN 10 CHARACTERS.
//@     The count of alphabetic characters is : 35

int main()
{
    char ch;
    int count = 0;

    while (cin >> noskipws >> ch)
    {
        if (isalpha(ch))
            count++;
        ch = toupper(ch);
        cout << ch;
    }

    cout << "The count of alphabetic characters is : " << count;

    return 0;
}
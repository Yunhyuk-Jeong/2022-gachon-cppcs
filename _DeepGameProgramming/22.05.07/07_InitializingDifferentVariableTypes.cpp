//* 202131230 정윤혁 2022.05.07

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         Global = 0
//@         Static Local = 0
//!         Automatic Local = 4202830

int global;

int main()
{
    static int sLocal;
    //! auto int aLocal; //! Old C++

    cout << "Global = " << global << endl;
    cout << "Static Local = " << sLocal << endl;
    //! cout << "Automatic Local = " << aLocal << endl;

    return 0;
}
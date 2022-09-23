//* 202131230 정윤혁 2022.06.04

#include "../22.06.04/01_Queue.cpp"

//@     ==OUTPUT==
//@     Checking front and back elements after four push operations :
//@     Element at the front : Henry
//@     Element at the back : Richard
//@
//@     Checking front and back elements after two pop operations :
//@     Element at the front : Tara
//@     Element at the back : Richard

int main()
{
    Queue<string> queue;

    queue.push("Henry");
    queue.push("William");
    queue.push("Tara");
    queue.push("Richard");

    cout << "Checking front and back elements";
    cout << "after four push operations :" << endl;
    cout << "Element at the front : " << queue.front() << endl;
    cout << "Element at the back : " << queue.back() << endl << endl;

    queue.pop();
    queue.pop();

    cout << "Checking front and back elements";
    cout << "after two pop operations :" << endl;
    cout << "Element at the front : " << queue.front() << endl;
    cout << "Element at the back : " << queue.back() << endl;

    return 0;
}
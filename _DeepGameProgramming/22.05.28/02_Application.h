//* 202131230 정윤혁 2022.05.28

#include "../22.05.28/01_List.cpp"
#include <string>

int main()
{
    List<string> list;

    list.insert(0, "Michael");
    list.insert(1, "Jane");
    list.insert(2, "Sophie");
    list.insert(3, "Thomas");
    list.insert(4, "Rose");
    list.insert(5, "Richard");

    cout << "Printing the list" << endl;
    list.print();

    cout << "Getting data in some nodes" << endl;
    cout << list.get(0) << endl;
    cout << list.get(3) << endl;
    cout << list.get(5) << endl;

    cout << "Erasing some nodes and printing after erasures" << endl;
    list.erase(0);
    list.erase(3);
    list.print();

    cout << "Checking the list size" << endl;
    cout << "List size: " << list.size();

    return 0;
}
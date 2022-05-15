#include "Useful.h"

using namespace std;

class MadangBook

{
    int num;
    string name;
    string publisher;
    string price;

  public:
    MadangBook();
    MadangBook(int num, string name, string publisher, string price);
    void SetNum(int num);
    void SetName(string name);
    void SetPublisher(string publisher);
    void SetPrice(string price);
    int GetNum();
    string GetName();
    string GetPublisher();
    string GetPrice();
};
#include "MadangBook.h"

MadangBook::MadangBook()
{
}

MadangBook::MadangBook(int num, string name, string publisher, string price)
    : num(num), name(name), publisher(publisher), price(price)
{
}

void MadangBook::SetNum(int num)
{
    this->num = num;
}

void MadangBook::SetName(string name)
{
    this->name = name;
}

void MadangBook::SetPublisher(string publisher)
{
    this->publisher = publisher;
}

void MadangBook::SetPrice(string price)
{
    this->price = price;
}

int MadangBook::GetNum()
{
    return num;
}

string MadangBook::GetName()
{
    return name;
}

string MadangBook::GetPublisher()
{
    return publisher;
}

string MadangBook::GetPrice()
{
    return price;
}
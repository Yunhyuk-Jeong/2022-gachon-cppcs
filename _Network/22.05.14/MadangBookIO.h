#pragma once

#include "MadangBook.h"

using namespace std;

class MadangBookIO
{
    string filepath;

  public:
    int curr_cnt;
    MadangBookIO();
    MadangBookIO(string filepath);
    MadangBook *List();
    bool Add(MadangBook &m);
    MadangBook Search(int num);
    bool Update(MadangBook &m);
    bool Del(int num);
    int GetCount();

  private:
    bool Overwrite(string *arr, int cnt);
};
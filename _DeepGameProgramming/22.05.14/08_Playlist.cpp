//* 202131230 정윤혁 2022.05.14

#include <iostream>

using namespace std;

class playlist
{
  private:
    int musicList[50];
    int front = 0;

  public:
    void insert(int musicList, int *front, int musicNumber);
    void erase(int musicList, int *front, int musicNumber);
    int find(int musicList, int musicNumber);
};

void playlist::insert(int musicList, int *front, int musicNumber)
{
    musicList[front] = musicNumber;
}

void playlist::erase(int musicList, int *front, int musicNumber)
{
    int path = find(musicList, musicNumber);
}

int playlist::find(int musicList, int musicNumber)
{
}
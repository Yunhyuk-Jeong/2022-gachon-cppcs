//* 202131230 Yunhyuk Jeong 22.05.21

#include "CardGame.h"

using namespace std;

int main()
{
    game newGame;
    newGame.buildDeck();
    newGame.dealCards();
    bool isEnd = newGame.playGame();

    if (isEnd)
    {
        auto winner = newGame.getWinner();
        cout << "Number " << winner << " Player is Winner" << endl;
    }
    else
    {
        newGame.getLeastPlayer();
        //? cout << "Nobody Win (Infinity Loop)" << endl;
    }

    return 0;
}
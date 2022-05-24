//* 202131230 Yunhyuk Jeong 22.05.21

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

//* Card Struct
//* Deck Build & etc...
struct card
{
    int number;

    enum suit
    {
        HEART,
        SPADE,
        CLUB,
        DIAMOND
    } suit;

    string toString() const
    {
        ostringstream os;

        if (number > 0 && number <= 10)
            os << number;
        else
        {
            switch (number)
            {
            case 1:
                os << "Ace";
                break;
            case 11:
                os << "Jack";
                break;
            case 12:
                os << "Queen";
                break;
            case 13:
                os << "King";
                break;
            default:
                return "Invalid Card";
            }
        }

        os << " of ";

        switch (suit)
        {
        case HEART:
            os << "Hearts";
            break;
        case SPADE:
            os << "Spades";
            break;
        case CLUB:
            os << "Clubs";
            break;
        case DIAMOND:
            os << "Diamonds";
            break;
        }

        return os.str();
    }
};

//* Game Struct
//* About Games
struct game
{
    //* Deck Array
    array<card, 52> deck;
    //* Player's Info
    vector<card> player[4];

    //* Deck Build
    void buildDeck()
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 13; j++)
                deck[j + (i * 13)] = card{j + 1, i == 0   ? card::HEART
                                                 : i == 1 ? card::SPADE
                                                 : i == 2 ? card::CLUB
                                                          : card::DIAMOND};
    }

    //* Spread Random Cards to 4 Players
    void dealCards()
    {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(deck.begin(), deck.end(), default_random_engine(seed));
        for (int i = 0; i < 4; i++)
            player[i] = {deck.begin() + (i * 13), i == 3 ? deck.end() : deck.begin() + ((i + 1) * 13)};
    }

    //* Compare Two Player's Card.
    bool compareAndRemove(vector<card> &p1, vector<card> &p2)
    {
        //* if Card is Same
        if (p1.back().number == p2.back().number)
        {
            //* Print Cards Number
            cout << p1.back().number << " & " << p2.back().number << "\n" << endl;

            //* And Pop that
            p1.pop_back();
            p2.pop_back();

            return true;
        }

        //* if Card is !Same
        //* Print Fail
        cout << "Fail"
             << "\n"
             << endl;

        return false;
    }

    //* Game Play
    void playOneRound()
    {
        //* Player i and j Compare
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                cout << "Player " << i << " and Player " << j << " Compare." << endl;
                if (compareAndRemove(player[i], player[j]))
                {
                    if (i == 0)
                    {
                        switch (j)
                        {
                        case 1:
                            cout << "Player " << 3 << " and Player " << 4 << " Compare." << endl;
                            compareAndRemove(player[2], player[3]);
                            break;
                        case 2:
                            cout << "Player " << 2 << " and Player " << 4 << " Compare." << endl;
                            compareAndRemove(player[1], player[3]);
                            break;
                        case 3:
                            cout << "Player " << 2 << " and Player " << 3 << " Compare." << endl;
                            compareAndRemove(player[1], player[2]);
                            break;
                        default:
                            break;
                        }
                    }

                    return;
                }
            }
        }

        //* Random Shuffle
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        for (int i = 0; i < 4; i++)
            shuffle(player[i].begin(), player[i].end(), default_random_engine(seed));
    }

    //* Check Game Complete
    bool isGameComplete() const
    {
        return player[0].empty() || player[1].empty() || player[2].empty() || player[3].empty();
    }

    //* Play Game & Infinity Loop Check
    bool playGame()
    {
        int i = 0;
        //* Play playOneRound(); in !isGameComplete();
        for (i = 0; !isGameComplete(); i++)
        {
            //* if function is looping over 200 times, it's Infinity loop
            if (i > 13)
                return false;

            playOneRound();
        }

        cout << "Round : " << i << endl;

        return true;
    }

    //* Check Winner
    int getWinner() const
    {
        for (int i = 0; i < 4; i++)
            if (player[i].empty())
                return i + 1;

        return 0;
    }

    //* Check Least Card Count Player
    void getLeastPlayer()
    {
        vector<int> cardCount;

        for (int i = 0; i < 4; i++)
            cardCount.push_back(player[i].size());

        for (int i = 0; i < 4; i++)
            cout << i + 1 << " Player's CardCount : " << cardCount[i] << " " << player[i].size() << endl;
        cout << endl;

        int minCard = *min_element(cardCount.begin(), cardCount.end());

        vector<int> minPlayer;

        for (int i = 0; i < 4; i++)
            if (cardCount[i] == minCard)
                minPlayer.push_back(i);

        for (int i = 0; i < minPlayer.size(); i++)
            cout << "Min CardCount Player : " << minPlayer[i] + 1 << endl;
        cout << endl;

        cout << "\n============ DEBUD LOG END ============\n\n\n";

        //* Check Min Player is 1 or Over
        if (minPlayer.size() > 1)
            getSum(minPlayer, cardCount);
        else
            cout << "Players with the Least Amount of Cards : " << minPlayer[0] + 1 << endl;
    }

    //* Check Min & Max Sum
    void getSum(vector<int> minPlayer, vector<int> cardCount)
    {
        vector<int> sum;
        int playerCount = minPlayer.size();

        //* Player Card Sum
        for (int i = 0; i < playerCount; i++)
        {
            int cardSum = 0;

            for (int j = 0; j < cardCount[minPlayer[i]]; j++)
                cardSum += player[minPlayer[i]][j].number;

            sum.push_back(cardSum);
        }

        cout << "Players with the Least Amount of Cards        : ";
        for (int i = 0; i < playerCount; i++)
            cout << minPlayer[i] + 1 << " ";
        cout << "\n\n";

        cout << "Players with the Smallest Sum of Card Numbers : "
             << minPlayer[min_element(sum.begin(), sum.end()) - sum.begin()] + 1 << endl;
        cout << "Players with the Largest  Sum of Card Numbers : "
             << minPlayer[max_element(sum.begin(), sum.end()) - sum.begin()] + 1 << endl;
    }
};
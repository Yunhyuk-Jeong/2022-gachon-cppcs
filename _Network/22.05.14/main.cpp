#include "MadangBookIO.h"
#include "Useful.h"

using namespace std;

enum Menu
{
    LIST,
    SEARCH,
    ADD,
    UPDATE,
    DEL,
    EXIT,
    NONE
};

int GetCommand()
{
    return _getch();
}

void PrintClear()
{
    for (int i = 2; i < 27; i++)
    {
        Gotoxy_(i, 2);
        if (i == 2)
            cout << "┌─────────────────────────────────────────────────────────────────────────────────────────┐"
                 << endl;
        else if (i == 26)
            cout << "└─────────────────────────────────────────────────────────────────────────────────────────┘";
        else
            cout << "│                                                                                         │";
    }
}

void PrintEnter(int x, int y)
{
    if (x != -1 && y != -1)
    {
        Gotoxy_(x, y);
        cout << "◀ Enter Here";
    }
}

void RemoveEnter(int x, int y)
{
    if (x != -1 && y != -1)
    {
        Gotoxy_(x, y);
        cout << "             ";
    }
}

void PrintMenu()
{
    int x = 6;
    int yText = 43;

    TextColor(0xA);

    system("cls");

    PrintClear();

    Gotoxy(x, yText);
    cout << "1. Book List";
    x += 3;
    Gotoxy(x, yText);
    cout << "2. Add Book";
    x += 3;
    Gotoxy(x, yText);
    cout << "3. Search Book";
    x += 3;
    Gotoxy(x, yText);
    cout << "4. Update Book";
    x += 3;
    Gotoxy(x, yText);
    cout << "5. Delete Book";
    x += 4;
    Gotoxy(x, yText);
    cout << "0. EXIT";
}

Menu GetBookMenu()
{
    char input;

    input = GetCommand();

    Menu menu = NONE;

    switch (input)
    {
    case '1':
        menu = LIST;
        break;
    case '2':
        menu = ADD;
        break;
    case '3':
        menu = SEARCH;
        break;
    case '4':
        menu = UPDATE;
        break;
    case '5':
        menu = DEL;
        break;
    case '0':
        menu = EXIT;
        break;
    default:
        menu = NONE;
    }

    return menu;
}

void PrintList()
{
    Gotoxy(3, 5);
    cout << "   No   │            Book Name              │        Publisher        │       Price      ";
    Gotoxy(4, 5);
    cout << "────────┼───────────────────────────────────┼─────────────────────────┼──────────────────" << endl;
    for (int i = 5; i < 26; i++)
    {
        Gotoxy(i, 5);
        cout << "        │                                   │                         │                  ";
    }
    Gotoxy_(27, 2);
    cout << "(Page Move) ◀  ▶ | (Quit) Q";
}

void List(MadangBook *pm, int cnt)
{
    //! 정상 출력 한계는 10개, 다음페이지 기능 구현 예정
    PrintClear();
    PrintList();

    int page = 0;
    int pageMax = 0;
    if (cnt != 1)
        pageMax = (cnt - 1) / 10;

    while (true)
    {
        bool quit = false;
        int x = 6;
        for (int i = 1; i <= 10; i++)
        {
            Gotoxy_(27, 40);
            cout << "Page "<< setw(3) << (page + 1) << " / " << (pageMax + 1);

            if ((i - 1) + (page * 10) > cnt - 1)
                break;

            int y = 4;

            if (pm[i - 1].GetName().empty())
                break;

            Gotoxy(x, y * 2 - 1);
            cout << pm[(i - 1) + (page * 10)].GetNum();
            y += 4;
            Gotoxy(x, y * 2 - 2);
            cout << " " << pm[(i - 1) + (page * 10)].GetName();
            y += 18;
            Gotoxy(x, y * 2 - 2);
            cout << " " << pm[(i - 1) + (page * 10)].GetPublisher();
            y += 14;
            Gotoxy(x, y * 2 - 2);
            cout << setw(11) << pm[(i - 1) + (page * 10)].GetPrice() << " KRW";
            x += 2;
        }

        while (true)
        {
            int command = GetCommand();
            if (command == 75) //* Left Arrow
            {
                if (page == 0)
                    continue;
                page--;
                PrintClear();
                PrintList();
                break;
            }
            if (command == 77) //* Right Arrow
            {
                if (page == pageMax)
                    continue;
                page++;
                PrintClear();
                PrintList();
                break;
            }
            if (command == 'q' || command == 'Q')
            {
                quit = true;
                break;
            }
        }

        if (quit)
            break;
    }

    delete[] pm;
}

void PrintAddBefore()
{
    PrintClear();

    int x = 5;
    int y = 17;

    Gotoxy_(x++, y);
    cout << "┌──────────  NUMBER ──────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;

    Gotoxy_(x++, y);
    cout << "┌─────────  BOOK NAME ────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;

    Gotoxy_(x++, y);
    cout << "┌─────────  PUBLUSHER ────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;

    Gotoxy_(x++, y);
    cout << "┌──────────  PRICE ───────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";

    Gotoxy_(27, 2);
    cout << "(Add Continue) S | (Quit) Q";
}

void PrintAddAfter()
{
    for (int i = 0; i < 14; i++)
    {
        Gotoxy_(7 + i, 11);
        if (i == 0)
            cout << "┌─────────────────────────────────────────────────────┐";
        else if (i == 13)
            cout << "└─────────────────────────────────────────────────────┘";
        else
            cout << "│                                                     │";
    }
}

MadangBook Add()
{
    int num;
    stringstream numSs;
    string numString;
    string name;
    string publisher;
    string price;

    for (int i = 0; i < 4; i++)
    {
        PrintEnter(i * 5 + 6, 33);
        Gotoxy_(i * 5 + 6, 20);
        switch (i)
        {
        case 0:
            cin >> numString;
            numSs << numString;
            numSs >> num;
            break;
        case 1:
            cin >> name;
            break;
        case 2:
            cin >> publisher;
            break;
        case 3:
            cin >> price;
            break;
        }
        RemoveEnter(i * 5 + 6, 33);
    }

    MadangBook m(num, name, publisher, price);

    return m;
}

void PrintSearchBefore(int cnt)
{
    int x = 5;
    int y = 17;

    Gotoxy_(x++, y);
    cout << "┌──────────  NUMBER ──────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;
    Gotoxy(x++, 5);
    cout << "────────┬───────────────────────────────────┬─────────────────────────┬──────────────────" << endl;
    Gotoxy(x++, 5);
    cout << "   No   │            Book Name              │        Publisher        │       Price      ";
    Gotoxy(x++, 5);
    cout << "────────┼───────────────────────────────────┼─────────────────────────┼──────────────────" << endl;
    if (cnt == 0)
    {
        for (int i = 0; i < 13; i++)
        {
            Gotoxy(x + i, 5);
            cout << "        │                                   │                         │                 ";
        }
    }

    Gotoxy_(27, 2);
    cout << "(Search Continue) S | (Quit) Q";

    Gotoxy_(x - 7, y + 4);
}

int Search()
{
    int num;
    stringstream numSs;
    string numString;

    cin >> numString;
    numSs << numString;
    numSs >> num;

    return num;
}

void PrintSearchAfter(MadangBook &m, int cnt)
{
    int x = (cnt * 2) + 14;
    int y = 4;

    if (cnt == -2 || cnt == -1)
        x--;

    if (cnt == 5)
    {
        Gotoxy_(6, 18);
        cout << "■■■■List is FULL■■■■";
        Gotoxy_(27, 2);
        cout << "(Restart) R | (Quit) Q                      ";
    }

    Gotoxy(x, y * 2 - 1);
    cout << m.GetNum();
    y += 4;
    Gotoxy(x, y * 2 - 2);
    cout << " " << m.GetName();
    y += 18;
    Gotoxy(x, y * 2 - 2);
    cout << " " << m.GetPublisher();
    y += 14;
    Gotoxy(x, y * 2 - 2);
    cout << setw(11) << m.GetPrice() << " KRW";
    x += 2;
}

void PrintUpdateBefore()
{
    int x = 4;
    int y = 17;

    Gotoxy_(x++, y);
    cout << "┌──────────  NUMBER ──────────┐";
    Gotoxy_(x, 6);
    cout << "Want You Change";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 1;
    Gotoxy(x++, 5);
    cout << "────────┬───────────────────────────────────┬─────────────────────────┬──────────────────" << endl;
    Gotoxy(x++, 5);
    cout << "        │                                   │                         │                  ";
    Gotoxy(x++, 5);
    cout << "────────┴───────────────────────────────────┴─────────────────────────┴──────────────────" << endl;

    Gotoxy_(27, 2);
    cout << "(Change Continue) S | (Quit) Q";

    x++;
    Gotoxy_(x++, y);
    cout << "┌─────────  BOOK NAME ────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;

    Gotoxy_(x++, y);
    cout << "┌─────────  PUBLUSHER ────────┐";
    Gotoxy_(x, 6);
    cout << "What To Change";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;

    Gotoxy_(x++, y);
    cout << "┌──────────  PRICE ───────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";

    PrintEnter(5, 33);
}

int UpdateGetNum()
{
    int num;
    stringstream numSs;
    string numString;

    Gotoxy_(5, 21);
    cin >> numString;
    numSs << numString;
    numSs >> num;

    return num;
}

MadangBook Update(int num)
{
    MadangBookIO bio("db.dat");

    string name, publisher, price;

    RemoveEnter(5, 33);

    for (int i = 0; i < 3; i++)
    {
        PrintEnter(i * 5 + 13, 33);
        Gotoxy_(i * 5 + 13, 21);
        switch (i)
        {
        case 0:
            cin >> name;
            break;
        case 1:
            cin >> publisher;
            break;
        case 2:
            cin >> price;
            break;
        }
        RemoveEnter(i * 5 + 13, 33);
    }

    MadangBook m;

    m.SetNum(num);
    m.SetName(name);
    m.SetPublisher(publisher);
    m.SetPrice(price);

    return m;
}

void PrintUpdateAfter()
{
    for (int i = 0; i < 13; i++)
    {
        Gotoxy_(12 + i, 11);
        if (i == 0)
            cout << "┌─────────────────────────────────────────────────────┐";
        else if (i == 12)
            cout << "└─────────────────────────────────────────────────────┘";
        else
            cout << "│                                                     │";
    }
    Gotoxy(16, 43);
    cout << "Change SUCCESS";
    Gotoxy(18, 39);
    cout << "Press 'S' to Continue";
    Gotoxy(19, 41);
    cout << "Press 'Q' to EXIT";
}

void PrintDelBefore()
{
    int x = 5;
    int y = 17;

    Gotoxy_(x++, y);
    cout << "┌──────────  NUMBER ──────────┐";
    PrintEnter(x, 33);
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;
    Gotoxy(x++, 5);
    cout << "────────┬───────────────────────────────────┬─────────────────────────┬──────────────────" << endl;
    Gotoxy(x++, 5);
    cout << "        │                                   │                         │                  ";
    Gotoxy(x++, 5);
    cout << "────────┴───────────────────────────────────┴─────────────────────────┴──────────────────";
    Gotoxy_(27, 2);
    cout << "(Delete Continue) S | (Quit) Q";
}

int Del()
{
    int num;
    stringstream numSs;
    string numString;

    Gotoxy_(6, 20);

    cin >> numString;
    numSs << numString;
    numSs >> num;

    return num;
}

bool DelCheck()
{
    for (int i = 0; i < 11; i++)
    {
        Gotoxy_(14 + i, 11);
        if (i == 0)
            cout << "┌─────────────────────────────────────────────────────┐";
        else if (i == 10)
            cout << "└─────────────────────────────────────────────────────┘";
        else
            cout << "│                                                     │";
    }
    Gotoxy(18, 41);
    cout << "Are you Delete it?";
    Gotoxy(20, 47);
    cout << "Y / N";

    while (true)
    {
        int command = GetCommand();
        if (command == 'y' || command == 'Y')
            return true;
        if (command == 'n' || command == 'N')
            return false;
    }
}

void PrintDelAfter(bool chk)
{
    Gotoxy(18, 41);
    cout << "                   ";
    Gotoxy(20, 47);
    cout << "      ";

    Gotoxy(18, 43);
    if (chk)
        cout << "Delete Complete";
    else
        cout << "Delete Cancled";

    Gotoxy(20, 36);
    cout << "Continue to 'S' | Exit to 'Q'";
}

int main()
{
    SetWindow(98, 29);
    RemoveScrollbar();
    SetCursorType(NOCURSOR);

    MadangBookIO bio("db.dat");

    bool run = true, saved = false;

    MadangBook *pm = 0;
    MadangBook book;

    while (run)
    {
        PrintMenu();

        Menu m = GetBookMenu();

        switch (m)
        {
        case LIST:
            pm = bio.List();
            List(pm, bio.curr_cnt);
            break;
        case ADD:
            for (int i = 0;; i++)
            {
                PrintAddBefore();
                book = Add();
                saved = bio.Add(book);
                PrintAddAfter();
                Gotoxy(13, 40);
                cout << "= Add Book " << (saved ? "SUCCESS" : "  FAIL ") << " =";

                while (true)
                {
                    int command = GetCommand();
                    if (command == 's' || command == 'S')
                        break;
                    if (command == 'q' || command == 'Q')
                    {
                        i = -10;
                        break;
                    }
                }
                if (i == -10)
                    break;
            }
            break;
        case SEARCH:
            PrintClear();
            for (int i = 0;; i++)
            {
                if (i < 6)
                {
                    try
                    {
                        PrintSearchBefore(i);
                        MadangBook m = bio.Search(Search());
                        PrintSearchAfter(m, i);
                    }
                    catch (exception &e)
                    {
                        Gotoxy_(6, 18);
                        cerr << e.what() << endl;
                        i--;
                    }
                }

                while (true)
                {
                    int command = GetCommand();
                    if (command == 's' || command == 'S')
                        break;
                    if (command == 'q' || command == 'Q')
                    {
                        i = -10;
                        break;
                    }
                    if (i >= 5 && (command == 'r' || command == 'R'))
                    {
                        i = -1;
                        PrintClear();
                        break;
                    }
                }
                if (i == -10)
                    break;
            }
            break;
        case UPDATE:
            for (int i = 0;; i++)
            {
                try
                {
                    PrintClear();
                    PrintUpdateBefore();
                    MadangBook m = bio.Search(UpdateGetNum());
                    PrintSearchAfter(m, -2);
                    book = Update(m.GetNum());
                    bio.Update(book);
                    PrintUpdateAfter();
                }
                catch (exception &e)
                {
                    Gotoxy_(5, 18);
                    cerr << e.what() << endl;
                }

                while (true)
                {
                    int command = GetCommand();
                    if (command == 's' || command == 'S')
                        break;
                    if (command == 'q' || command == 'Q')
                    {
                        i = -10;
                        break;
                    }
                }
                if (i == -10)
                    break;
            }
            break;
        case DEL:
            for (int i = 0;; i++)
            {
                try
                {
                    PrintClear();
                    PrintDelBefore();
                    MadangBook m = bio.Search(Del());
                    PrintSearchAfter(m, -1);
                    if (DelCheck())
                    {
                        bio.Del(m.GetNum());
                        PrintDelAfter(true);
                    }
                    else
                        PrintDelAfter(false);
                }
                catch (exception &e)
                {
                    Gotoxy_(6, 18);
                    cerr << e.what() << endl;
                }

                while (true)
                {
                    int command = GetCommand();
                    if (command == 's' || command == 'S')
                        break;
                    if (command == 'q' || command == 'Q')
                    {
                        i = -10;
                        break;
                    }
                }
                if (i == -10)
                    break;
            }
            break;

        case EXIT:
            run = false;
            break;
        case NONE:
            break;
        }
    }

    return 0;
}
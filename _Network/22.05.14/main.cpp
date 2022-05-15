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
        if (i == 2 || i == 26)
            cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
        else
            cout << "■                                                                                        ■";
    }
}

void PrintMenu()
{
    int x = 6;
    int yText = 21;

    TextColor(0xA);

    system("cls");

    PrintClear();

    Gotoxy_(x, yText);
    cout << "1. 모든 도서찾기";
    x += 3;
    Gotoxy_(x, yText);
    cout << "2. 도서 등록하기";
    x += 3;
    Gotoxy_(x, yText);
    cout << "3. 도서 검색하기";
    x += 3;
    Gotoxy_(x, yText);
    cout << "4. 도서 수정하기";
    x += 3;
    Gotoxy_(x, yText);
    cout << "5. 도서 삭제하기";
    x += 4;
    Gotoxy_(x, yText);
    cout << "0. 이제 종료하기";
    Gotoxy_(9, yText);
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

void PrintList(MadangBook *pm, int cnt)
{
    PrintClear();
    Gotoxy_(3, 2);
    cout << "■  No  ■            Book Name             ■        Publisher         ■     Price      ■";
    Gotoxy_(4, 2);
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
    for (int i = 5; i < 26; i++)
    {
        Gotoxy_(i, 2);
        cout << "■      ■                                  ■                          ■                ■";
    }
    Gotoxy_(28, 2);
    cout << "(Page Move) ◀  ▶ | (Quit) Q";

    //! 정상 출력 한계는 10개, 다음페이지 기능 구현 예정

    while (true)
    {
        int x = 6;
        for (int i = 1; i <= cnt; i++)
        {
            int y = 4;
            if (pm[i - 1].GetName().empty())
                break;

            Gotoxy(x, y * 2 - 1);
            cout << pm[i - 1].GetNum();
            y += 4;
            Gotoxy(x, y * 2 - 2);
            cout << " " << pm[i - 1].GetName();
            y += 18;
            Gotoxy(x, y * 2 - 2);
            cout << " " << pm[i - 1].GetPublisher();
            y += 14;
            Gotoxy(x, y * 2 - 2);
            cout << setw(11) << pm[i - 1].GetPrice() << " KRW";
            x += 2;
        }

        int command = GetCommand();
        if (command == 'q' || command == 'Q')
            break;
    }

    delete[] pm;
}

MadangBook Add()
{
    int num;
    stringstream numSs;
    string numString;
    string name;
    string publisher;
    string price;

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

    Gotoxy_(6, 33);
    cout << "◀ Enter Here";
    Gotoxy_(6, y + 3);
    cin >> numString;
    numSs << numString;
    numSs >> num;

    Gotoxy_(6, 33);
    cout << "             ";
    Gotoxy_(11, 33);
    cout << "◀ Enter Here";
    Gotoxy_(11, y + 3);
    cin >> name;

    Gotoxy_(11, 33);
    cout << "             ";
    Gotoxy_(16, 33);
    cout << "◀ Enter Here";
    Gotoxy_(16, y + 3);
    cin >> publisher;

    Gotoxy_(16, 33);
    cout << "             ";
    Gotoxy_(21, 33);
    cout << "◀ Enter Here";
    Gotoxy_(21, y + 3);
    cin >> price;

    Gotoxy_(21, 33);
    cout << "             ";

    MadangBook m(num, name, publisher, price);
    string line;

    getline(cin, line);

    return m;
}

int Search()
{
    int num;
    stringstream numSs;
    string numString;

    int x = 5;
    int y = 17;

    Gotoxy_(x++, y);
    cout << "┌──────────  NUMBER ──────────┐";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 2;
    Gotoxy_(x++, 2);
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
    Gotoxy_(x++, 2);
    cout << "■  No  ■            Book Name             ■        Publisher         ■     Price      ■";
    Gotoxy_(x++, 2);
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

    Gotoxy_(28, 2);
    cout << "(Search Continue) S | (Quit) Q";

    Gotoxy_(x - 7, y + 4);

    cin >> numString;
    numSs << numString;
    numSs >> num;

    return num;
}

void PrintBook(MadangBook &m, int cnt)
{
    int x = (cnt * 2) + 14;
    int y = 4;

    if (cnt == -2)
        x--;

    if (cnt == 5)
    {
        Gotoxy_(6, 18);
        cout << "■■■■List is FULL■■■■";
        Gotoxy_(28, 2);
        cout << "(Quit) Q                      ";
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

MadangBook UpdateInfo()
{
    MadangBookIO bio("db.dat");

    int num;
    stringstream numSs;
    string numString;

    int x = 4;
    int y = 17;

    string name, publisher, price;

    Gotoxy_(x++, y);
    cout << "┌──────────  NUMBER ──────────┐";
    Gotoxy_(x, 6);
    cout << "Want You Change";
    Gotoxy_(x++, y);
    cout << "│                             │";
    Gotoxy_(x++, y);
    cout << "└─────────────────────────────┘";
    x += 1;
    Gotoxy_(x++, 2);
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
    Gotoxy_(x++, 2);
    cout << "■      ■                                  ■                          ■                ■";
    Gotoxy_(x++, 2);
    cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

    Gotoxy_(28, 2);
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

    Gotoxy_(5, 33);
    cout << "◀ Enter Here";

    Gotoxy_(5, y + 4);
    cin >> numString;
    numSs << numString;
    numSs >> num;

    MadangBook m = bio.Search(num);
    PrintBook(m, -2);

    Gotoxy_(5, 33);
    cout << "             ";
    Gotoxy_(13, 33);
    cout << "◀ Enter Here";
    Gotoxy_(13, y + 3);
    cin >> name;

    Gotoxy_(13, 33);
    cout << "             ";
    Gotoxy_(18, 33);
    cout << "◀ Enter Here";
    Gotoxy_(18, y + 3);
    cin >> publisher;

    Gotoxy_(18, 33);
    cout << "             ";
    Gotoxy_(23, 33);
    cout << "◀ Enter Here";
    Gotoxy_(23, y + 3);
    cin >> price;

    Gotoxy_(23, 33);
    cout << "             ";

    MadangBook m2;

    m2.SetNum(num);
    m2.SetName(name);
    m2.SetPublisher(publisher);
    m2.SetPrice(price);

    return m2;
}

int GetDelName()
{
    cout << "\n삭제할 책의 번호 : ";

    int num;

    cin >> num;

    return num;
}

int main()
{
    SetWindow(100, 30);
    RemoveScrollbar();
    SetCursorType(NOCURSOR);

    MadangBookIO bio("db.dat");

    bool go = true, saved = false;

    MadangBook *pm = 0;
    MadangBook book;

    while (go)
    {
        PrintMenu();

        Menu m = GetBookMenu();

        switch (m)
        {
        case LIST:
            pm = bio.List();
            PrintList(pm, bio.curr_cnt);
            break;
        case ADD:
            book = Add();
            saved = bio.Add(book);
            Gotoxy_(24, 20);
            cout << "= Add Book " << (saved ? "SUCCESS" : "  FAIL ") << " =";
            cout << endl;
            GetCommand();
            break;
        case SEARCH:
            PrintClear();
            for (int i = 0;; i++)
            {
                if (i < 6)
                {
                    try
                    {
                        MadangBook m = bio.Search(Search());
                        PrintBook(m, i);
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
                }
                if (i == -10)
                    break;
            }
            break;
        case UPDATE:
            PrintClear();
            book = UpdateInfo();
            bio.Update(book);
            GetCommand();
            break;
        case DEL:
            bio.Del(GetDelName());
            GetCommand();
            break;
        case EXIT:
            go = false;
            break;
        case NONE:
            break;
        }
    }

    cout << "\n프로그램 종료...." << endl;

    return 0;
}
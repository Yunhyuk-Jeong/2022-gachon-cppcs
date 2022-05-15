#include "MadangBookIO.h"

using namespace std;

MadangBookIO::MadangBookIO()
{
    this->filepath = "db.dat";
}

MadangBookIO::MadangBookIO(string filepath)
{
    this->filepath = filepath;
}

MadangBook *MadangBookIO::List()
{
    int cnt = GetCount();

    if (cnt == 0)
    {
        cout << "도서정보가 아직 없음" << endl;

        return nullptr;
    }

    MadangBook *pm = new MadangBook[cnt];

    ifstream fin(filepath);

    if (!fin.is_open())
    {
        cout << "파일열기 오류" << endl;
        return nullptr;
    }

    string line, name, publisher, price;

    int num, idx = 0;

    stringstream ss;

    while (!fin.eof())
    {
        getline(fin, line);

        if (line.length() == 0)
            break;

        ss.str(line);
        ss >> num >> name >> publisher >> price;

        pm[idx++] = MadangBook(num, name, publisher, price);

        ss.clear();
        line.clear();
    }

    fin.close();

    return pm;
}

bool MadangBookIO::Add(MadangBook &m)
{
    ofstream fout(filepath, ios::app);

    if (!fout.is_open())
    {
        cout << "파일 열기 오류" << endl;
        return false;
    }

    fout << m.GetNum() << " " << m.GetName() << " " << m.GetPublisher() << " " << m.GetPrice() << endl;

    fout.close();

    return true;
}

MadangBook MadangBookIO::Search(int num)
{
    ifstream fin(filepath);

    if (!fin.is_open())
    {
        cout << "파일 열기 오류" << endl;

        throw exception("파일열기 오류");
    }

    string line;
    int cnt = 0;
    stringstream ss;
    int fnum;
    string name, publisher, price;
    MadangBook m;

    while (!fin.eof())
    {
        getline(fin, line);
        ss.str(line);

        ss >> fnum;

        if (fnum == num)
        {
            ss >> name >> publisher >> price;

            fin.close();

            return MadangBook(fnum, name, publisher, price);
        }
    }

    fin.close();

    throw exception("■■■■SEARCH ERROR■■■■");
}

bool MadangBookIO::Update(MadangBook &m)
{
    int cnt = GetCount();

    ifstream fin(filepath);

    int num;
    string *all_lines = new string[cnt];
    string line, name, publisher, price;
    stringstream ss;

    int idx = 0;

    while (!fin.eof())
    {
        getline(fin, line);

        if (line.length() == 0)
            break;

        ss.str(line);
        ss >> num;

        if (num == m.GetNum())
        {
            stringstream ss2;

            ss2 << m.GetNum() << " " << m.GetName() << " " << m.GetPublisher() << " " << m.GetPrice();
            all_lines[idx++] = ss2.str();
            ss2.clear();
        }
        else
            all_lines[idx++] = line;

        ss.clear();
    }

    bool ok = Overwrite(all_lines, idx);

    return ok;
}

bool MadangBookIO::Del(int num)
{
    int cnt = GetCount();

    ifstream fin(filepath);

    int fnum;
    string *all_lines = new string[cnt - 1];
    string line;
    stringstream ss;
    int idx = 0;

    while (!fin.eof())
    {
        getline(fin, line);

        if (line.length() == 0)
            break;

        ss.str(line);
        ss >> fnum;
        if (num != fnum)
            all_lines[idx++] = line;

        ss.clear();
    }

    bool ok = Overwrite(all_lines, idx);

    cout << "삭제 결과 : " << ok << endl;

    return true;
}

int MadangBookIO::GetCount()
{
    ifstream fin(filepath);

    if (!fin.is_open())
    {
        cout << "파일 열기 오류" << endl;

        return -1;
    }

    string line;
    int cnt = 0;

    while (!fin.eof())
    {
        getline(fin, line);

        if (line.length() != 0)
            cnt++;

        line.clear();
    }

    fin.close();
    curr_cnt = cnt;

    return cnt;
}

bool MadangBookIO::Overwrite(string *arr, int cnt)
{
    ofstream fout(filepath);

    if (!fout.is_open())
    {
        cout << "파일 열기 오류" << endl;

        return false;
    }

    for (int i = 0; i < cnt; i++)
        fout << arr[i] << endl;

    fout.close();

    delete[] arr;

    return true;
}
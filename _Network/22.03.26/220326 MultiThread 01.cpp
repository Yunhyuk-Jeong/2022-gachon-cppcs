#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
const int MaxCount = 150000;

bool isPrimeNumber(int number)
{
    if (number == 1)
        return false;
    if (number == 2 || number == 3)
        return true;
    for (int i = 2; i < number; i++)
    {
        if ((number % i) == 0)
            return false;
    }
    return true;
}

void PrintNumbers(const vector<int> &primes)
{
    for (int v : primes)
        cout << v << endl;
}

void main()
{
    vector<int> primes;
    auto t0 = chrono::system_clock::now();
    for (int i = 1; i < MaxCount; i++)
        if (isPrimeNumber(i))
            primes.push_back(i);
    auto t1 = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t1 - t0).count();
    cout << "Took " << duration << " milliseconds." << endl;

    PrintNumbers(primes);
}
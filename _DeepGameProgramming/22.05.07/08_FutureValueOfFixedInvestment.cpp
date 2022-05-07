//* 202131230 정윤혁 2022.05.07

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

//?         ==INPUT01==
//?         Enter the value of investment : 360000
//?         Enter the interest rate per year : 5
//?         Enter the term (number of years) : 30
//@         ==OUTPUT01==
//@         Information about investment
//@         Investment : 360000.00
//@         Interest rate : 5.00 percent per year
//@         Term : 30.00 years
//@         Investment is multiplied by : 4.32194238
//@         Future value : 1555899.26

void input(double &invest, double &rate, double &term);
void process(double invest, double rate, double term, double &multiplier, double &futureValue);
void output(double invest, double rate, double term, double multiplier, double futureValue);

double getInput(string message);
double findMultiplier(double rate, double period);
void printData(double invest, double rate, double term);
void printResult(double multiplier, double value);

int main()
{
    double invest, rate, term, multiplier, futureValue;

    input(invest, rate, term);
    process(invest, rate, term, multiplier, futureValue);
    output(invest, rate, term, multiplier, futureValue);

    return 0;
}

void input(double &invest, double &rate, double &term)
{
    invest = getInput("Enter the value of investment : ");
    rate = getInput("Enter the interest rate per year : ");
    term = getInput("Enter the term (number of years) : ");
}

void process(double invest, double rate, double term, double &multiplier, double &futureValue)
{
    multiplier = findMultiplier(rate, term);
    futureValue = multiplier * invest;
}

void output(double invest, double rate, double term, double multiplier, double futureValue)
{
    printData(invest, rate, term);
    printResult(multiplier, futureValue);
}

double getInput(string message)
{
    double input;
    do
    {
        cout << message;
        cin >> input;
    } while (input < 0.0);

    return input;
}

double findMultiplier(double rate, double term)
{
    double factor = 1 + rate / 100;

    return pow(factor, term);
}

void printData(double invest, double rate, double term)
{
    cout << endl << "Information about investment" << endl;
    cout << "Investment : " << fixed << setprecision(2) << invest << endl;
    cout << "Interest rate : " << rate << fixed << setprecision(2);
    cout << " percent per year" << endl;
    cout << "Term : " << term << " years" << endl << endl;
}

void printResult(double multiplier, double futureValue)
{
    cout << "Investment is multiplied by : " << fixed << setprecision(8);
    cout << multiplier << endl;
    cout << "Future value : " << fixed << setprecision(2);
    cout << futureValue << endl;
}
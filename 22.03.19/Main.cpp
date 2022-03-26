#include <iostream>
using namespace std;
#define PI 3.141592;
#define MULTPLY(x,y) x+y

int main(){
    const unsigned int pennyValue  = 1;
    const unsigned int nickelValue = 5;
    const unsigned int dimeValue = 10;
    const unsigned int quarterValue = 25;
    const unsigned int dollarValue = 100;

    unsigned int pennies;
    unsigned int nickels;
    unsigned int dimes;
    unsigned int quarters;
    unsigned int dollars;

    unsigned long totalValue;

    cout << "penni";
    cin >> pennies;

    cout << "nickel";
    cin >> nickels;

    cout << "dime";
    cin >> dimes;

    cout << "quarters";
    cin >> quarters;

    cout << "dollars";
    cin >> dollars;

    totalValue = pennies * pennyValue + nickels*nickelValue + dimes*dimeValue + quarters*quarterValue + dollars*dollarValue;

    cout << "total is " << totalValue << " penny";

    return 0;
}

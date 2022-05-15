//* 202131230 정윤혁 2022.05.14

#include <iostream>

using namespace std;

//@         ==OUTPUT01==
//@         The sum of them is : 484
//@         The average of them is : 48.4
//@         The smallest number is : 14
//@         The largest number is : 95

int main()
{
    const int CAPACITY = 50;
    int numbers[CAPACITY] = {14, 76, 80, 33, 21, 95, 22, 88, 16, 39};
    int size = 10;
    int sum = 0;
    double average;
    int smallest = 1000000;
    int largest = -1000000;

    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
        if (numbers[i] < smallest)
            smallest = numbers[i];
        if (numbers[i] > largest)
            largest = numbers[i];
    }
    average = static_cast<double>(sum) / size;

    cout << "The sum of them is : " << sum << endl;
    cout << "The average of them is : " << average << endl;
    cout << "The smallest number is : " << smallest << endl;
    cout << "The largest number is : " << largest << endl;

    return 0;
}
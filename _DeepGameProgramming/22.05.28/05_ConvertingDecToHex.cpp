//* 202131230 정윤혁 2022.05.28

#include "../22.05.28/03_Stack.cpp"

int main()
{
    Stack<char> stack;

    string converter("0123456789ABCDEF");
    string hexadecimal;
    int decimal;
    int index;

    do
    {
        cout << "Enter a positive integer: ";
        cin >> decimal;
    } while (decimal <= 0);

    cout << "The decimal number: " << decimal << endl;

    while (decimal != 0)
    {
        stack.push(converter[decimal % 16]);
        decimal = decimal / 16;
    }

    while (stack.size() > 0)
    {
        hexadecimal.push_back(stack.top());
        stack.pop();
    }

    cout << "The hexadecimal number : " << hexadecimal;

    return 0;
}
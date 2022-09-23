//* 202131230 정윤혁 2022.05.28

#include "../22.05.28/03_Stack.cpp"

int main()
{
    Stack<char> stack;
    string origin;
    string reversed;

    cout << "Enter a string to be reversed: ";
    getline(cin, origin);

    for (int i = 0; i < origin.size(); i++)
    {
        stack.push(origin[i]);
    }

    while (stack.size() > 0)
    {
        reversed.push_back(stack.top());
        stack.pop();
    }

    cout << "Original string: " << origin << endl;
    cout << "Reversed string: " << reversed;

    return 0;
}
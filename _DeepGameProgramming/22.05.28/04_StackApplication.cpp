//* 202131230 정윤혁 2022.05.28

#include "../22.05.28/03_Stack.cpp"

int main()
{
    Stack<string> stack;

    stack.push("Henry");
    stack.push("William");
    stack.push("Tara");
    stack.push("Richard");

    cout << "Stack size: " << stack.size() << endl;

    while (stack.size() > 0)
    {
        cout << "Node value at the top: " << stack.top() << endl;
        stack.pop();
    }

    cout << "Stack size: " << stack.size();

    return 0;
}
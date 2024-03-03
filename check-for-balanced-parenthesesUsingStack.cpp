#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int max_size = 1000;
template <class T>
class Stack
{
    int top;
    T *List;
    T item[max_size];

public:
    Stack()
    {
        top = 0;
        List = new T[max_size];
    }
    bool empty()
    {
        return top == 0;
    }
    void push(T value)
    {
        List[top] = value;
        top++;
    }
    int Top()
    {
        return List[top - 1];
    }
    void pop()
    {
        if (empty())
        {
            cout << "is empty!" << endl;
        }
        else
            top--;
    }
};
bool Pair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    return false;
}
bool areBalanced(string exp)
{
    Stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            else if (!Pair(s.Top(), exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string exp = "[()]{}{[()()]()}";
    if (areBalanced(exp))
    {
        cout << "This is Balanced" << endl;
    }
    else
        cout << "Not Balannced." << endl;
}
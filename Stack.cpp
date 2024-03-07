#include <iostream>
#include <string>
using namespace std;
const int max_size = 1000;
template <class t>
class Stack
{
    int MS;
    t *List;
    int top;

public:
    Stack() // constructor
    {
        top = 0;
        MS = max_size;
        List = new t[MS];
    }
    Stack(int size) // constructor
    {
        top = 0;
        MS = size;
        List = new t[size];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    void push(t value)
    {
        if (StackisFull())
        {
            cout << "The Stack is Full!\n";
        }
        else
        {
            List[top] = value;
            top++;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "The Stack is Empty!" << endl;
        }
        else
        {
            top--;
        }
    }
    void print()
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << List[i] << " ";
        }
        cout << endl;
    }
    int Stacksize()
    {
        return top;
    }
    int getTop()
    {
        return List[top - 1];
    }
    bool StackisFull()
    {
        return (top == MS);
    }
    void clearStack()
    {
        for (int i = 0; i < MS; i++)
        {
            top--;
        }
    }
    int friStack(const Stack &y)
    {
        bool notEq = true;
        if (top != y.top)
        {
            notEq = false;
        }
        else
        {
            for (int i = 0; i < top; i++)
            {
                if (List[i] == y.List[i])
                {
                    notEq = true;
                }
                else
                {
                    notEq = false;
                    break;
                }
            }
        }
        return notEq;
    }
    void copyStack(const Stack &y)
    {
        MS = y.MS;
        top = y.top;
        List = new string[MS];
        for (int i = 0; i < MS; i++)
        {
            List[i] = y.List[i];
        }
    }
    Stack(const Stack &stack)
    {
        copyStack(stack);
    }
    ~Stack()
    {
        delete[] List;
    }
};
void revers(string &str)
{
    Stack<char> x;

    for (int i = 0; i < str.length(); i++)
    {
        char value;
        value = str[i];
        x.push(value);
    }
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = x.getTop();
        x.pop();
    }
}
int main()
{
    string str = "Data Structure Task 1";
    revers(str);
    cout << str << endl;
    string str1 = "MINA1611";
    revers(str1);
    cout << str1 << endl;
    return 0;
}
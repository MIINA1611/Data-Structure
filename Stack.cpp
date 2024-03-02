#include <iostream>
using namespace std;
template <class t>
class Stack
{
    int MS;
    t *List;
    int top;

public:
    Stack(int size)
    {
        top = 0;
        MS = size;
        List = new t[size];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    void Inetialize()
    {
        for (int i = 0; i < MS; i++)
        {
            string element;
            cout << "Stack[" << i + 1 << "]= ";
            getline(cin, element);
            push(element);
        }
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
    void Revers()
    {
        for (int i = top - 1; i >= 0; i--)
        {
            string value = List[i];
            int x = value.length();
            for (int j = x; j >= 0; j--)
            {
                cout << value[j];
            }
            cout << " ";
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
        return List[top];
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
int main()
{
    Stack<string> x(3);
    x.Inetialize();
    x.print();
    x.Revers();
    // Stack<string> y(5);
    // y.Inetialize();
    // x.pop();
    // x.print();
    // if (x.friStack(y))
    // {
    //     cout << "The Stack x Equal Stack y." << endl;
    // }
    // else
    // {
    //     cout << "The Stack x Not Equal Stack y." << endl;
    // }
    return 0;
}

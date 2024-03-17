#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
};
template <class T>
class Stack
{
    Node<T> *top;
    void copyStack(const Stack<T> &other)
    {
        Node<T> *newnode, *current, *last;
        clearStack();
        current = other.top;
        last = nullptr;
        while (current != nullptr)
        {
            newnode = new Node<T>();
            newnode->data = current->data;
            newnode->next = nullptr;
            if (top == nullptr)
                top = newnode;
            else
                last->next = newnode;
            last = newnode;
            current = current->next;
        }
    }

public:
    Stack()
    {
        top = nullptr;
    }
    void initialize()
    {
        while (top != nullptr)
        {
            Node<T> *delptr = top;
            top = top->next;
            delete delptr;
        }
    }
    bool isEmpty()
    {
        return (top == nullptr);
    }
    bool isFull()
    {
        return false;
    }
    void push(const T item)
    {
        Node<T> *newnode = new Node<T>();
        newnode->data = item;
        if (isEmpty())
        {
            newnode->next = nullptr;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
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
            Node<T> *delptr = top;
            top = top->next;
            delete delptr;
        }
    }
    void Traverse()
    {
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void clearStack()
    {
        initialize();
    }
    int Stacksize()
    {
        int counter;
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    T Top()
    {
        return top->data;
    }
    Stack<T> &operator=(const Stack<T> &other)
    {
        if (this != &other)
            copyStack(other);
        return *this;
    }
    friend bool operator==(const Stack<T> &firstStack, const Stack<T> &secondStack)
    {
        Node<T> *temp1 = firstStack.top;
        Node<T> *temp2 = secondStack.top;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    void merge(const Stack<T> &first, const Stack<T> &other)
    {
        Node<T> *temp1 = first.top;
        while (temp1 != nullptr)
        {
            push(temp1->data);
            temp1 = temp1->next;
        }
        Node<T> *temp2 = other.top;
        while (temp2 != nullptr)
        {
            push(temp2->data);
            temp2 = temp2->next;
        }
    }
    Stack<T> operator+(const Stack<T> &other) const
    {
        Stack<T> result;
        Node<T> *temp1 = this->top;
        Node<T> *temp2 = other.top;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            int sum = carry;
            if (temp1 != NULL)
            {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2 != NULL)
            {
                sum += temp2->data;
                temp2 = temp2->next;
            }
            carry = sum / 10;
            sum %= 10;
            result.push(sum);
        }

        return result;
    }
    ~Stack()
    {
        delete top;
    }
};
int main()
{
    Stack<int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    Stack<int> y;
    y.push(4);
    y.push(4);

    y.push(4);

    y.push(4);

    y.Traverse();
    if (x == y)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    Stack<int> MergeStack;
    MergeStack.merge(x, y);
    // MergeStack=x+y;
    MergeStack.Traverse();
}
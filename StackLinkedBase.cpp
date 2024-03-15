#include <iostream>
#include <string>
using namespace std;
template <class Type>
class Node
{
public:
    Type data;
    Node<Type> *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
template <class Type>
class stackADT
{
    Node<Type> *top;
    void copyStack(const stackADT<Type> &other);

public:
    stackADT();                            // defulte constructor
    void initialize();                     // TOP=NULL
    bool isEmpty();                        // Check Stack IS EMPTY Or NOOT
    bool isFullStack();                    // RETURN FALSE FOREVER
    void push(const Type &Newitem);        // THIS IS PUSH
    Type Top();                            // RETURN DATA FOR TOP
    void pop();                            // DELETE DATA FOR TOP
    void clearStack();                     // CLEAR ALL STACK
    int count();                           // THE ELEMENT STACK COUNTER
    void Traverse();                       // PRINT ALL THE ELEMENT STACK
    stackADT(const stackADT<Type> &other); // COPY STACK TO ANOTHER STACK
                                           //  bool operator=(const stackADT<Type> &x); // CHECK WHETHER FIRST STACK EQUAL ANOTHER STACK OR NOT
    ~stackADT();                           // DELETE TOP
};
template <class Type>
stackADT<Type>::stackADT(){};
template <class Type>
void stackADT<Type>::initialize()
{
    top = NULL;
}
template <class Type>
bool stackADT<Type>::isEmpty()
{
    return (top == NULL);
}
template <class Type>
bool stackADT<Type>::isFullStack()
{
    return false;
}
template <class Type>
void stackADT<Type>::push(const Type &newitem)
{
    Node<Type> *newnode = new Node<Type>();
    newnode->data = newitem;
    if (isEmpty())
    {
        newnode->next = NULL;
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
template <class Type>
Type stackADT<Type>::Top()
{
    return top->data;
}
template <class Type>
void stackADT<Type>::pop()
{
    Node<Type> *delptr = top;
    top = top->next;
    delete delptr;
}
template <class Type>
int stackADT<Type>::count()
{
    Node<Type> *temp = top;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
template <class Type>
void stackADT<Type>::clearStack()
{
    while (top != NULL)
    {
        Node<Type> *delptr = top;
        top = top->next;
        delete delptr;
    }
}
template <class Type>
void stackADT<Type>::Traverse()
{
    Node<Type> *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
template <class Type>
void stackADT<Type>::copyStack(const stackADT<Type> &other)
{
    top = other.top;
}
// template<class Type> bool stackADT<Type>::operator=(const stackADT<Type> &x)
// {
//     if (x.top != top)
//     {
//         return false;
//     }
//     else if (x.count() != count())
//     {
//         return false;
//     }
//     else
//     {
//         Node<Type> *temp1 = x.top;
//         Node<Type> *temp2 = top;
//         while (temp1 != NULL)
//         {
//             if (temp1 != temp2)
//             {
//                 return false;
//             }
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         }
//         return true;
//     }
// }
template <class Type>
stackADT<Type>::stackADT(const stackADT &other)
{
    copyStack(other);
}
template <class Type>
stackADT<Type>::~stackADT()
{
    delete top;
}
int main()
{
    stackADT<int> x;
    x.initialize();
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    x.push(5);
    cout << x.count() << endl;
    // x.Traverse();
    // x.pop();
    // x.Traverse();
    // x.clearStack();
    // if (x.isEmpty())
    // {
    //     cout << "Stack is Clear" << endl;
    // }
    // else
    // {
    //     cout << "Clear This Stack Idiot!" << endl;
    // }
    stackADT<int> y(x);
    y.pop();
    y.Traverse();
}
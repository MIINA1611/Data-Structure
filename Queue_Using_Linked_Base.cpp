#include <iostream>
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
class queueLinkedbase
{
    Node<Type> *front;
    Node<Type> *rear;
    void copyQueue(const queueLinkedbase<Type> &other);

public:
    queueLinkedbase();
    queueLinkedbase(const queueLinkedbase<Type> &other); // COPY QUEUE
    ~queueLinkedbase();
    bool isEmpty() const;
    bool isFull() const;
    void initailizeQueue();
    void addQueue(const Type &newitem);
    void deQueue();
    Type getFront();
    Type getRear();
    void Traverse();
    void clearQueue();
    Type sizeofQueue() const;
    void reverse();                                 // JUST REVERSE
    void reversQueue(queueLinkedbase<Type> &other); // REVERSE AND COPY
    queueLinkedbase<Type> &operator=(const queueLinkedbase<Type> &other);
    friend ostream &operator<<(ostream &os, const queueLinkedbase<Type> &obj);
    queueLinkedbase<Type> operator+(const queueLinkedbase<Type> &other) const;
    bool compare(const queueLinkedbase<Type> &second) const;
    friend bool operator==(const queueLinkedbase<Type> &first, const queueLinkedbase<Type> &second);
};
template <class Type>
queueLinkedbase<Type>::queueLinkedbase()
{
    front = NULL;
    rear = NULL;
}
template <class Type>
queueLinkedbase<Type>::queueLinkedbase(const queueLinkedbase<Type> &other) // COPY QUEUE
{
    copyQueue(other);
}
template <class Type>
bool queueLinkedbase<Type>::isEmpty() const
{
    return (front == NULL && rear == NULL);
}
template <class Type>
bool queueLinkedbase<Type>::isFull() const
{
    return false;
}
template <class Type>
void queueLinkedbase<Type>::initailizeQueue()
{
    Node<Type> *delptr;
    while (front != NULL)
    {
        delptr = front;
        front = front->next;
        delete delptr;
    }
}
template <class Type>
void queueLinkedbase<Type>::addQueue(const Type &newitem)
{

    Node<Type> *newnode = new Node<Type>();
    newnode->data = newitem;
    if (isEmpty())
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
template <class Type>
void queueLinkedbase<Type>::deQueue()
{
    if (isEmpty())
    {
        cout << "The Queue is Empty!" << endl;
    }
    else
    {
        Node<Type> *temp = front;
        front = front->next;
        delete temp;
    }
}
template <class Type>
Type queueLinkedbase<Type>::getFront()
{
    return front->data;
}
template <class Type>
Type queueLinkedbase<Type>::getRear()
{
    return rear->data;
}
template <class Type> // JUST REVERSE
void queueLinkedbase<Type>::reverse()
{
    if (isEmpty() || front == rear)
        return;
    Node<Type> *prev = nullptr;
    Node<Type> *current = front;
    Node<Type> *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    rear = front;
    front = prev;
}
template <class Type>
void queueLinkedbase<Type>::reversQueue(queueLinkedbase<Type> &other) // REVERSE AND COPY
{
    other.reverse();
    copyQueue(other);
}
template <class Type>
void queueLinkedbase<Type>::Traverse()
{
    if (isEmpty())
    {
        cout << "THe Queue is Empty!" << endl;
    }
    else
    {
        Node<Type> *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
template <class Type>
void queueLinkedbase<Type>::copyQueue(const queueLinkedbase<Type> &other)
{
    clearQueue();
    Node<Type> *frontcurrent = other.front;
    while (frontcurrent != NULL)
    {
        Node<Type> *newnode = new Node<Type>();
        newnode->data = frontcurrent->data;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
            rear->next = newnode;
        rear = newnode;
        frontcurrent = frontcurrent->next;
    }
}
template <class Type>
void queueLinkedbase<Type>::clearQueue()
{
    initailizeQueue();
}
template <class Type>
queueLinkedbase<Type> &queueLinkedbase<Type>::operator=(const queueLinkedbase<Type> &other)
{
    copyQueue(other);
    return *this;
}
template <class Type>
Type queueLinkedbase<Type>::sizeofQueue() const
{
    int counter = 0;
    Node<Type> *temp = front;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

template <class Type>
bool queueLinkedbase<Type>::compare(const queueLinkedbase<Type> &second) const
{
    if (CountofQueue() != second.CountofQueue())
        return false;
    Node<Type> *temp1 = front;
    Node<Type> *temp2 = second.front;
    while (temp1 != nullptr)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <class Type>
bool operator==(queueLinkedbase<Type> &first, queueLinkedbase<Type> &second)
{
    if (first.compare(second))
    {
        return true;
    }
    return false;
}
template <class Type> // MERGE
queueLinkedbase<Type> queueLinkedbase<Type>::operator+(const queueLinkedbase<Type> &other) const
{
    queueLinkedbase<Type> result;
    Node<Type> *temp1 = front;
    Node<Type> *temp2 = other.front;
    while (temp1 != NULL)
    {
        result.addQueue(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        result.addQueue(temp2->data);
        temp2 = temp2->next;
    }
    return result;
}

/*template<class Type>//SUM CARRY
queueLinkedbase<Type> queueLinkedbase<Type>::operator+(const queueLinkedbase<Type>& other)const
{
    queueLinkedbase<Type> result; // Create a new queue to store the result

    Node<Type>* temp1 = front;
    Node<Type>* temp2 = other.front;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        Type sum = carry;

        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10;
        sum %= 10;

        result.addQueue(sum); // Add the sum to the result queue
    }

    return result; // Return the result queue by value
}*/
template <class Type>
ostream &operator<<(ostream &os, queueLinkedbase<Type> &obj)
{
    obj.Traverse();
    return os;
}
template <class Type>
queueLinkedbase<Type>::~queueLinkedbase()
{
    delete front;
    delete rear;
}
int main()
{
    queueLinkedbase<int> x;
    x.addQueue(1);
    x.addQueue(2);
    x.addQueue(3);
    x.addQueue(4);
    x.addQueue(5);
    cout << x;
    queueLinkedbase<int> y;
    y.reversQueue(x);
    cout << y;
    if (y == x)
        cout << "Equal" << endl;
    else
        cout << "Not Equal!" << endl;
}

#include <iostream>
using namespace std;
template <class Type>
class queueADT
{
    int Max_Size;
    int count;
    int front;
    int rear;
    Type *list;
    void copyQueue(const queueADT<Type> &other);

public:
    queueADT();
    queueADT(int size);
    void initialize();
    bool isEmpty();
    bool isFull();
    void addQueue(const Type &newitem);
    void deQueue();
    Type frontQueue();
    Type rearQueue();
    void Traverse();
    void reverseTraverse();
    void clearQueue();
    bool SearchinQueue(const Type &item);
    queueADT<Type> &operator=(const queueADT<Type> &other);
    bool operator==(const queueADT<Type> &other);
    queueADT<Type> operator+(queueADT<Type> &other);
    void Merge(const queueADT<Type> &first, const queueADT<Type> &second);
    ~queueADT();
};

template <class Type>
queueADT<Type>::queueADT(int size)
{
    Max_Size = size;
    front = 0;
    count = 0;
    rear = Max_Size - 1;
    list = new Type[Max_Size];
}
template <class Type>
queueADT<Type>::queueADT()
{
    Max_Size = 1000;
    front = 0;
    count = 0;
    rear = Max_Size - 1;
    list = new Type[Max_Size];
}
template <class Type>
bool queueADT<Type>::isEmpty()
{
    return (count == 0);
}
template <class Type>
bool queueADT<Type>::isFull()
{
    return count == Max_Size;
}
template <class Type>
void queueADT<Type>::addQueue(const Type &newitem)
{
    if (isFull())
    {
        cout << "The Queue is Full!" << endl;
    }
    else
    {
        rear = (rear + 1) % Max_Size;
        list[rear] = newitem;
        count++;
    }
}
template <class Type>
void queueADT<Type>::initialize()
{
    front = 0;
    rear = Max_Size - 1;
    count = 0;
}
template <class Type>
void queueADT<Type>::Traverse()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % Max_Size)
        {
            cout << list[i] << " ";
        }
        cout << list[rear];
        cout << endl;
    }
}
template <class Type>
Type queueADT<Type>::frontQueue()
{
    return list[front];
}
template <class Type>
Type queueADT<Type>::rearQueue()
{
    return list[rear];
}
template <class Type>
void queueADT<Type>::deQueue()
{
    if (isEmpty())
        cout << "The Queue Is Empty!" << endl;
    else
    {
        count--;
        front = (front + 1) % Max_Size;
    }
}
template <class Type>
void queueADT<Type>::clearQueue()
{
    initialize();
}
template <class Type>
void queueADT<Type>::reverseTraverse()

{
    for (int i = (rear + Max_Size) % Max_Size; i != front; i = (i - 1 + Max_Size) % Max_Size)
    {
        cout << list[i] << " ";
    }
    cout << list[front];
    cout << endl;
}
template <class Type>
bool queueADT<Type>::SearchinQueue(const Type &item)
{
    for (int i = 0; i < count; i++)
    {
        if (item == list[i])
            return true;
    }
    return false;
}
template <class Type> // MERGE Version 2
void queueADT<Type>::Merge(const queueADT<Type> &first, const queueADT<Type> &second)
{
    Max_Size = (first.Max_Size + second.Max_Size);

    for (int i = first.front; i != first.rear; i = (i + 1) % first.Max_Size)
    {
        addQueue(first.list[i]);
    }
    addQueue(first.list[first.rear]);
    for (int i = second.front; i != second.rear; i = (i + 1) % second.Max_Size)
    {
        addQueue(second.list[i]);
    }
    addQueue(second.list[second.rear]);
}
/*template<class Type>    //MERGE
queueADT<Type> queueADT<Type>::operator+(queueADT<Type>& other)
{
    queueADT<Type>mergeQueue(count + other.count);
    for (int i = front; i != rear; i = (i + 1) % Max_Size)
    {
        mergeQueue.addQueue(list[i]);
    }
    mergeQueue.addQueue(list[rear]);
    for (int i = other.front; i != other.rear; i = (i + 1) % other.Max_Size)
    {
        mergeQueue.addQueue(other.list[i]);
    }
    mergeQueue.addQueue(other.list[other.rear]);
    return mergeQueue;
}*/
template <class Type> // SUM
queueADT<Type> queueADT<Type>::operator+(queueADT<Type> &other)
{

    queueADT<Type> resultqueue(max(Max_Size, other.Max_Size) + 2);
    int carry = 0;
    while (!isEmpty() || !other.isEmpty())
    {
        int sum = carry;
        if (!isEmpty())
        {
            sum += frontQueue();
            deQueue();
        }
        if (!other.isEmpty())
        {
            sum += other.frontQueue();
            other.deQueue();
        }
        carry = sum / 10; // Corrected carry calculation
        sum %= 10;

        resultqueue.addQueue(sum);
    }
    // If there's still a carry after adding all elements, enqueue it
    if (carry > 0)
    {
        resultqueue.addQueue(carry);
    }
    return resultqueue;
}
template <class Type>
void queueADT<Type>::copyQueue(const queueADT<Type> &other) // Not finish this function
{
    count = other.count;
    front = other.front;
    rear = other.rear;
    Max_Size = other.Max_Size;
    for (int i = other.front; i != other.rear; i = (i + 1) % other.Max_Size)
    {
        list[i] = other.list[i];
    }
    list[rear] = other.list[rear];
}
template <class Type>
queueADT<Type> &queueADT<Type>::operator=(const queueADT<Type> &other)
{
    copyQueue(other);
    return *this;
}
template <class Type>
bool queueADT<Type>::operator==(const queueADT<Type> &other)
{
    if (other.count != count)
        return false;
    int i = front;
    int j = other.front;
    for (int counter = 0; counter < other.count; counter++)
    {
        if (other.list[j] != list[i])
        {
            return false;
        }
        i = (i + 1) % Max_Size;
        j = (j + 1) % other.Max_Size;
    }
    return true;
}
template <class Type>
queueADT<Type>::~queueADT()
{
    delete[] list;
}
int main()
{
    queueADT<int> x(5);
    // x.initialize();
    x.addQueue(1);
    x.addQueue(2);
    x.addQueue(3);
    x.addQueue(4);
    x.addQueue(5);
    x.Traverse();
    queueADT<int> y(5);
    /*y.addQueue(1);
    y.addQueue(2);
    y.addQueue(3);
    y.addQueue(4);
    y.addQueue(5);*/
    y = x;
    y.deQueue();
    y.addQueue(6);
    y.Traverse();
    queueADT<int> q;
    q.Merge(x, y);
    q.Traverse();
}

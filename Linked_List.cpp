#pragma once
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
		next = nullptr;
	}
};
template <class Type>
class LinkedListIterator;
template <class Type>
class LinkedListType
{
private:
	void copyLinkedList(LinkedListType<Type> &other);

protected:
	int count;
	Node<Type> *first;
	Node<Type> *last;

public:
	LinkedListType();
	LinkedListType(LinkedListType<Type> &other);
	~LinkedListType();
	virtual bool search(const Type &item) const = 0;
	virtual void insertFirst(const Type &newitem) = 0;
	virtual void insertLast(const Type &item) = 0;
	virtual void deleteNode(const Type &item) = 0;
	virtual bool search2(const Type &item) = 0;
	void deleteFirst();
	void initialize();
	bool isEmptyList() const;
	void print1() const;
	void print2();
	int length() const;
	void destroyList();
	Type Front() const;
	Type Back() const;
	LinkedListIterator<Type> begin();
	LinkedListIterator<Type> end();
	friend void operator<<(ostream &out, const LinkedListType<Type> &other)
	{
		Node<Type> *temp = new Node<Type>();
		temp = other.first;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	LinkedListType<Type> &operator=(LinkedListType<Type> &other);
};
template <class Type>
class unorderdLinkedList : public LinkedListType<Type>
{
public:
	bool search(const Type &item) const;
	bool search2(const Type &item);
	void insertFirst(const Type &newitem);
	void insertLast(const Type &item);
	void deleteNode(const Type &item);
	Type RetrieveItem(int index);
	void ReplaceItem(int index, Type new_value);
	void insertAT(int index, Type element);
	void deleteAT(int index);
	void TraverseList();
	Type operator[](int index);
};
template <class Type>
class LinkedListIterator
{
private:
	Node<Type> *current;

public:
	LinkedListIterator();
	LinkedListIterator(Node<Type> *ptr);
	Type operator*();
	LinkedListIterator<Type> operator++();
	bool operator==(const LinkedListIterator<Type> &other) const;
	bool operator!=(const LinkedListIterator<Type> &other) const;
};
template <class Type>
LinkedListType<Type>::LinkedListType()
{
	count = 0;
	first = nullptr;
	last = nullptr;
}
template <class Type>
LinkedListType<Type>::LinkedListType(LinkedListType<Type> &other)
{
	copyLinkedList(other);
}
template <class Type>
LinkedListType<Type>::~LinkedListType()
{
	delete first;
	delete last;
}
template <class Type>
bool LinkedListType<Type>::isEmptyList() const
{
	return first == nullptr;
}
template <class Type> // UNORDERD LINKED LIST
bool unorderdLinkedList<Type>::search(const Type &item) const
{
	Node<Type> *temp = this->first;
	while (temp != nullptr)
	{

		if (temp->data == item)
			return true;
		temp = temp->next;
	}
	return false;
}
template <class Type> // UNORDERD LINKED LIST
bool unorderdLinkedList<Type>::search2(const Type &item)
{
	LinkedListIterator<Type> ser(this->begin());
	for (auto a = ser; a != this->end(); ++a)
	{
		if (*a == item)
			return true;
	}
	return false;
}
template <class Type> // UNORDERD LINKED LIST
void unorderdLinkedList<Type>::insertFirst(const Type &item)
{
	Node<Type> *newnode = new Node<Type>();
	newnode->data = item;
	newnode->next = this->first;
	this->first = newnode;
	this->count++;
	if (this->last == nullptr)
		this->last = newnode;
}
template <class Type> // UNORDERD LINKED LIST
void unorderdLinkedList<Type>::insertLast(const Type &item)
{
	Node<Type> *newnode = new Node<Type>();
	newnode->data = item;
	if (this->isEmptyList())
	{
		this->first = this->last = newnode;
		this->count++;
	}
	else
	{
		this->count++;
		this->last->next = newnode;
		this->last = newnode;
	}
}
template <class Type> // UNORDERD LINKED LIST
void unorderdLinkedList<Type>::deleteNode(const Type &item)
{
	if (this->first->data == item)
	{
		this->deleteFirst();
	}
	else if (this->last->data == item)
	{
		Node<Type> *delptr = this->last;
		Node<Type> *temp = this->first;
		Node<Type> *prev = nullptr;
		while (temp != this->last)
		{
			prev = temp;
			temp = temp->next;
		}
		this->last = prev;
		delete delptr;
		this->last->next = nullptr;
		this->count--;
	}
	else
	{
		Node<Type> *current = this->first;
		Node<Type> *prev = nullptr;
		while (current->data != item)
		{
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		delete current;
		this->count--;
	}
}
template <class Type>
void LinkedListType<Type>::deleteFirst()
{
	Node<Type> *temp = first;
	if (first->next == nullptr)
		last = nullptr;
	first = first->next;
	count--;
	delete temp;
}
template <class Type>
void LinkedListType<Type>::initialize()
{
	while (!isEmptyList())
	{
		deleteFirst();
	}
}
template <class Type>
void LinkedListType<Type>::print1() const
{
	if (isEmptyList())
	{
		cout << "The List Is Empty!" << endl;
	}
	else
	{
		Node<Type> *temp = first;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
template <class Type>
void LinkedListType<Type>::print2()
{
	if (isEmptyList())
	{
		cout << "The List Is Empty!" << endl;
	}
	else
	{
		LinkedListIterator<Type> x(this->begin());
		for (auto a = x; a != this->end(); ++a)
			cout << *a << " ";
		cout << endl;
	}
}
template <class Type>
int LinkedListType<Type>::length() const
{
	return count;
}
template <class Type>
void LinkedListType<Type>::destroyList()
{
	initialize();
}
template <class Type>
Type LinkedListType<Type>::Front() const
{
	return first->data;
}
template <class Type>
Type LinkedListType<Type>::Back() const
{
	return last->data;
}
template <class Type>
void LinkedListType<Type>::copyLinkedList(LinkedListType<Type> &other)
{
	Node<Type> *current, *newnode;
	current = other.first;
	while (current != nullptr)
	{
		newnode = new Node<Type>();
		newnode->data = current->data;
		if (first == nullptr)
		{
			first = last = newnode;
		}
		else
			last->next = newnode;
		last = newnode;
		current = current->next;
	}
}
template <class Type>
LinkedListType<Type> &LinkedListType<Type>::operator=(LinkedListType<Type> &other)
{
	copyLinkedList(other);
	return *this;
}
//-------------------------------------------------------------------------------------------------------------
// LINKED LIST ITERATOR
template <class Type>
LinkedListIterator<Type>::LinkedListIterator()
{
	current = nullptr;
}
template <class Type>
LinkedListIterator<Type>::LinkedListIterator(Node<Type> *ptr)
{
	current = ptr;
}
template <class Type>
LinkedListIterator<Type> LinkedListType<Type>::begin()
{
	LinkedListIterator<Type> temp(first);
	return temp;
}
template <class Type>
LinkedListIterator<Type> LinkedListType<Type>::end()
{
	LinkedListIterator<Type> temp(nullptr);
	return temp;
}
template <class Type>
Type LinkedListIterator<Type>::operator*()
{
	return current->data;
}
template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++()
{
	current = current->next;
	return *this;
}
template <class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator<Type> &other) const
{
	return current == other.current;
}
template <class Type>
bool LinkedListIterator<Type>::operator!=(const LinkedListIterator<Type> &other) const
{
	return current != other.current;
}
//--------------------------------------------------------------------------------------------
// TASK 5
template <class Type>
void unorderdLinkedList<Type>::ReplaceItem(int index, Type new_value)
{
	if (index < 0 || index >= this->count)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	Node<Type> *current = this->first;
	for (int i = 0; i < index; ++i)
	{
		current = current->next;
	}
	current->data = new_value;
}
template <class Type>
Type unorderdLinkedList<Type>::RetrieveItem(int index)
{
	if (index < 0 || index >= this->count)
	{
		cout << "Invalid index!" << endl;
		return 0;
	}
	Node<Type> *current = this->first;
	LinkedListIterator<Type> temp(current);
	for (int i = 0; i < index; ++i)
	{
		++temp;
	}
	return *temp;
}
template <class Type>
void unorderdLinkedList<Type>::insertAT(int index, Type element)
{
	if (index < 0 || index > this->count)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	if (index == 0)
	{
		this->insertFirst(element);
	}
	else
	{
		this->insertLast(element);
	}
}
template <class Type>
void unorderdLinkedList<Type>::deleteAT(int index)
{
	if (index < 0 || index >= this->count)
	{
		cout << "Invalid index!" << endl;
		return;
	}

	Node<Type> *temp = this->first;
	if (index == 0)
	{
		this->deleteFirst();
	}
	else
	{
		Node<Type> *prev = nullptr;
		for (int i = 0; i < index; ++i)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete temp;
		if (index == this->count - 1)
		{
			this->last = prev;
		}
		this->count--;
	}
}
template <class Type>
void unorderdLinkedList<Type>::TraverseList()
{
	this->print2();
}
template<class Type>
Type unorderdLinkedList<Type>::operator[](int index)
{
	if (index < 0 || index >= this->count) {
		cout << "Invalid index!" << endl;
		return 0;
	}
	Node<Type>* current = this->first;
	LinkedListIterator<Type> temp(current);
	for (int i = 0; i < index; ++i) {
		++temp;
	}
	return *temp;
}
int main()
{
	unorderdLinkedList<int> x;
	x.insertAT(0, 1);
	x.insertAT(1, 2);
	x.insertAT(2, 3);
	x.insertAT(3, 4);
	// x.deleteAT(0);
	x.ReplaceItem(2, 5);
	cout << x.RetrieveItem(3) << endl;
	cout << x[2];
	cout << x;
	return 0;
}
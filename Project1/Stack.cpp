#include "Header.h"

Stack::Stack() {}

Stack::Stack(int a)
{
	tail = new Node();
	tail->prev = tail;
	tail->next = tail;
	tail->a = a;
	count = 0;

}

Stack& Stack::operator=(Stack&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete tail;
	delete next;
	tail = other.tail;
	other.tail = nullptr;
}

int Stack::GetSize() const
{
	return count;
}

void Stack::Push(const int a)
{
	Node* newnode = new Node();
	Node* checking = next;
	if (HasElements())
	{
		while (checking->next != tail)
		{
			checking = checking->next;
		}
		checking->next = newnode;
		tail->prev = next;
	}
	else
	{
		tail = newnode;
		next = newnode;
	}
	newnode->a = a;
	newnode->prev = checking;
	newnode->next = tail;
	count = count + 1;
}

void Stack::Pop(int& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	Node* temp = tail;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	a = temp->a;
	next = temp;
	if (next != tail)
	{
		next->prev->next = tail;
	}
	else
	{
		next = tail = nullptr;
	}
	count = count - 1;
}

void Stack::Peek(int& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	Node* temp = next;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	a = temp->a;
}


bool Stack::HasElements() const
{
	if (this->tail != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


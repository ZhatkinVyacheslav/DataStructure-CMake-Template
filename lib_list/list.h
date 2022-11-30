#pragma once

#include <iostream>
#include <ostream>

template <class Type>
class CNode
{
	Type data;
	CNode<Type>* next;

public:
	CNode(Type val)
	{
		data = val;
		next = nullptr;
	}

	void set_next(CNode* newnext) {
		next = newnext;
	}

	void print() {
		std::cout << data << " -> ";
	}

	CNode<Type>* get_next() {
		if (next == nullptr)
		{
			throw std::logic_error("ERROR! next = nullptr");
		}
		else return next;
	}

	int get_data()
	{
		return data;
	}

};

template <class Type>
class Clist
{
	CNode<Type>* head;
	CNode<Type>* tail;
public:
	Clist() {
		head = nullptr;
		tail = nullptr;
	}
	
	size_t size()
	{
		size_t len = 0;
		CNode* head_copy = head;
		while (head_copy != nullptr)
		{
			head_copy = head_copy->get_next();
			len++;
		}
		return len;
	}
	
	void push_back(Type val)
	{
		CNode<Type>* newnode = new CNode<Type>(val);
		if (this->isEmpty())
		{
			head = newnode;
			tail = newnode;		
		}
		else {
			tail->set_next(newnode);
			tail = newnode;
		}
	}

	void push_front(Type val) {
		CNode<Type>* newnode = new CNode<Type>(val);
		if (this->isEmpty())
		{
			head = newnode;
			tail = newnode;
		}
		else {
			newnode->set_next(head);
			head = newnode;
		}
	}

	void insert(CNode<Type>* pos, int val)
	{
		if (pos == nullptr) {
			throw std::logic_error("ERROR! pos = 0");
		}
		else {
			CNode<Type>* newnode = new CNode(val);
			newnode->set_next(pos->get_next());
			pos->set_next(newnode);
			if (newnode->get_next() == nullptr) tail = newnode;		
		}
	}

	void pop_front() {
		if (isEmpty()) throw std::logic_error("beda");
		else {
			CNode<Type>* head_copy = head;
			head = head->get_next();
			delete head_copy;
		}
	}

	void pop_back() {
		if (isEmpty()) throw std::logic_error("beda");
		else
		{
			CNode<Type>* tail_copy = tail;
			tail = head;
			while (tail->get_next() != tail_copy)
			{
				tail = tail->get_next();
			}
			delete tail_copy;
		}
	}

	void printAll() 
	{
		CNode<Type>* head_copy = head;
		do
		{
			head_copy->print();
			head_copy = head_copy->get_next();
		} while (head_copy != tail);
		head_copy->print();
	}

	CNode<Type>* GetLastData() {
		return tail;
	}

	CNode<Type>* GetFirstData() {
		return head;
	}

	bool isEmpty() {
		if (head == nullptr) return true;
		else return false;
	}

};

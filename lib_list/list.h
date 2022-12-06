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
		/*if (next == nullptr)
		{
			throw std::logic_error("ERROR! next = nullptr");
		}
		else*/ return next;
	}

	Type get_data()
	{
		return data;
	}

};

template <class Type>
class Clist
{
protected:
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
		CNode<Type>* head_copy = head;
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
			CNode<Type>* newnode = new CNode<Type>(val);
			newnode->set_next(pos->get_next());
			pos->set_next(newnode);
			if (newnode->get_next() == nullptr) tail = newnode;		
		}
	}

	void erase(CNode<Type>* pos) {
		if (pos < 0) throw std::logic_error("Pos < 0");	
		if (isEmpty()) throw std::logic_error("beda");

		if (pos != head)
		{
			CNode<Type>* copy = head;
			CNode<Type>* DeletedNode = head->get_next();
			int i = 0;
			while (DeletedNode != pos)
			{
				i++;
				copy = copy->get_next();
				DeletedNode = DeletedNode->get_next();
			}
			copy->set_next(DeletedNode->get_next());
			DeletedNode = nullptr;
		}
		else
		{
			this->pop_front();
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
			tail_copy = nullptr;
		}
	}

	void printAll()
	{
		if (this->isEmpty())
		{
			std::cout << "Is empty";
		}
		else
		{
			CNode<Type>* head_copy = head;
			do
			{
				head_copy->print();
				head_copy = head_copy->get_next();
			} while (head_copy != nullptr);
			//head_copy->print();
		}
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

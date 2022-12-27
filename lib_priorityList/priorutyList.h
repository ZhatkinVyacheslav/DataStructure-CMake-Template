#pragma once
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <iomanip>
#include <iostream>

using namespace std;

template <class Type>
class PriorityCNode
{
protected:
	pair <int, Type> pdata;
	PriorityCNode<Type>* next;

public:
	PriorityCNode(int priority, Type val)
	{
		pair <int, Type> para{ priority , val };
		pdata = para;
		next = nullptr;
	}

	void set_next(PriorityCNode<Type>* newnext) {
		next = newnext;
	}

	void print() {
		std::cout << "(" << pdata.first << " ; " << pdata.second << ") -> ";
	}

	PriorityCNode<Type>* get_next() {
		/*if (next == nullptr)
		{
			throw std::logic_error("ERROR! next = nullptr");
		}
		else*/ return next;
	}

	int get_data_first()
	{
		return pdata.first;
	}

	Type get_data_second()
	{
		return pdata.second;
	}
};

template <class Type>
class PriorityCList
{
protected:
	PriorityCNode<Type>* head;
	PriorityCNode<Type>* tail;

public:
	PriorityCList() {
		head = nullptr;
		tail = nullptr;
	}
	 
	size_t size()
	{
		size_t len = 0;
		PriorityCNode<Type>* head_copy = head;
		if (head == tail && head != nullptr)
		{
			return 1;
		}
		else {
			while (head_copy != tail)
			{
				head_copy = head_copy->get_next();
				len++;
			}
			return len;
		}
	}

	void push_back(int priritet, Type val)
	{
		PriorityCNode<Type>* newnode = new PriorityCNode<Type>(priritet, val);
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

	void push_back_priority(int priritet, Type val )
	{
		PriorityCNode<Type>* newnode = new PriorityCNode<Type>(priritet, val);
		PriorityCNode<Type>* cur = head;
		if (this->isEmpty())
		{
			head = newnode;
			tail = newnode;
		}
		else {

			if (newnode->get_data_first() > head->get_data_first()) {
				newnode->set_next(head);
				head = newnode;
			}
			else
			{
				
				while ((newnode->get_data_first() >= cur->get_next()->get_data_first()) && (cur->get_next() != tail)) {
					cur = cur->get_next();
				}
				if (cur->get_next() == tail && newnode->get_data_first() < tail->get_data_first())
				{
					tail->set_next(newnode);
					tail = newnode;
				}
				else
				{
					newnode->set_next(cur->get_next());
					cur->set_next(newnode);
				}
			}
		}
	}

	void pop_front() {
		if (isEmpty()) throw std::logic_error("beda");
		else {
			PriorityCNode<Type>* head_copy = head;
			head = head->get_next();
			delete head_copy;
		}
	}

	void pop_front_priority() {
		if (isEmpty()) throw std::logic_error("beda");
		else {
			PriorityCNode<Type>* cur = head;
			PriorityCNode<Type>* res = head;
			if (tail == head)
			{
				delete cur;
			}
			else
			{
				while (cur->get_next() != tail)
				{
					if (res->get_data_first() < cur->get_data_first()) {
						res = cur;
					}
					cur = cur->get_next();
					if (cur->get_next() == tail) {
						if (res->get_data_first() < cur->get_data_first())
						{
							res = cur;
						}
					}
				}

				if (res->get_data_first() < tail->get_data_first())
				{
					res = tail;
					tail = cur;
					delete res;
				}
				else {
					if (res == head)
					{
						head = res->get_next();
						delete res;
					}
					else
					{
						cur = head;
						while (cur->get_next() != res)
						{
							cur = cur->get_next();
						}
						cur->set_next(res->get_next());
						delete res;
					}
				}
			}			
		}
	}

	void print()
	{
		if (this->isEmpty())
		{
			std::cout << "Is empty";
		}
		else
		{
			PriorityCNode<Type>* head_copy = head;
			if (tail == head)
			{
				head->print();
			}
			else{
				while (head_copy->get_next() != tail)
				{
					head_copy->print();
					head_copy = head_copy->get_next();
				}
				head_copy->print();
				tail->print();
			}
		}
	}

	Type GetFirstValuePriority() {
		if (isEmpty()) throw std::logic_error("beda");
		else {
			PriorityCNode<Type>* cur = head;
			PriorityCNode<Type>* res = head;
			if (tail == head)
			{
				return head->get_data_second();
			}
			else
			{
				while (cur->get_next() != tail)
				{
					if (res->get_data_first() < cur->get_data_first()) {
						res = cur;
					}
					cur = cur->get_next();
					if (cur->get_next() == tail) {
						if (res->get_data_first() < cur->get_data_first())
						{
							res = cur;
						}
					}
				}

				if (res->get_data_first() < tail->get_data_first())
				{
					return res->get_data_second();
				}
				else {
					if (res == head)
					{
						return res->get_data_second();
					}
					else
					{
						cur = head;
						while (cur->get_next() != res)
						{
							cur = cur->get_next();
						}
						return res->get_data_second();
					}
				}
			}
		}
	}

	Type GetFirstValue() {
		return head->get_data_second();
	}

	PriorityCNode<Type>* GetLastData() {
		return tail;
	}

	PriorityCNode<Type>* GetFirstData() {
		return head;
	}

	bool isEmpty() {
		if (head == nullptr) return true;
		else return false;
	}

};









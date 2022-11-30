#include <iostream>
#include <ostream>
#include "../lib_list/list.h"


template <class Type>
class Queue {

	Clist<Type> data;
	size_t size;

public:

	Queue() {
		size = 0;
	}

	int End() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Queue is empty");
		}
		CNode<Type>* copy = data.GetLastData();
		return copy->get_data();
	}

	int Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Queue is empty");
		}
		CNode<Type>* copy = data.GetFirstData();
		return copy->get_data();
	}

	int Pop() {
		if (!isEmpty()) {
			CNode<Type>* copy = data.GetFirstData();
			data.pop_front();
			size--;
			return copy->get_data();
		}
		else {
			throw std::logic_error("Error!!! Queue is empty");
		}
	}

	void push(const int val)
	{		
		size++;
		data.push_back(val);
	}

	void Print() {
		data.printAll();
	}

	bool isEmpty() {
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
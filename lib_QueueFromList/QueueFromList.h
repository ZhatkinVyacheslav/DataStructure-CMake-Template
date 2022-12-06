#include <iostream>
#include <ostream>
#include "../lib_list/list.h"


template <class Type>
class LQueue {

private:
	Clist<Type> data;
	size_t size;

public:

	LQueue() {
		size = 0;
	}

	size_t GetSize()
	{
		return size;
	}

	Type End() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Queue is empty");
		}
		else {
			CNode<Type>* copy = data.GetLastData();
			return copy->get_data();
		}
	}

	Type Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Queue is empty");
		}
		CNode<Type>* copy = data.GetFirstData();
		return copy->get_data();
	}

	void Pop() {
		if (!isEmpty()) {
			data.pop_front();
			size--;
		}
		else {
			throw std::logic_error("Error!!! Queue is empty");
		}
	}

	void Push(const Type val)
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
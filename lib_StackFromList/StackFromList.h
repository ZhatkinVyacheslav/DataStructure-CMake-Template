#include <iostream>
#include <ostream>
#include "../lib_list/list.h"

class StackFromList {

	Clist data;
	size_t size;

public:
	StackFromList() {
		size = 0;
	}
	
	StackFromList(int a) {
		size = 1; 
		data.push_back(a);
	}

	void Push(int a) {
		data.push_back(a);
		size++;
	}

	int Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Stack is empty");
		}
		else {
			CNode* copy = data.GetLastData();
			return copy->get_data();
		}
	}

	int Pop() {
		if (!isEmpty()) {
			CNode* copy = data.GetLastData();
			data.pop_back();
			size--;
			int copy2 = copy->get_data();
			return copy2;
		}
		else {
			throw std::logic_error("Error!!! Stack is empty");
		}
	}

	size_t Size() {
		return size;
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
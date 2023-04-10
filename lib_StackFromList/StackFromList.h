#pragma once
#include <iostream>
#include <ostream>
#include "../lib_list/list.h"


template <class Type>
class StackFromList {

	Clist<Type> data;
	size_t size;

public:
	StackFromList() {
		size = 0;
	}
	

	void Push(Type a) {
		data.push_back(a);
		size++;
	}

	Type Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Stack is empty");
		}
		else {
			CNode<Type>* copy = data.GetLastData();
			return copy->get_data();
		}
	}

	Type Pop() {
		if (!isEmpty()) {
			CNode<Type>* copy = data.GetLastData();
			Type copy2 = copy->get_data();
			data.pop_back();
			size--;
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
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};
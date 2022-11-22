#include <iostream>
#include <ostream>

template <class Type> class Queue;
template <class Type> std::ostream& operator <<(std::ostream& out, const Queue<Type>& pair);

template <class Type>
class Queue {
	Type* data;
	size_t top;
	size_t size;
	size_t end;

public:
	Queue(size_t size1) {
		if (size1 < 1)
		{
			throw std::logic_error("Error!!! Size cant be <1");
		}
		size = size1;
		top = 0;
		end = -1;
		data = new Type[size1];
	}

	Type Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Stack is empty");
		}
		return data[this->top];
	}

	Type End()
	{
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Stack is empty");
		}
		return data[this->end];
	}

	Type Pop()
	{
		if (!isEmpty()) {
			Type copy = this->Top();
			top++;
			return data[copy];
		}
		else {
			throw std::logic_error("Error!!! Stack is empty");
		}
	}

	void push(const Type& val)
	{
		if (!isFull()) {
			end++;
			data[end] = val;
		}
		else {
			throw std::logic_error("Error!!!Stack is full");
		}
	}

	bool isFull() {
		if (top == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() {
		if (top < end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend std::ostream& operator<<  <Type>(std::ostream& out, const Queue& queue);

};

template <class Type>
std::ostream& operator<< (std::ostream& out, const Queue<Type>& queue) {
	for (int i = queue.top; i <= queue.end; i++)
	{
		std::cout << "\n| " << stack.data[i] << " |";
	}
}

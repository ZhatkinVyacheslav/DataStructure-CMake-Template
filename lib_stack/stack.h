#include <iostream>
#include <ostream>

template <class Type> class Stack;
template <class Type> std::ostream& operator <<(std::ostream& out, const Stack<Type>& pair);

template <class Type>
class Stack {
	Type* data;
	size_t top;
	size_t size;

public:

	Stack(int size1) {

		if (size1 < 1)
		{
			throw std::logic_error("Error!!! Size cant be <1");
		}
		size = size1;
		top = -1;
		data = new Type[size1];
	}

	Type Top() {
		if (this->isEmpty())
		{
			throw std::logic_error("Error!!! Stack is empty");
		}
		return data[this->top];
	}

	void push(const Type& val)
	{
		if (!isFull()) {
			top++;
			data[top] = val;
		}
		else {
			throw std::logic_error("Error!!!Stack is full");
		}
	}

	Type Pop()
	{
		if (!isEmpty()) {
			Type copy = this->Top();
			top--;
			return copy;
		}
		else {
			throw std::logic_error("Error!!! Stack is empty");
		}
	}

	bool isFull() {
		if (top == (size - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() {
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend std::ostream& operator<<  <Type>(std::ostream& out, const Stack& stack);

	~Stack() {
		delete[] data;
	}
};

template <class Type>
std::ostream& operator<< (std::ostream& out, const Stack<Type>& stack) {
	for (int i = 0; i <= stack.top; i++)
	{
		std::cout << "\n| " << stack.datd[i] << " |";
	}
}


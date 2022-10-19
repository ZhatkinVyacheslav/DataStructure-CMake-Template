#include <iostream>
#include <ostream>

template <class Type> class TPair;
template <class Type> std::ostream& operator <<(std::ostream& out, const TPair<Type>& pair);

template <class Type>
class Stack {
	T* data;
	size_t top;
	size_t size;

public:

	Stack()

	void push(const T& val)
	{
		if (!isFull()) {
			top++;
			data[top] = val;
		}
		else {
			throw std::logic_error("Error!!!Stack is full");
		}
	}

	void pop()
	{
		if (!isEmpty()) {
			top--;
		}
		else {
			throw std::logic_error("Error!!! Stack is empty");
		}
	}

	bull isFull() {
		if (top == (size - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bull isEmpty() {
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend std::ostream& operator<<  <Type>(std::ostream& out, const Stack& stack) {};

	~Stack() {
		delete[] data;
	}
};

template <class Type>
std::ostream& operator<<  <Type>(std::ostream& out, const Stack<Type>& stack) {
	for (int i = 0; i <= stack.top; i++)
	{
		std::cout << "\n| " << stack.datd[i] << " |";
	}
}


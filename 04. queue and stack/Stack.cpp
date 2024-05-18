#include "Stack.h"
#include <algorithm>
using namespace std;

template <class T>
void ChangeSize1D(T*& t, const int oldSize, const int newSize) {
	if (newSize < 0) throw "Length must be >= 0";

	T* temp = new T[newSize];
	int size = min(oldSize, newSize);
	copy(t, t + size, temp);
	delete[] t;
	t = temp;
}

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T> ::Top() const
{
	if (IsEmpty()) throw "Stack is empty";
	return stack[top];
}

template <class T>
void Stack<T>::Push(const T& x)
{
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

template <class T>
void Stack<T> ::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}

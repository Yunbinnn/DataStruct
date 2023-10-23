#pragma once
#include "using_std.h"

#define SIZE 5

template <typename T>
class Stack
{
private:
	int top;
	T buffer[SIZE];

public:
	Stack()
	{
		top = -1;
	}

	T& Top()
	{
		return buffer[top];
	}

	int Size()
	{
		return top + 1;
	}

	bool Empty()
	{
		if (top <= -1) return true;
		else return false;
	}

	bool IsFull()
	{
		if (SIZE - 1 <= top) return true;
		else return false;
	}

	void Push(T data)
	{
		if (IsFull()) cout << "Stack Overflow" << endl;
		else buffer[++top] = data;
	}

	void Pop()
	{
		if (Empty()) cout << "Stack is Empty" << endl;
		else top--;
	}

	~Stack() { ; }
};
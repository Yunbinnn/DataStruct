#pragma once
#include "using_std.h"

#pragma region 선형 큐
// 배열의 공간에 들어간 데이터가 고정되어 데이터를
// 빼내더라도 초기화하지 않으며 원래 데이터가
// 있던 배열의 자리에 더 이상 다른 값이 들어갈 수 없는 Queue 입니다.

#pragma endregion

#define SIZE 5

template <typename T>
class LinearQueue
{
private:
	int front;
	int rear;
	int size;
	T linearQueue[SIZE];

public:
	LinearQueue()
	{
		front = 0;
		rear = 0;
		size = 0;
	}

	bool IsEmpty()
	{
		return front == rear ? true : false;
	}

	bool IsFull()
	{
		return rear == SIZE ? true : false;
	}

	int& Size() const
	{
		return size;
	}

	void Enqueue(T data)
	{
		if (IsFull()) cout << "Queue is Full" << endl;
		else
		{
			linearQueue[rear++] = data;
			size++;
		}
	}

	void Dequeue()
	{
		if (IsEmpty()) cout << "Queue is Empty" << endl;
		else
		{
			linearQueue[front++] = NULL;
			size--;
		}
	}

	void Display()
	{
		for (int i = front; i < rear; i++)
		{
			cout << linearQueue[i] << " ";
		}

		cout << endl;
	}

	T& Front()
	{
		if (IsEmpty()) exit(1);
		else return linearQueue[front];
	}

	T& Back()
	{
		if (IsEmpty()) exit(1);
		else return linearQueue[rear - 1];
	}

	~LinearQueue() { ; }
};
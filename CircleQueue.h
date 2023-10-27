#pragma once
#include "using_std.h"

constexpr auto SIZE = 4;

#pragma region 원형 큐
// 물리적으로는 선형 구조를 가지고 있으며,
// 큐의 시작점과 끝점을 연결한 큐입니다.
#pragma endregion

template<typename T>
class CircleQueue
{
private:
	int front;
	int rear;

	T buffer[SIZE];

public:
	CircleQueue() {
		front = rear = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
			buffer[i] = NULL;
	}

	bool IsEmpty() {
		return front == rear ? true : false;
	}

	bool IsFull() {
		return front == (rear + 1) % SIZE ? true : false;
	}

	T& Front() {
		return buffer[(front + 1) % SIZE];
	}

	T& Back() {
		return buffer[rear];
	}

	void Enqueue(T data) {
		if (IsFull()) cout << "Queue is Full" << endl;
		else buffer[rear = (rear + 1) % SIZE] = data; 
	}

	void Dequeue() {
		if (IsEmpty()) cout << "Queue is Empty" << endl;
		else front = (front + 1) % SIZE; 
	}

	void Display() {
		cout << "현재 Queue에 담긴 data : ";
		
		for (int i = (front + 1) % SIZE; i != (rear + 1) % SIZE; i = (i + 1) % SIZE)
			cout << buffer[i] << " ";

		cout << endl;
	}

	~CircleQueue() { ; }
};
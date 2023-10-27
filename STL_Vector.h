#pragma once
#include "using_std.h"

template<typename T>
class STL_VECTOR
{
private:
	int size;
	int capacity;
	T* bufferPointer;

public:
	STL_VECTOR()
	{
		size = 0;
		capacity = 0;
		bufferPointer = nullptr;
	}

	int Size()
	{
		return size;
	}
	
	int Capacity()
	{
		return capacity;
	}

	T& Front() 
	{
		return bufferPointer[0];
	}

	T& Back()
	{
		return bufferPointer[size - 1];
	}

	T* Begin()
	{
		return bufferPointer;
	}

	T* End()
	{
		return bufferPointer + size;
	}

	bool IsFull()
	{
		return size >= capacity ? true : false;
	}

	void Resize(int newSize)
	{
		capacity = newSize;
		T* tempBuffer = new T[capacity];

		for (int i = 0; i < capacity; i++) tempBuffer[i] = NULL;

		for (int i = 0; i < size; i++) tempBuffer[i] = bufferPointer[i];

		if (bufferPointer != nullptr) delete[] bufferPointer;

		bufferPointer = tempBuffer;
	}

	void Push_Back(T data)
	{
		if (capacity == 0) Resize(1);
		else if (IsFull())
		{
			capacity *= 2;
			Resize(capacity);
		}

		bufferPointer[size++] = data;
	}

	void Pop_Back()
	{
		size = size > 0 ? size - 1 : 0;
	}

	T& operator[](const int value) { return bufferSize[value]; }

	~STL_VECTOR()
	{
		delete[] bufferPointer;
	}
};
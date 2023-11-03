#pragma once
#include "using_std.h"

constexpr auto SIZE = 8;

template <typename T>
class MaxHeap
{
private:
	T heap[SIZE];
	int heapCount;

public:
	MaxHeap()
	{
		for (int i = 0; i < SIZE; i++) heap[i] = NULL;
		heapCount = 0;
	}

	void Insert(T data)
	{
		if (IsFull())
		{
			cout << "리스트가 가득 차 있습니다." << endl;
			return;
		}
		else
		{
			cout << "Insert : " << data << endl;

			heap[++heapCount] = data;

			int child = heapCount;
			int parent = child / 2;

			while (child > 1 && heap[child] > heap[parent])
			{
				swap(heap[child], heap[parent]);
				child = parent;
				parent = child / 2;
			}
		}
	}

	void Delete()
	{
		if (heapCount <= 0)
		{
			cout << "리스트가 비어 있습니다." << endl;
			return;
		}
		else
		{
			T result = heap[1];
			cout << "\nDelete : " << result << endl;
			heap[1] = heap[heapCount];

			heap[heapCount--] = NULL;

			int parent = 1;
			int child = 2;

			if (child + 1 <= heapCount)
				if (heap[child] <= heap[child + 1])
					child = child + 1;

			while (child > 1 && heap[child] > heap[parent])
			{
				swap(heap[child], heap[parent]);

				parent = child;
				child = parent / 2;

				if (child + 1 <= heapCount)
					if (heap[child] <= heap[child + 1])
						child = child + 1;
			}
		}
	}

	bool IsFull()
	{
		if (heapCount == SIZE - 1) return true;
		else return false;
	}

	void Display()
	{
		for (const T& element : heap)
		{
			cout << element << " ";
		}
		cout << "\n";
	}
};
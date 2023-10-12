#pragma once

template <typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;

		Node* prev;
		Node* next;
	};

	Node* head;
	Node* tail;

	int size;

public:
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void Show()
	{
		Node* currentNode = head->next;
		while (currentNode!=tail)
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}

	void Insert(T _data)
	{
		Node* newNode = new Node;
		newNode->data = _data;

		Node* currentNode;
		currentNode = head->next;

		Node* prev = currentNode->prev;
		prev->next = newNode;

		currentNode->prev = newNode;
		newNode->next = currentNode;
	}

};
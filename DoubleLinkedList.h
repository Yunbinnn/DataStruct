#pragma once
#include <iostream>
using namespace std;

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

	void Push_Back(T _data)
	{
		Node* newNode = new Node;

		newNode->data = _data;

		newNode->next = nullptr;
		newNode->prev = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->prev = tail;

			tail->next = newNode;

			tail = newNode;
		}

		size++;
	}

	void Push_Front(T _data)
	{
		Node* newNode = new Node;

		newNode->data = _data;

		newNode->next = nullptr;
		newNode->prev = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else if (size == 1)
		{
			Node* deleteNode = head;

			head = nullptr;
			tail = nullptr;

			delete deleteNode;
		}
		else
		{
			newNode->next = head;

			head->prev = newNode;

			head = newNode;
		}

		size++;
	}

	void Pop_Front()
	{
		if (head == nullptr)
		{
			cout << "데이터가 비어있습니다." << endl;
			return;
		}
		
		Node* deleteNode = head;

		head = head->next;							

		head->prev = nullptr;

		delete deleteNode;

		size--;
	}

	void Pop_Back()
	{
		if (head == nullptr)
		{
			cout << "데이터가 y0." << endl;
			return;
		}
		else
		{
			Node* deleteNode = tail;

			tail = tail->prev;

			tail->next = nullptr;

			delete deleteNode;
		}

		size--;
	}

	void Insert(int _size, T _data)
	{
		if (_size <= 1)
		{
			Push_Front(_data);
			return;
		}

		Node* newNode = new Node;

		newNode->data = _data;

		newNode->next = nullptr;
		newNode->prev = nullptr;

		Node* searchNode = head;
		Node* prevNode;

		for (int i = 1; i < _size; i++)
		{
			searchNode = searchNode->next;
		}

		prevNode = searchNode->prev;

		newNode->next = searchNode;
		searchNode->prev = newNode;

		prevNode->next = newNode;
		newNode->prev = prevNode;

		size++;
	}

	int Size()
	{
		return size;
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

	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			Node* deleteNode = head;

			head = head->next;

			delete deleteNode;
		}
	}
};
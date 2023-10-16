#pragma once
#include <iostream>
using namespace std;

template <typename T>
class CircleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	int size;
	Node* head;

public:
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void Print_List()
	{
		Node* printNode = head->next;

		int listSize = Size();

		if (printNode == nullptr)
		{
			cout << "데이터가 비어있습니다." << endl;
			return;
		}
		else
		{
			while (listSize)
			{
				cout << printNode->data << endl;
				printNode = printNode->next;
				listSize--;
			}
		}
	}

	void Push_Back(T _data)
	{
		Node* newNode = new Node;

		newNode->data = _data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}

		size++;
	}

	void Push_Front(T _data)
	{
		Node* newNode = new Node;

		newNode->data = _data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}

	void Pop_Back()
	{
		if (head == nullptr)
		{
			cout << "데이터가 비어있습니다." << endl;
			return;
		}

		Node* deleteNode = head;
		Node* searchNode = head;

		int listSize = Size();
		
		if (Size() == 1)
		{
			head = nullptr;

			delete deleteNode;
		}
		else
		{
			while (listSize != 1)
			{
				searchNode = searchNode->next;

				listSize--;
			}

			searchNode->next = deleteNode->next;

			head = searchNode;

			delete deleteNode;
		}

		size--;
	}

	void Pop_Front()
	{
		if (head == nullptr)
		{
			cout << "데이터가 비어있습니다." << endl;
			return;
		}

		Node* deleteNode = head;

		if (Size() == 1)
		{
			head = nullptr;

			delete deleteNode;
		}
		else
		{
			deleteNode = deleteNode->next;
			head->next = deleteNode->next;
			delete deleteNode;
		}

		size--;
	}

	int Size()
	{
		return size;
	}

	~CircleLinkedList()
	{
		while (Size())
		{
			Pop_Back();
			cout << "소멸자 호출" << endl;
		}
	}
};
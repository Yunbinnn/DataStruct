#pragma once
#include <iostream>
using namespace std;

#pragma region ���� ���� ����Ʈ

// 1. ���� ���� ����Ʈ ��� ����
struct Node
{
	int data;
	Node* next;
};

Node* CreateHead()
{
	Node* headNode = new Node;
	headNode->data = NULL;
	headNode->next = nullptr;
	return headNode;
}

void Push_Front(Node* _head, int _data)
{
	Node* newNode = new Node;

	newNode->data = _data;
	newNode->next = _head->next;

	_head->next = newNode;
}

#pragma endregion

int main()
{
#pragma region ��� ����� ����

	/*Node* head = CreateHead();

	Push_Front(head, 10);
	Push_Front(head, 20);
	Push_Front(head, 30);

	Node* currentPtr = head->next;

	while (currentPtr != nullptr)
	{
		cout << currentPtr->data << " ";
		currentPtr = currentPtr->next;
	}*/
#pragma endregion
	return 0;
}
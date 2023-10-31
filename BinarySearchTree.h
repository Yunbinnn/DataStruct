#pragma once
#include "using_std.h"

#pragma region 이진 탐색 트리(BST)
	// 임의의 키를 가진 원소를 삽입, 삭제, 검색하는데
	// 효율적은 알고리즘 입니다.

template<typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
	};

	Node* rootNode;

public:
	inline BinarySearchTree() { rootNode = nullptr; }

	Node* GetRoot() { return rootNode; }

	void Insert(T data, Node* root = rootNode)
	{
		if (root == nullptr)
		{
			root = new Node;
			root->data = data;
			root->leftChild = nullptr;
			root->rightChild = nullptr;
			return;
		}

		if (root->data > data) Insert(data, root->leftChild);
		else if (root->data < data) Insert(data, root->rightChild);
		else cout << "이미 존재하는 값 입니다." << endl;
	}

	T MaxValue(Node* root)
	{
		Node* currentNode = root;

		while(currentNode->rightChild != nullptr) currentNode = currentNode->rightChild;

		return currentNode->data;
	}

	void Inorder(Node* root)
	{
		Inorder(root->leftChild);
		cout << root->data << " ";
		Inorder(root->rightChild);
	}
};

#pragma endregion
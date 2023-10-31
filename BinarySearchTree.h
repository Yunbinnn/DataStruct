#pragma once
#include "using_std.h"

#pragma region ���� Ž�� Ʈ��(BST)
	// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ�
	// ȿ������ �˰��� �Դϴ�.

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
		else cout << "�̹� �����ϴ� �� �Դϴ�." << endl;
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
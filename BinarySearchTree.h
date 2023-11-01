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
		T data = NULL;
		Node* left = nullptr;
		Node* right = nullptr;
	};

public:
	Node* rootNode;

	inline BinarySearchTree() { rootNode = nullptr; }

	Node* GetRoot() const { return rootNode; }

	Node* Insert(T data, Node* root)
	{
		if (Find(root, data))
		{
			cout << "이미 존재하는 값 입니다." << endl;
			return root;
		}

		if (root == nullptr)
		{
			root = new Node;
			root->data = data;
			root->left = nullptr;
			root->right = nullptr;
		}
		else if (root->data > data) root->left = Insert(data, root->left);
		else if (root->data < data) root->right = Insert(data, root->right);

		return root;
	}

	Node* Delete(T data, Node* root)
	{
		if (root == nullptr) return root;
	}

	bool Find(Node* root, T data)
	{
		if (root == nullptr) return false;

		if (root->data == data) return true;
		else
			if (root->data > data) return Find(root->left, data);
			else return Find(root->right, data);
	}

	T& MaxValue(Node* root)
	{
		if (root == nullptr)
		{
			cout << "BST가 비어있습니다." << endl;
			exit(1);
		}

		if (root->right != nullptr) return MaxValue(root->right);
		else return root->data;
	}

	T& MinValue(Node* root)
	{
		if (root == nullptr)
		{
			cout << "BST가 비어있습니다." << endl;
			exit(1);
		}

		if (root->left != nullptr) return MinValue(root->left);
		else return root->data;
	}

	void Inorder(Node* root)
	{
		if (root)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
	}
};

#pragma endregion
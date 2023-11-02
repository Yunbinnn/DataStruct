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

	Node* Insert(Node* root, T data)
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
		else if (root->data > data) root->left = Insert(root->left, data);
		else if (root->data < data) root->right = Insert(root->right, data);

		return root;
	}

	Node* RemoveNode(Node* root, T data)
	{
		if (root == nullptr) return root;

		if (root->data > data) root->left = RemoveNode(root->left, data);
		else if (root->data < data) root->right = RemoveNode(root->right, data);
		else
		{
			Node* currentNode;

			// 자식이 하나 이거나 없는 경우
			if (root->left == nullptr)
			{
				currentNode = root->right;
				delete root;
				return currentNode;
			}
			else if (root->right == nullptr)
			{
				currentNode = root->left;
				delete root;
				return currentNode;
			}

			// 자식이 둘 있는 경우
			currentNode = MinValueNode(root->right);

			// 삭제할 노드의 데이터를 넣어줍니다.
			root->data = currentNode->data;
			
			// 노드를 삭제합니다.
			root->right = RemoveNode(root->right, currentNode->data);
		}

		return root;
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

	Node* MinValueNode(Node* root)
	{
		Node* currentNode = root;

		if (currentNode->left != nullptr) return MinValueNode(currentNode->left);

		return currentNode;
	}
};

#pragma endregion
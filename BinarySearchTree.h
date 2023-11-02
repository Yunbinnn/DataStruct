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
			cout << "�̹� �����ϴ� �� �Դϴ�." << endl;
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

			// �ڽ��� �ϳ� �̰ų� ���� ���
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

			// �ڽ��� �� �ִ� ���
			currentNode = MinValueNode(root->right);

			// ������ ����� �����͸� �־��ݴϴ�.
			root->data = currentNode->data;
			
			// ��带 �����մϴ�.
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
			cout << "BST�� ����ֽ��ϴ�." << endl;
			exit(1);
		}

		if (root->right != nullptr) return MaxValue(root->right);
		else return root->data;
	}

	T& MinValue(Node* root)
	{
		if (root == nullptr)
		{
			cout << "BST�� ����ֽ��ϴ�." << endl;
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
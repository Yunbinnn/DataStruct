#pragma once
#include "using_std.h"

#pragma region Ʈ��

struct TreeNode
{
	int data;

	TreeNode* left;
	TreeNode* right;
};

TreeNode* CreateNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
{
	// 1. ���ο� ��带 �����մϴ�.
	TreeNode* newNode = new TreeNode;

	// 2. ���ο� ����� data ���� �����մϴ�.
	newNode->data = data;

	// 3. ���ο� ����� left ���� �����մϴ�.
	newNode->left = left;

	// 4. ���ο� ����� right ���� �����մϴ�.
	newNode->right = right;

	// 5. ���ο� ����� �ּҰ��� ��ȯ�մϴ�.
	return newNode;
}

// ���� ��ȸ
// 1. Root Node�� �湮�մϴ�.
// 2. ���� ���� Ʈ���� ���� ��ȸ�մϴ�.
// 3. ������ ���� Ʈ���� ���� ��ȸ�մϴ�.
void Preorder(TreeNode* root)
{
	if (root)
	{
		cout << root->data;
		root->data == 7 ? cout << " " : cout << " �� ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

// ���� ��ȸ
// 1. ���� ���� Ʈ���� ���� ��ȸ�մϴ�.
// 2. Root Node�� �湮�մϴ�.
// 3. ������ ���� Ʈ���� ���� ��ȸ�մϴ�.
void Inorder(TreeNode* root)
{
	if (root)
	{
		Inorder(root->left);
		cout << root->data;
		root->data == 7 ? cout << " " : cout << " �� ";
		Inorder(root->right);
	}
}

// ���� ��ȸ
// 1. ���� ���� Ʈ���� ���� ��ȸ�մϴ�.
// 2. ������ ���� Ʈ���� ���� ��ȸ�մϴ�.
// 3. Root Node�� �湮�մϴ�.
void Postorder(TreeNode* root)
{
	if (root)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data;
		root->data == 1 ? cout << " " : cout << " �� ";
	}
}

#pragma endregion

int main()
{
#pragma region Ʈ��
	// �׷����� �������� ������ ������
	// �̿��Ͽ� �������� ��ġ ���¸� �߻�ȭ�� �ڷ� �����Դϴ�.

	TreeNode* node7 = CreateNode(7);
	TreeNode* node6 = CreateNode(6);
	TreeNode* node5 = CreateNode(5);
	TreeNode* node4 = CreateNode(4);
	TreeNode* node3 = CreateNode(3, node6, node7);
	TreeNode* node2 = CreateNode(2, node4, node5);
	TreeNode* node1 = CreateNode(1, node2, node3);

	cout << "���� ��ȸ : ";
	Preorder(node1);
	cout << "\n\n";
	cout << "���� ��ȸ : ";
	Inorder(node1);
	cout << "\n\n";
	cout << "���� ��ȸ : ";
	Postorder(node1);
	cout << "\n";

#pragma endregion

	return 0;
}
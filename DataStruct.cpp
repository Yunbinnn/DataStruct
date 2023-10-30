#include "using_std.h"

#pragma region 트리

struct TreeNode
{
	int data;

	TreeNode* left;
	TreeNode* right;
};

TreeNode* CreateNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
{
	// 1. 새로운 노드를 생성합니다.
	TreeNode* newNode = new TreeNode;

	// 2. 새로운 노드의 data 값을 저장합니다.
	newNode->data = data;

	// 3. 새로운 노드의 left 값을 저장합니다.
	newNode->left = left;

	// 4. 새로운 노드의 right 값을 저장합니다.
	newNode->right = right;

	// 5. 새로운 노드의 주소값을 반환합니다.
	return newNode;
}

// 전위 순회
// 1. Root Node를 방문합니다.
// 2. 왼쪽 서브 트리를 전위 순회합니다.
// 3. 오른쪽 서브 트리를 전위 순회합니다.
void Preorder(TreeNode* root)
{
	if (root)
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

// 중위 순회
// 1. 왼쪽 서브 트리를 전위 순회합니다.
// 2. Root Node를 방문합니다.
// 3. 오른쪽 서브 트리를 전위 순회합니다.
void Inorder(TreeNode* root)
{
	if (root)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}

// 후위 순회
// 1. 왼쪽 서브 트리를 전위 순회합니다.
// 2. 오른쪽 서브 트리를 전위 순회합니다.
// 3. Root Node를 방문합니다.
void Postorder(TreeNode* root)
{
	if (root)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}

#pragma endregion

int main()
{
#pragma region 트리
	// 그래프의 일종으로 정점과 간선을
	// 이용하여 데이터의 배치 형태를 추상화한 자료 구조입니다.

	TreeNode* node7 = CreateNode(7);
	TreeNode* node6 = CreateNode(6);
	TreeNode* node5 = CreateNode(5);
	TreeNode* node4 = CreateNode(4);
	TreeNode* node3 = CreateNode(3, node6, node7);
	TreeNode* node2 = CreateNode(2, node4, node5);
	TreeNode* node1 = CreateNode(1, node2, node3);

	cout << "전위 순회 : ";
	Preorder(node1);
	cout << "\n\n";
	cout << "중위 순회 : ";
	Inorder(node1);
	cout << "\n\n";
	cout << "후위 순회 : ";
	Postorder(node1);
	cout << "\n";

#pragma endregion

	return 0;
}
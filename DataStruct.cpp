#include "using_std.h"
#include "BinarySearchTree.h"

int main()
{
#pragma region 이진 탐색 트리(BST)

	BinarySearchTree<int> bst;

	bst.rootNode = bst.Insert(10, bst.GetRoot());

	bst.Insert(5, bst.GetRoot());
	bst.Insert(15, bst.GetRoot());
	bst.Insert(23, bst.GetRoot());
	bst.Insert(3, bst.GetRoot());
	bst.Insert(17, bst.GetRoot());
	bst.Insert(2, bst.GetRoot());

	bst.Inorder(bst.GetRoot());	

	cout << "\n\n";

	cout << "BST Data의 최소 값 : " << bst.MinValue(bst.GetRoot()) << endl;
	cout << "\nBST Data의 최대 값 : " << bst.MaxValue(bst.GetRoot()) << endl;

#pragma endregion

	return 0;
}
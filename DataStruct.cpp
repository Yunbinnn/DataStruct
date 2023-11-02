#include "using_std.h"
#include "BinarySearchTree.h"
#include "CompleteBinaryTree.h"

int main()
{
#pragma region 이진 탐색 트리(BST)

	/*BinarySearchTree<int> bst;

	bst.rootNode = bst.Insert(bst.GetRoot(), 10);

	bst.Insert(bst.GetRoot(), 5);
	bst.Insert(bst.GetRoot(), 15);
	bst.Insert(bst.GetRoot(), 23);
	bst.Insert(bst.GetRoot(), 3);
	bst.Insert(bst.GetRoot(), 17);
	bst.Insert(bst.GetRoot(), 2);

	bst.Inorder(bst.GetRoot());	

	cout << "\n\n";

	cout << "BST Data의 최소 값 : " << bst.MinValue(bst.GetRoot()) << endl;
	cout << "\nBST Data의 최대 값 : " << bst.MaxValue(bst.GetRoot()) << endl;*/

#pragma endregion

#pragma region 완전 이진 트리(CBT)

	CompleteBinaryTree<int> cbt;

	cbt.Insert(13);
	cbt.Insert(15);
	cbt.Insert(20);
	cbt.Insert(30);
	cbt.Insert(50);

	cout << "\nDelete 하기 전 : ";
	cbt.Display();

	cbt.Delete();
	cout << "\nDelete 후 : ";
	cbt.Display();

#pragma endregion

	return 0;
}
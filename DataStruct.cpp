#include "using_std.h"
#include "BinarySearchTree.h"
#include "MaxHeap.h"
#include "HashTable.h"

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

#pragma region 최대 힙(Max Heap)

	/*MaxHeap<int> mHeap;

	mHeap.Insert(30);
	mHeap.Insert(40);
	mHeap.Insert(15);
	mHeap.Insert(31);
	mHeap.Insert(55);

	cout << "\nDelete 전 : ";
	mHeap.Display();

	mHeap.Delete();
	cout << "\nDelete 후 : ";
	mHeap.Display();*/

#pragma endregion

#pragma region 해시 테이블

	HashTable<char, int>  hTable;

#pragma endregion

	return 0;
}
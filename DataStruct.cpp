#include "SingleLinkedList.h"

int main()
{
	SingleLinkedList<int> sList;

	sList.Push_Front(10);
	sList.Push_Front(20);
	sList.Push_Front(30);

	sList.Pop_Front();

	cout << "sList의 사이즈 : " << sList.Size() << endl;
	sList.Show();

	return 0;
}
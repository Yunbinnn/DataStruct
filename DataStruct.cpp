#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main()
{
#pragma region 단방향 연결 리스트

	/*SingleLinkedList<int> sList;

	sList.Push_Front(10);
	sList.Push_Front(20);
	sList.Push_Front(30);

	sList.Pop_Front();

	cout << "sList의 사이즈 : " << sList.Size() << endl;
	sList.Show();*/

#pragma endregion

#pragma region 양방향 연결 리스트

	DoubleLinkedList<int> dList;

	dList.Push_Back(19);
	
	dList.Show();

#pragma endregion

	return 0;
}
#pragma once
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "CircleLinkedList.h"

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

	/*DoubleLinkedList<int> dList;

	dList.Push_Back(19);

	dList.Show();*/

#pragma endregion

#pragma region 원형 연결 리스트

	CircleLinkedList<int> cList;

	cList.Push_Front(60);
	cList.Push_Front(50);
	cList.Push_Front(40);
	cList.Push_Front(30);
	cList.Push_Front(20);
	cList.Push_Front(10);

	cList.Pop_Back();
	cList.Pop_Front();

	cList.Print_List();


#pragma endregion

	return 0;
}
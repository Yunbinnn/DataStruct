#pragma once
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "CircleLinkedList.h"

int main()
{
#pragma region �ܹ��� ���� ����Ʈ

	/*SingleLinkedList<int> sList;

	sList.Push_Front(10);
	sList.Push_Front(20);
	sList.Push_Front(30);

	sList.Pop_Front();

	cout << "sList�� ������ : " << sList.Size() << endl;
	sList.Show();*/

#pragma endregion

#pragma region ����� ���� ����Ʈ

	/*DoubleLinkedList<int> dList;

	dList.Push_Back(19);

	dList.Show();*/

#pragma endregion

#pragma region ���� ���� ����Ʈ

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
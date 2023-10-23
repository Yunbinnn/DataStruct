#pragma once
#include <iostream>
using namespace std;

int main()
{
#pragma region ���� ����
	// ���ĵ��� ���� �����͵鿡 ���� ���� ���� �����͸�
	// ã�Ƽ� ���� �տ� �ִ� �����Ϳ� ��ȯ�ϴ� �˰����Դϴ�.

	// �ð� ���⵵ O(n^2)

	int selectBuffer[] = { 6,2,8,1,0 };

	int size = sizeof(selectBuffer) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		int min = selectBuffer[i]; // 6

		int select = i;

		for (int j = i + 1; j < size; j++)
		{
			if (min > selectBuffer[j])
			{
				min = selectBuffer[j];
				select = j;
			}
		}

		swap(selectBuffer[i], selectBuffer[select]);
	}

	for (const int& element : selectBuffer)
	{
		cout << element << " ";
	}

#pragma endregion

	return 0;
}
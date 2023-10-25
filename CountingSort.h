#pragma once
#include "using_std.h"

constexpr auto COUNT_SIZE = 5;
constexpr auto BUFFER_SIZE = 20;

#pragma region ��� ����

void Counting_Sort(int buffer[], int countBuffer[])
{
	for (int i = 0; i < BUFFER_SIZE; i++) countBuffer[buffer[i] - 1]++;

	for (int i = 0; i < COUNT_SIZE; i++)
		if (countBuffer[i] != 0)
			for (int j = 0; j < countBuffer[i]; j++) cout << i + 1 << " ";
}

#pragma endregion

int main()
{
#pragma region ��� ����
	// �������� ���� ���� ������ �ʰ�, �ܼ��ϰ� �� ���ڰ�
	// � �ִ��� ������ ���� ������ ���� �����ϴ� �˰����Դϴ�.

	// �ð� ���⵵ : O(n + k)

	int countBuffer[COUNT_SIZE] = { 0, };
	int buffer[BUFFER_SIZE] =
	{
	   1,2,4,4,2,
	   5,5,3,3,1,
	   2,3,1,5,4,
	   2,3,3,5,4
	};

	Counting_Sort(buffer, countBuffer);

#pragma endregion

	return 0;
}

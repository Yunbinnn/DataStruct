#pragma once
#include <iostream>
using namespace std;

int main()
{
#pragma region ���� ����
	// �� ��° �ڷ���� �����Ͽ� �� ��(������)
	// �ڷ��� ���Ͽ� ������ ��ġ�� ������ ��
	// �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ�
	// �����ϴ� �˰����Դϴ�.

	// �ð� ���⵵ : O(n^2)

	/*int insertBuffer[] = { 9,1,5,3,2 };

	int key = 0, j = 0;

	int size = sizeof(insertBuffer) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		key = insertBuffer[i];

		for (j = i - 1; j >= 0 && insertBuffer[j] > key; j--)
		{
			insertBuffer[j + 1] = insertBuffer[j];
		}

		insertBuffer[j + 1] = key;
	}

	for (const int& element : insertBuffer)
	{
		cout << element << " ";
	}*/

#pragma endregion

#pragma region ���� ó��

	/*int value = 0;

	int result = 0;

	try
	{
		cin >> value;

		result = 10 / value;

		throw result;
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}*/

#pragma endregion

#pragma region �ð� ���⵵
	// ��ǻ�� ���α׷��� �Է� ���� ���� ���� �ð���
	// ������踦 ��Ÿ���� ô���Դϴ�.

	// Big-O ǥ���
	// �Է°��� ��ȭ�� ���� ������ ������ ��,
	// ���� Ƚ���� ���� �ð��� �󸶸�ŭ �ɸ����� ��Ÿ���� ô���Դϴ�.

	// �־��� ��츦 ����ϹǷ�, ���α׷��� ����Ǵ�
	// �������� �ҿ�Ǵ� �־��� �ð����� ����� �� �ֱ� �����Դϴ�.

	/*
	O(1) ��� �ð� ���⵵
	�Է°��� �����ϴ��� �ð��� �þ�� �ʴ� �ð� ���⵵�Դϴ�.

	ex) �迭�� �ε��� ����
	int buffer[10]
	cout << buffer[5];
	*/

	/*
	O(n) ���� �ð� ���⵵
	�Է°��� �����Կ� ���� �ð� ���� ���� ������
	�����ϴ� �ð� ���⵵�Դϴ�.

	ex)	�Է� 1	     �Է� 100
		�ð� -> 1��   �ð� -> 100��

	ex) for(int i = 0; i < n; i++)
		{
		   content...
		}
	*/

	// O(log n) �α� �ð� ���⵵
	// �Է� �������� ũ�Ⱑ Ŀ������ ó�� �ð��� �α�(log)��ŭ
	// ª������ �ð� ���⵵�Դϴ�.



#pragma endregion

	return 0;
}
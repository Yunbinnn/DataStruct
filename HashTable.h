#pragma once
#include "using_std.h"

constexpr auto SIZE = 5;

#pragma region �ؽ� ���̺�
// (key, value)�� �����͸� �����ϴ� �ڷ� ���� �� �ϳ���
// ������ �����͸� �˻��� �� �ִ� �ڷ� �����Դϴ�.

// �ؽ� ���̺��� ��� �ð� ���⵵�� O(1)�Դϴ�.

// �ؽ� �浹�� �ذ��ϴ� ���

// <ü�̴� ���>
// �� �ؽ� ��Ŷ�� ���� ����Ʈ�� �����ϴ� ����Դϴ�.

// �ؽ� �浹 �߻� �� ������ �ؽ� ���� �ش��ϴ� �����͵���
// ���� ����Ʈ�� �����Ͽ� �����մϴ�.

// <���� �ּҹ�>
// �浹 �߻� �� �� ��Ŷ�� �����͸� �����ϴ� ����Դϴ�.

// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶����ϴ�.

// ���� Ž�� : �浹 �߻� �� �տ��� ���� ���ʴ�� �� ��Ŷ�� ã��
// ���� �����ϴ� ����Դϴ�.

// ���� Ž�� : �浹 �߻��� 2^, 2^3 ��ŭ ������ �� ��Ŷ�� ã��
// ���� �����ϴ� ����Դϴ�.

// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ��� �־� �ٸ� �Լ���
// �����ϴ� ����Դϴ�.

#pragma endregion

template<typename T, typename V>
class HashTable
{
private:
	struct Node
	{
		T key;
		V value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];

public:

	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	int HashFunc(T key)
	{
		int sumValue = 0;

		for (const char& element : key) sumValue += (int)element;

		int hashIndex = sumValue % SIZE;

		return hashIndex;
	}
	
	Node* CreateNode(T key, V value)
	{
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void Insert(T key, V value)
	{
		// �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunc(key);

		// ���ο� ��带 �����մϴ�.
		Node* newNode = CreateNode(key, value);

		// ��尡 1���� �������� �ʴ´ٸ�
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]�� head �����Ϳ� ���ο� ����� �ּҰ��� �����մϴ�.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]�� count ������ ���� ������ŵ�ϴ�.
			bucket[hashIndex].count++;
		}
		else // ��尡 1���� �����Ѵٸ�
		{
			// 1. NewNode�� next�� bucket[hashIndex]�� head�� ���� �־��ݴϴ�.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head�� ��� ���� ������ ����� �ּҸ� ����Ű�� �մϴ�.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex].count�� ���� ������ŵ�ϴ�.
			bucket[hashIndex].count++;
		}
	}
};
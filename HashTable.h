#pragma once
#include "using_std.h"
#include <string>

#define SIZE 5 

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

template<typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
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
	
	template<typename T>
	int HashFunc(T key)
	{
		int hashIndex = (int)key % SIZE;

		return hashIndex;
	}

	template<>
	int HashFunc(string key) 
	{ 
		int sumValue = 0;

		for (const char& element : key) sumValue += (int)element;

		int hashIndex = sumValue % SIZE;

		return hashIndex;
	}

	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode;
	}

	void Insert(KEY key, VALUE value)
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

	void Remove(KEY key)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunc(key);

		// 2. ��带 Ž���� �� �ִ� ��ȸ�� ������ ���� ����
		//    �� ��Ŷ�� head�� �����մϴ�.
		Node* currentNode = bucket[hashIndex];
																  
		// 3. ���� ��带 ������ �� �ִ� ������ ���� ����
		Node* traceNode = nullptr;

		// 4. currentNode�� nullptr�̶�� �ϸ� �Լ��� �����մϴ�.
		if (currentNode == nullptr)
		{
			cout << "�ؽ� ���̺��� ��� �ֽ��ϴ�." << endl;
			return;
		}

		// 5. currentNode�� �̿��ؼ� ���� ã���� �ϴ� key ���� ã���� �˴ϴ�.
		while (currentNode != nullptr)
		{
			// currentNode->key ���� ���� �����ϰ� ���� key���� ���ٸ�
			if (currentNode->key == key)
			{
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// �� ��Ŷ�� ī��Ʈ�� ���� ��ŵ�ϴ�.
				bucket[hashIndex].count--;

				// �ش� �޸𸮸� �����մϴ�
				delete currentNode;

				return;
			}			   

			traceNode = currentNode;
			currentNode = currentNode->next;
		}

		cout << "Ű�� ã�� �� �����ϴ�." << endl;
	}	

	void Display()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* currentNode = bucket[i].head;

			while (currentNode !=nullptr)
			{
				cout << "[" << i << "]" << "KEY : " << currentNode->key << endl;
				cout << "[" << i << "]" << "VALUE : " << currentNode->value << endl;
				currentNode = currentNode->next;
			}
			cout << endl;
		}
	}
};
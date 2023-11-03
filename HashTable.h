#pragma once
#include "using_std.h"
#include <string>

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
class Node
{
private:
	T key;
	V value;
	Node<T, V>* next;
	Node(T key, V value) : key(key), value(value) {}
};

template<typename T, typename V>
class HashTable
{
private:
	int size;
	Node<T, V>* head;

public:

	HashTable()
	{
		size = 0;
		head = nullptr;
	}

	bool IsEmpty() const { return size <= 0 ? true : false; }
};
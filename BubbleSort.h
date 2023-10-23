#pragma once
#include <iostream>
using namespace std;

constexpr auto SIZE = 5;

void BubbleSort(int arr[])
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < (SIZE - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

#pragma region ������ �����ε�

class Vector2
{
private:
	int x;
	int y;

public:
	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator+(const Vector2& vector2)
	{
		Vector2 sum(this->x + vector2.x, this->y + vector2.y);

		return sum;
	}

	Vector2 operator-(const Vector2& vector2)
	{
		Vector2 sum(this->x - vector2.x, this->y - vector2.y);

		return sum;
	}

	Vector2 operator*(const Vector2& vector2)
	{
		Vector2 sum(this->x * vector2.x, this->y * vector2.y);

		return sum;
	}

	Vector2 operator/(const Vector2& vector2)
	{
		Vector2 sum(this->x / vector2.x, this->y / vector2.y);

		return sum;
	}

	Vector2 operator++()
	{
		this->x++;
		this->y++;

		return *this;
	}

	Vector2 operator++(int)
	{
		Vector2 clone = *this;

		this->x++;
		this->y++;

		return clone;
	}

	int GetX() const
	{
		return x;
	}

	int GetY() const
	{
		return y;
	}
};

#pragma endregion

int main()
{
#pragma region ��ǰ ����(Bubble Sort)
	// ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰��� �Դϴ�.

	// �ð� ���⵵ O(n^2)

	/*int arr[SIZE] = { 8,4,9,3,1 };

	cout << "���� �� : ";

	for (const int& element : arr)
	{
		cout << element << " ";
	}

	BubbleSort(arr);

	cout << "\n\n���� �� : ";

	for (const int& element : arr)
	{
		cout << element << " ";
	}*/

#pragma endregion

#pragma region ������ �����ε�

	Vector2 Up(0, 1);
	Vector2 Right(1, 0);

	Vector2 Sum = Up + Right;

	cout << Sum.GetX() << endl;
	cout << Sum.GetY() << endl;

#pragma endregion

	return 0;
}
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

#pragma region 연산자 오버로딩

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
#pragma region 거품 정렬(Bubble Sort)
	// 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘 입니다.

	// 시간 복잡도 O(n^2)

	/*int arr[SIZE] = { 8,4,9,3,1 };

	cout << "정렬 전 : ";

	for (const int& element : arr)
	{
		cout << element << " ";
	}

	BubbleSort(arr);

	cout << "\n\n정렬 후 : ";

	for (const int& element : arr)
	{
		cout << element << " ";
	}*/

#pragma endregion
	
#pragma region 연산자 오버로딩

	Vector2 Up(0, 1);
	Vector2 Right(1, 0);

	Vector2 Sum = Up + Right;

	cout << Sum.GetX() << endl;
	cout << Sum.GetY() << endl;

#pragma endregion

	return 0;
}
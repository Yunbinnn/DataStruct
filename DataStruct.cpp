#include "using_std.h"

int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 직접 비교하지 않고, 단순하게 각 숫자가
	// 몇개 있는지 갯수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	// 시간 복잡도 : O(n + k)

	int count[5] = { 0, };
	int data[20] =
	{
	   1,2,4,4,2,
	   5,5,3,3,1,
	   2,3,1,5,4,
	   2,3,3,5,4
	};

	for (int i = 0; i < 20; i++)
	{
		count[data[i] - 1]++;
	}

	for(int i=0;i<5;i++)
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
				cout << i + 1 << " ";
		}

#pragma endregion


	return 0;
}

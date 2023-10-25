#include "using_std.h"
#include "CircleQueue.h"

int main()
{
#pragma region 원형 큐
	// 물리적으로는 선형 구조를 가지고 있으며,
	// 큐의 시작점과 끝점을 연결한 큐입니다.

	CircleQueue<int> cQueue;

	cQueue.Enqueue(10);
	cQueue.Enqueue(20);
	cQueue.Enqueue(30);
	
	cQueue.Display();

	cout << "\nCircle Queue의 Front : " << cQueue.Front() << endl;
	cout << "Circle Queue의 Back : " << cQueue.Back() << endl;

#pragma endregion

	return 0;
}
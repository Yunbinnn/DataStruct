#include "using_std.h"
#include "STL_Vector.h"

int main()
{
	STL_VECTOR<int> sVector;

	for (int i = 0; i < 11; i++)
		sVector.Push_Back(i + 1);

	cout << "Vector의 Size : " << sVector.Size() << endl;

	cout << "Vector의 Capacity : " << sVector.Capacity() << endl;

	for (int i = 0; i < 5; i++)
		sVector.Pop_Back();

	cout << "Vector의 Size : " << sVector.Size() << endl;

	cout << "Vector의 Front : " << sVector.Front() << endl;
	cout << "Vector의 Back : " << sVector.Back() << endl;
	cout << "Vector의 Begin : " << sVector.Begin() << endl;
	cout << "Vector의 End : " << sVector.End() << endl;

	return 0;
}
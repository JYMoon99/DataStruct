#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// 거품 정렬
	// 서로 인접한 두 원소의 대소를 비교하여, 조건에 맞지 않다면
	// 자리를 교환하여 정렬하는 알고리즘
	int array[5] = { 7, 52, 1, 11, 3 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}

	for (int& element : array)
	{
		cout << element << endl;
	}

	return 0;
}

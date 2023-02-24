#define SIZE 5
#include <iostream>

using namespace std;

int main()
{
	// 삽입 정렬
	// 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된
	// 배열과 비교하여, 자신의 위치를 찾아 삽입하는 정렬

	int array[SIZE] = { 1, 10, 7, 2, 17 };
	int key = 0;
	int j = 0;
	int i = 0;

	for (i = 1; i < SIZE; i++)
	{
		key = array[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (key < array[j])
			{
				array[j + 1] = array[j];
				array[j] = key;
			}
			else
				break;

		}
		array[j + 1] = key;


	}

	for (const int& element : array)
	{
		cout << element << endl;
	}

}
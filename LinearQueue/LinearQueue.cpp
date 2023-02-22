﻿#include <iostream>

using namespace std;

#define SIZE 5

class Queue
{

private:
	int front = -1;
	int rear = -1;


public:
	int buffer[SIZE] = { 0, };

	bool Empty() // 내용물이 비어있는가?
	{
		if (rear == front)
		{
			return true;
		}
		else
			return false;
	}

	bool IsFull() // 내용물이 가득차있는가?
	{
		if (rear == SIZE - 1)
		{
			return true;
		}
		else
			return false;
	}

	void Enqueue(int data) // 큐에 요소를 추가한다 (큐가 다 차있으면 데이터를 넣을 수 없도록 처리)
	{

		if (IsFull() == true)
		{
			cout << "Queue Is Full" << endl;
		}
		else
		{
			buffer[++rear] = data;
		}
	}

	int Dequeue() // 큐에서 맨 앞의 요소를 빼낸다 (큐가 비어있으면 데이터를 뺄 수 없도록 처리)
	{
		if (Empty() == true)
		{
			cout << "Queue Is Empty" << endl;
		}
		else
		{
			int temp = buffer[++front];
			buffer[front] = NULL;
			return temp;
		}

	}
};

int main()
{
	Queue queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);

	while (!queue.Empty())
	{
		cout << queue.Dequeue() << endl;
	}

	queue.Dequeue();

	return 0;
}
#define SIZE 4
#include <iostream>

using namespace std;

class CircleQueue
{
public:
	bool Empty() // 비어있는가?
	{
		if (rear == front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull() // 가득 차 있는가?
	{
		if ((rear + 1) % SIZE == front)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void Enqueue(int data)
	{
		if (IsFull() == true)
		{
			cout << "Queue Is Full" << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;
			buffer[rear] = data;
		}

	}

	int Dequeue()
	{
		if (Empty() == true)
		{
			cout << "Queue Is Empty" << endl;

		}
		else
		{
			front = (front + 1) % SIZE;
			int temp = buffer[front];
			buffer[front] = NULL;
			return temp;
		}

	}



private:
	int rear = SIZE - 1;
	int front = SIZE - 1;
	int buffer[SIZE] = { 0, };
};


int main()
{
	CircleQueue queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);


	while (!queue.Empty())
	{
		cout << queue.Dequeue() << endl;
	}
	queue.Dequeue();
	return 0;

} 
#include <iostream>


using namespace std;

struct Node
{
	int data;
	Node* next;
};

void Insert(Node* target, int data)
{
	Node* newNode = new Node;

	newNode->data = data;

	newNode->next = target->next;

	target->next = newNode;
}

void Delete(Node* target)
{
	Node* removePtr = target->next;
	target->next = removePtr->next;

	delete removePtr;
}

int Size(Node* target)
{
	int count = 0;

	Node* currPtr = target->next;


	while (currPtr != NULL)
	{
		count++;
		currPtr = currPtr->next;

	}

	return count;
}


int main()
{
	Node* head = new Node;

	head->next = NULL;

	Insert(head, 10);
	Insert(head, 20);
	Insert(head, 30);
	Insert(head, 40);
	Insert(head, 50);
	Insert(head, 60);

	Delete(head);



	Node* curPtr = head->next;

	while (curPtr != NULL)
	{
		cout << curPtr->data << endl;
		curPtr = curPtr->next;
	}

	cout << Size(head);






	return 0;
}
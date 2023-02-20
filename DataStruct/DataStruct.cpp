#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;
Node* tail;

void Insert(Node* target, int data)
{
	Node* newnode = new Node;
	newnode->data = data;

	newnode->prev = target;
	newnode->next = target->next;

	target->next->prev = newnode;
	target->next = newnode;
	
}


// 삭제 함수
void Remove(Node* target)
{
	Node* removePtr = target->next;
	removePtr->next->prev = target;
	target->next = removePtr->next;
	delete removePtr;

}

// 앞에서 출력하는 함수
void FrontCircuit(Node* target)
{
	Node* curPtr = target->next;

	while (curPtr != tail)
	{
		cout << curPtr->data << endl;
		curPtr = curPtr->next;
	}
}

void BackCircuit(Node* target)
{
	Node* curPtr = target->prev;

	while (curPtr != head)
	{
		cout << curPtr->data << endl;
		curPtr = curPtr->prev;
	}
}



int main()
{
	head = new Node;
	tail = new Node;

	head->prev = NULL;
	tail->next = NULL;

	head->next = tail;
	tail->prev = head;
	//Node* node1 = new Node;
	//node1->data = 1000;
	//
	//Node* node2 = new Node;
	//node2->data = 2000;
	//
	//head->next = node1;
	//
	//node1->prev = head;
	//node1->next = node2;
	//
	//node2->prev = node1;
	//node2->next = tail;
	//
	//tail->prev = node2;
	//
	//Node* frontPtr = head->next;
	//
	//while (frontPtr != tail)
	//{
	//	cout << frontPtr->data << endl;
	//	frontPtr = frontPtr->next;
	//}
	//
	//Node* backPtr = tail->prev;
	//
	//while (backPtr != head)
	//{
	//	cout << backPtr->data << endl;
	//	backPtr = backPtr->prev;
	//}

	FrontCircuit(head);
	BackCircuit(tail);

	return 0;
}
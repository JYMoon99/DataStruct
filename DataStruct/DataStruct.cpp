#include <iostream>
#define SIZE 5

using namespace std;

struct Node
{
	int key;
	int value;

	Node* next;
};

struct Bucket
{
	int size;
	Node* head;
};

struct Bucket* bucket = new Bucket[5];

int HashFunction(int key)
{
	return key % SIZE;
}


void Insert(int key, int value)
{
	// 1. 노드 추가
	Node* newNode = new Node;

	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	// 2. 해시 인덱스 구하기
	int hashIndex = HashFunction(key);

	// 3. 노드를 해당 Bucket의 인덱스에 연결
	if (bucket[hashIndex].size == 0)
	{
		bucket[hashIndex].size++;
		bucket[hashIndex].head = newNode;
	}

	else if (bucket[hashIndex].size > 0)
	{
		newNode->next = bucket[hashIndex].head;
		bucket[hashIndex].head = newNode;
		bucket[hashIndex].size++;
	}

}

int main()
{
	// 해시 테이블
	// 해시함수를 통해서 변환된 값을 index로 삼아서
	// key와 value 형태로 저장하는 자료구조입니다.
	for (int i = 0; i < SIZE; i++)
	{
		bucket[i].head = NULL;
		bucket[i].size = 0;
	}
	
	Insert(10, 5);
	Insert(11, 77);

	

	return 0;
}
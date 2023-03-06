#include <iostream>

using namespace std;

// 완전 이진트리는 왼쪽부터 채워가야한다.

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* leftChild, Node* rightChild)
{
	Node* newNode = new Node;

	newNode->data = data;
	newNode->left = leftChild;
	newNode->right = rightChild;

	return newNode;

}

void Preorder(Node* root)
{
	// 전위 순회

	if (root != NULL)
	{
		// 1. 자기자신을 출력
		cout << root->data << endl;

		// 재귀함수 이용
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Inorder(Node* root)
{
	// 중위 순회
	if (root != NULL)
	{
		Inorder(root->left);
		cout << root->data << endl;
		Inorder(root->right);
	}
}

void Postorder(Node* root)
{
	// 후위 순회	
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << endl;
	}
}


int main()
{
	// 트리 구조란?
	// 한 노드에서 시작해서 다른 정점들을 순회하여
	// 자기 자신에게 돌아오는 순환이 없는 연결 그래프

	// 이진 트리란?
	// 최대 2개의 자식 노드를 가지는 트리

	Node* node7 = CreateNode(70, NULL, NULL);
	Node* node6 = CreateNode(60, NULL, NULL);
	Node* node5 = CreateNode(50, NULL, NULL);
	Node* node4 = CreateNode(40, NULL, NULL);

	Node* node3 = CreateNode(30, node6, node7);
	Node* node2 = CreateNode(20, node4, node5);
	Node* node1 = CreateNode(10, node2, node3);

	/* 트리의 순회
	전위 순회 -> 자기 자신을 출력 -> 왼쪽 노드 방문 -> 오른쪽 노드 방문
	중위 순회 -> 왼쪽 노드 방문 -> 자기 자신을 출력 -> 오른쪽 노드 방문
	후위 순회 -> 왼쪽 노드 방문 -> 오른쪽 노드 방문 -> 자기 자신을 출력
	*/

	//Preorder(node1);
	Inorder(node1);
	//Postorder(node1);

	return 0;
}
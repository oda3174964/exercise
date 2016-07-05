//In-place Convert BST into a Min-Heap
//Given a Binary Search Tree, convert it into a Min - Heap containing the same elements in O(n) time.
//Do this in - place.

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

struct Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void printLevelOrder(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		int nodeCount = q.size();
		while (nodeCount > 0)
		{
			Node* node = q.front();
			q.pop();
			cout << node->data << " ";
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			nodeCount--;
		}
		cout << endl;
	}
}

void BSTToSortedLL(Node* root, Node** head_ref)
{
	if (root == NULL)
	{
		return;
	}

	BSTToSortedLL(root->right, head_ref);

	root->right = *head_ref;

	if (*head_ref != NULL)
		(*head_ref)->left = NULL;

	*head_ref = root;

	BSTToSortedLL(root->left, head_ref);
}

void SortedLLToMinHeap(Node*& root, Node* head)
{
	if (head == NULL)
		return;

	queue<Node*> q;

	root = head;

	head = head->right;

	root->right = NULL;

	q.push(root);

	while (head)
	{
		Node* parent = q.front();
		q.pop();

		Node* leftChild = head;
		head = head->right;
		leftChild->right = NULL;
		q.push(leftChild);

		parent->left = leftChild;

		if (head)
		{
			Node* rightChild = head;
			head = head->right;
			rightChild->right = NULL;
			q.push(rightChild);
			parent->right = rightChild;
		}
	}
}

void BSTToMinHeap(Node*& root)
{
	Node* head = NULL;

	BSTToSortedLL(root, &head);

	root = NULL;

	SortedLLToMinHeap(root, head);
}

int main()
{
	Node* root = newNode(8);
	root->left = newNode(4);
	root->right = newNode(12);
	root->right->left = newNode(10);
	root->right->right = newNode(14);
	root->left->left = newNode(2);
	root->left->right = newNode(6);

	BSTToMinHeap(root);

	printLevelOrder(root);
	system("pause");
	return 0;
}
/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted.
If array is already sorted then inversion count is 0. 
If array is sorted in reverse order that inversion count is the maximum.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node
{
	int key, height;
	struct Node* left, *right;
	int size;
};

int height(struct Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int size(struct Node* N)
{
	if (N == NULL)
		return 0;
	return N->size;
}

struct Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	node->height = 1;
	return node;
}

//LL型
Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	y->size = size(y->left) + size(y->right) + 1;
	x->size = size(x->left) + size(x->right) + 1;

	return x;
}

//RR型
Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = x->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	x->size = size(x->left) + size(x->right) + 1;
	y->size = size(y->left) + size(y->right) + 1;

	return y;
}

int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key, int* result)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
	{
		node->left = insert(node->left, key, result);

		*result = *result + size(node->right) + 1;
	}
	else
	{
		node->right = insert(node->right, key, result);
	}

	node->height = max(height(node->left), height(node->right)) + 1;

	node->size = size(node->left) + size(node->right) + 1;

	int balance = getBalance(node);

	//LL
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	//RR
	if (balance < -1 && key > node->right->key)
		return rightRotate(node);

	//LR
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	//RL
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

int getTnvCount(int arr[], int n)
{
	struct Node* root = NULL;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		root = insert(root, arr[i], &result);
	}

	return result;
}

int main()
{
	int arr[] = { 8, 4, 2, 1 };
	int n = sizeof(arr) / sizeof(int);
	cout << "Number of inversions count are : "
	<< getTnvCount(arr, n) << endl;
	system("pause");
	return 0;
}
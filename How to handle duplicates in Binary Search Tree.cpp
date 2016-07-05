/*
In a Binary Search Tree (BST), all keys in left subtree of a key must be smaller 
and all keys in right subtree must be greater. 
So a Binary Search Tree by definition has distinct keys.

How to allow duplicates where every insertion inserts one more key 
with a value and every deletion deletes one occurrence?
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node
{
	int key;
	int count;
	node* left, *right;
};

node* newNode(int item)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->count = 1;
	return temp;
}

void inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d(%d) ", root->key, root->count);
		inorder(root->right);
	}
}

node* insert(node* n, int key)
{
	if (n == NULL)
		return newNode(key);

	if (key == n->key)
	{
		(n->count)++;
		return n;
	}

	if (key < n->key)
		n->left = insert(n->left, key);
	else
		n->right = insert(n->right, key);

	return n;
}

node* minValueNode(node* n)
{
	node* current = n;

	while (n->left != NULL)
	{
		current = current->left;
	}

	return current;
}

node* deleteNode(node* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->count > 1)
		{
			(root->count)--;
			return root;
		}

		if (root->left == NULL)
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}

		node* temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
	node* root = NULL;
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 9);
	root = insert(root, 11);
	root = insert(root, 10);
	root = insert(root, 12);
	root = insert(root, 12);

	printf("Inorder traversal of the given tree \n");
	inorder(root);

	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 12\n");
	root = deleteNode(root, 12);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 9\n");
	root = deleteNode(root, 9);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);
	
	system("pause");
	return 0;
}
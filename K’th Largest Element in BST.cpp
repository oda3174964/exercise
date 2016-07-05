/*
Given a Binary Search Tree (BST) and a positive integer k, find the k’th largest element in the Binary Search Tree.

For example, in the following BST, if k = 3, then output should be 14, and if k = 5, then output should be 10.
*/

#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node* left, *right;
};

Node* newNode(int item)
{
	Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void kthLargestUtil(Node* root, int k, int& c)
{
	if (root == NULL || c >= k)
		return;

	kthLargestUtil(root->right, k, c);

	c++;

	if (c == k)
	{
		cout << "K'th largest element is "
			<< root->key << endl;
		return;
	}

	kthLargestUtil(root->left, k, c);
}

void kthLargest(Node *root, int k)
{
	// Initialize count of nodes visited as 0
	int c = 0;

	// Note that c is passed by reference
	kthLargestUtil(root, k, c);
}

Node* insert(Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

// Driver Program to test above functions
int main()
{
	/* Let us create following BST
	50
	/     \
	30      70
	/  \    /  \
	20   40  60   80 */
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	int c = 0;
	for (int k = 1; k <= 7; k++)
		kthLargest(root, k);

	system("pause");
	return 0;
}
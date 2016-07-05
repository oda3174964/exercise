#include <iostream>
#include <climits>
using namespace std;

struct Node
{
	int key;
	Node* right, *left;
};

int KSmallestUsingMorris(Node* root, int k)
{
	int count = 0;

	int ksmall = INT_MIN;
	Node* curr = root;

	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			count++;
			if (count == k)
			{
				ksmall = curr->key;
			}
			curr = curr->right;
		}
		else
		{
			Node* pre = curr->left;
			while (pre->right != NULL && pre->right != curr)
			{
				pre = pre->right;
			}

			if (pre->right == NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}
			else
			{
				pre->right = NULL;
				count++;

				if (count == k)
					ksmall = curr->key;

				curr = curr->right;
			}
		}
	}
	return ksmall;
}

Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	for (int k = 1; k <= 7; k++)
		cout << KSmallestUsingMorris(root, k) << " ";
	cout << endl;

	system("pause");
	return 0;
}
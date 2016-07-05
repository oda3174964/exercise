//Given two Binary Search Trees, find common nodes in them. In other words, find intersection of two BSTs.
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int key;
	Node* left, *right;
};

Node* newNode(int ele)
{
	Node* temp = new Node;
	temp->key = ele;
	temp->left = temp->right = NULL;
	return temp;
}

void printCommon(Node* root1, Node* root2)
{
	stack<Node*> stack1, s1, s2;

	while (1)
	{
		if (root1)
		{
			s1.push(root1);
			root1 = root1->left;
		}
		else if (root2)
		{
			s2.push(root2);
			root2 = root2->left;
		}
		else if (!s1.empty() && !s2.empty())
		{
			root1 = s1.top();
			root2 = s2.top();

			if (root1->key == root2->key)
			{
				cout << root1->key << " ";
				s1.pop();
				s2.pop();

				root1 = root1->right;
				root2 = root2->right;
			}
			else if (root1->key < root2->key)
			{
				s1.pop();
				root1 = root1->right;

				root2 = NULL;
			}
			else if (root1->key > root2->key)
			{
				s2.pop();
				root2 = root2->right;

				root1 = NULL;
			}
		}
		else
			break;
	}
}

void inorder(Node* root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

Node* insert(Node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
	Node *root1 = NULL;
	root1 = insert(root1, 5);
	root1 = insert(root1, 1);
	root1 = insert(root1, 10);
	root1 = insert(root1, 0);
	root1 = insert(root1, 4);
	root1 = insert(root1, 7);
	root1 = insert(root1, 9);

	Node *root2 = NULL;
	root2 = insert(root2, 10);
	root2 = insert(root2, 7);
	root2 = insert(root2, 20);
	root2 = insert(root2, 4);
	root2 = insert(root2, 9);

	cout << "Tree 1 : ";
	inorder(root1);
	cout << endl;

	cout << "Tree 2 : ";
	inorder(root2);

	cout << "\nCommon Nodes: ";
	printCommon(root1, root2);
	system("pause");
	return 0;
}
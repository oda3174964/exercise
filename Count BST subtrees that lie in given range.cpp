//返回子树在指定范围内的个数
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left, *right;
};

bool inRange(node* root, int low, int hight)
{
	return root->data >= low && root->data <= hight;
}

bool getCountUtil(node* root, int low, int high, int* count)
{
	if (root == NULL)
		return true;
	bool l = (root->left) ? getCountUtil(root->left, low, high, count) : true;
	bool r = (root->right) ? getCountUtil(root->right, low, high, count) : true;

	if (l && r && inRange(root, low, high))
	{
		++*count;
		return true;
	}

	return false;
}

int getCount(node* root, int low, int high)
{
	int count = 0;
	getCountUtil(root, low, high, &count);
	return count;
}

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


int main()
{
	node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(50);
	root->left->left = newNode(1);
	root->right->left = newNode(40);
	root->right->right = newNode(100);

	int l = 5;
	int h = 45;
	cout << "Count of subtrees in [" << l << ", "
		<< h << "] is " << getCount(root, l, h) << endl;
	system("pause");
	return 0;
}
/*
In this article, first count of possible BST (Binary Search Trees)s is discussed, 
then construction of all possible BSTs.
*/
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

vector<struct node *> constructTrees(int start, int end)
{
    vector<struct node *> list;

    if (start > end)
    {
        list.push_back(NULL);
        return list;
    }

    for (int i = start; i <= end; i++)
    {
        vector<struct node *> leftSubtree  = constructTrees(start, i - 1);
 
        vector<struct node *> rightSubtree = constructTrees(i + 1, end);

        for (int j = 0; j < leftSubtree.size(); j++)
        {
            struct node* left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                struct node * right = rightSubtree[k];
                struct node * node = newNode(i);
                node->left = left;         
                node->right = right;        
                list.push_back(node);        
            }
        }
    }
    return list;
}

int main()
{
    vector<struct node *> totalTreesFrom1toN = constructTrees(1, 3);

    cout << "Preorder traversals of all constructed BSTs are \n";
    for (int i = 0; i < totalTreesFrom1toN.size(); i++)
    {
        preorder(totalTreesFrom1toN[i]);
        cout << endl;
    }
    return 0;
}
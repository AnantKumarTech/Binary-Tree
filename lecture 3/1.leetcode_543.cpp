#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

// Calculate height of tree
int level(TreeNode *head)
{
    if (head == NULL)
        return 0;

    return 1 + max(level(head->left), level(head->right));
}

// Calculate diameter
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return level(root->left) + level(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter: " << diameterOfBinaryTree(root);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
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

int length=0;
// Calculate height of tree
int level(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(level(root->left), level(root->right));
}
void preorder(TreeNode *root, vector<int> &v, int length)
{
    if (root == NULL)
    {
        return;
    }
    v[length]=root->val;
    preorder(root->left,v,length+1);
    preorder(root->right,v,length+1);
}

// Right Side View
vector<int> rightSideView(TreeNode *root)
{
    int levels = level(root);
    vector<int>v(levels,0);
    preorder(root,v,length);
    return v;
}

int main()
{
    /*
             1
           /   \
          2     3
           \     \
            5     4
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = rightSideView(root);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
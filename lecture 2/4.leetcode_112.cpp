
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool has(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }

        // Check leaf node
        if (root->left == NULL && root->right == NULL)
        {
            return targetSum == root->val;
        }

        int sum = root->val;

        return has(root->left, targetSum - sum) ||
               has(root->right, targetSum - sum);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }

        return has(root, targetSum);
    }
};

int main()
{
    /*
             5
            / \
           4   8
          /   / \
         11  13  4
        /  \       \
       7    2       1
    */

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution obj;

    if (obj.hasPathSum(root, targetSum))
    {
        cout << "Path with target sum exists";
    }
    else
    {
        cout << "Path with target sum does not exist";
    }

    return 0;
}

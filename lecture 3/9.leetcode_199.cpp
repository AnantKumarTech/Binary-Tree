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

class Pair
{
public:
    TreeNode *node;
    int level;

    Pair(TreeNode *node, int level)
    {
        this->node = node;
        this->level = level;
    }
};

// Calculate height of tree
int level(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(level(root->left), level(root->right));
}

// Level Order Traversal
vector<int> levelOrder(TreeNode *root)
{
    vector<int> ans;

    int n = level(root);

    vector<vector<int>> v(n, vector<int>(0));

    queue<Pair> q;

    if (root != NULL)
        q.push({root, 0});

    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();

        TreeNode *node = front.node;
        int lvl = front.level;

        v[lvl].push_back(node->val);

        if (node->left != NULL)
            q.push({node->left, lvl + 1});

        if (node->right != NULL)
            q.push({node->right, lvl + 1});
    }

    // Store last element of every level
    for (int i = 0; i < v.size(); i++)
    {
        ans.push_back(v[i].back());
    }

    return ans;
}

// Right Side View
vector<int> rightSideView(TreeNode *root)
{
    return levelOrder(root);
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
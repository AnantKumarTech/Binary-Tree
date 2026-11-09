//     /*
//              1
//             / \
//            2   3
//           / \
//          4   5
//     */
// ans ={1,2,3,4,5}

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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
int level(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(level(root->left), level(root->right));
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    int n = level(root);
    vector<vector<int>> v(n, vector<int>(0));
    queue < pair<TreeNode*,int>> q;
    if (root != NULL)
        q.push({root, 0});
    while (q.size() != 0)
    {
        pair < TreeNode *, int > h= q.front();
        q.pop();
        TreeNode *node = h.first;
        int level = h.second;
        v[level].push_back(node->val);
        if (node->left != NULL)
            q.push({node->left, level + 1});
        if (node->right != NULL)
            q.push({node->right, level + 1});
    }
    return v;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> Arr = levelOrder(root);

    for (vector<int> row : Arr)
    {
        for (int x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

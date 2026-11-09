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
int level(TreeNode *head)
{
    if (head == NULL)
        return 0;

    return 1 + max(level(head->left), level(head->right));
}

void preorder(TreeNode *root, vector<int> &v, int length, int k)
{

    if (root == NULL)
    {
        return;
    }
    if (length == k)
    {
        v.push_back(root->val);
    }
    length++;
    preorder(root->left, v, length, k);
    preorder(root->right, v, length, k);
}
void kdistance(TreeNode *root, int k, vector<int> &v)
{
    int length = 0;

    preorder(root, v, length, k);
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> v;
    int le = level(root);
    for (int i = 0; i < le; i++)
    {
        vector<int> vt;
        kdistance(root, i, vt);
        v.push_back(vt);
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

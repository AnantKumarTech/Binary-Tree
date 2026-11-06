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
#include <queue>
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




vector<int> levelOrder(TreeNode *root)
{
    vector<int> v;
    queue < TreeNode*>q;
    if(root!=NULL) q.push(root);
    while(q.size()!=0){
        TreeNode *front = q.front();
        q.pop();
        v.push_back(front->val);
        if(front->left!=NULL) q.push(front->left);
        if(front->right!=NULL) q.push(front->right);
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

    vector<int> Arr = levelOrder(root);
    for (int x : Arr)
    {
        cout << x << " ";
    }

    return 0;
}

#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
void preorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
   
    preorder(root->left, v);
    preorder(root->right, v);
    v.push_back(root->val);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    preorder(root, v);
    return v;
}

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    a->left = b;
    a->right = d;
    b->left = c;
    b->right = e;
    d->left = f;
    //   cout<<a->val<<endl;
    //   cout<<a->left->val<<endl;
    //   cout<<a->left->left->val<<endl;
    //   cout<<a->right->val<<endl;
    //   cout<<a->left->right->val<<endl;
    //   cout<<a->right->left->val<<endl;
    vector<int> Arr = preorderTraversal(a);
    for (int x : Arr)
    {
        cout << x << " ";
    }
}
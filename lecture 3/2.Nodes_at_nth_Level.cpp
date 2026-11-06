#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void preorder(TreeNode *root, vector<int> &v, int length, int k)
{

    if (root == NULL)
    {
        return;
    }
    if (length == k)
    {
        v.push_back(root->data);
    }
    length++;
    preorder(root->left, v, length, k);
    preorder(root->right, v, length, k);
}
vector<int> kdistance(TreeNode *root, int k)
{
    int length = 0;
    // code here
    vector<int> v;
    preorder(root, v, length, k);
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
    vector<int> Arr = kdistance(a,2);
    for (int x : Arr)
    {
        cout << x << " ";
    }
}
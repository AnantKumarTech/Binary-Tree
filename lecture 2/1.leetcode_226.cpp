// #include <iostream>
// #include <climits>
// #include <vector>
// using namespace std;
// class TreeNode
// {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int val)
//     {
//         this->val = val;
//         left = right = NULL;
//     }
// };
// void invert(TreeNode *root){
//     if (root == NULL)
//         return;
//     TreeNode * temp=root->left;
//     root->left=root->right;
//     root->right=temp;
//     invert(root->left);
//     invert(root->right);
// }

// TreeNode *invertTree(TreeNode *root)
// {
//     invert(root);
//    return root;
// }

// int main()
// {
//     TreeNode *a = new TreeNode(1);
//     TreeNode *b = new TreeNode(2);
//     TreeNode *c = new TreeNode(3);
//     TreeNode *d = new TreeNode(4);
//     TreeNode *e = new TreeNode(5);
//     TreeNode *f = new TreeNode(6);
//     a->left = b;
//     a->right = d;
//     b->left = c;
//     b->right = e;
//     d->left = f;
//     //   cout<<a->val<<endl;
//     //   cout<<a->left->val<<endl;
//     //   cout<<a->left->left->val<<endl;
//     //   cout<<a->right->val<<endl;
//     //   cout<<a->left->right->val<<endl;
//     //   cout<<a->right->left->val<<endl;
   
// }



// another solution
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

TreeNode *invertTree(TreeNode *root)
{
    if(root==NULL) return root;
    TreeNode *temp=root->left;
    root->left=invertTree(root->right);
    root->right = invertTree(temp);
    return root;
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
}

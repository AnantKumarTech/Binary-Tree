
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

// class Solution
// {
// public:
//     int level(TreeNode *head)
//     {
//         if (head == NULL)
//             return 0;

//         return 1 + max(level(head->left), level(head->right));
//     }

//     bool isBalanced(TreeNode *root)
//     {
//         if (root == NULL)
//             return true;

//         if (abs(level(root->left) - level(root->right)) >= 2)
//         {
//             return false;
//         }

//         return isBalanced(root->left) && isBalanced(root->right);
//     }
// };

// int main()
// {

//     /*
//              1
//             / \
//            2   3
//           / \
//          4   5
//     */

//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     Solution obj;

//     if (obj.isBalanced(root))
//     {
//         cout << "Tree is Balanced";
//     }
//     else
//     {
//         cout << "Tree is Not Balanced";
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cmath>
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
    bool ans;
    int level(TreeNode *head)
    {
        if (head == NULL){
            return 0;
        }
        int r=level(head->right);
        int l=level(head->left);
        if(abs(l-r)>1){
            ans=false;
        }


        return 1 + max(r,l);
    }

    bool isBalanced(TreeNode *root)
    {
        ans=true;
        level(root);
        return ans;
       
    }
};

int main()
{

    /*
             1
            / \
           2   3
          / \
         4   5
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if (obj.isBalanced(root))
    {
        cout << "Tree is Balanced";
    }
    else
    {
        cout << "Tree is Not Balanced";
    }

    return 0;
}

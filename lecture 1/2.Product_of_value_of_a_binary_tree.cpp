#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
int product(Node *head)
{
    if (head == NULL)
        return 1;
    return head->val * product(head->right) * product(head->left);
}
int MaxInTree(Node *head)
{
    if (head == NULL)
        return INT_MIN;

    return max(head->val,max(MaxInTree(head->left),MaxInTree(head->right)));
}
int level(Node *head)
{
    if (head == NULL)
        return 0;

    return 1 + max(level(head->left), level(head->right));
}

int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
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
    cout << product(a);
    cout << MaxInTree(a);

}
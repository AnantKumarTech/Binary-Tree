#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }


};
void display(Node* head){
    if(head==NULL){
        return;
    }
    cout<<head->val<<" ";
    display(head->left);
    display(head->right);

}

int main()
{
    Node*a=new Node(1);
    Node*b=new Node(2);
    Node*c=new Node(3);
    Node*d=new Node(4);
    Node*e=new Node(5);
    Node*f=new Node(6);
    a->left=b;
    a->right=d;
    b->left=c;
    b->right=e;
    d->left=f;
//   cout<<a->val<<endl;
//   cout<<a->left->val<<endl;
//   cout<<a->left->left->val<<endl;
//   cout<<a->right->val<<endl;
//   cout<<a->left->right->val<<endl;
//   cout<<a->right->left->val<<endl;
  display(a);


}
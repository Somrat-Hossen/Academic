#include<bits/stdc++.h>
using namespace std;


 int cnt=0,k=9,res;
class node
{
   public:
   int data;
   node *left,*right,*parent;
   node()
   {
      left=right=parent=nullptr;
   }
};

  node *root;
 class BST
 {
    public:
       BST()
       {
          root=nullptr;
       }

    node* Insert(node *root,int item)
    {
       if(root==nullptr)
       {
           node *newnode=new node;
           newnode->data=item;
           return newnode;
       }

       if(item<root->data)
       {
          node *tmp=Insert(root->left,item);
          root->left=tmp;
          tmp->parent=root;
       }
       else
       {
          node *tmp= Insert(root->right,item);
          root->right=tmp;
          tmp->parent=root;
       }

       return root;
    }

     void Inorder(node *root)
     {
        if(root==nullptr) return;

        Inorder(root->left);
        cout<<root->data<<" "; cnt++;

        if(cnt==k){res=root->data;}
        Inorder(root->right);
     }
 };




   int main()
   {
         BST t;

        root= t.Insert(root,5);
        root= t.Insert(root,10);
        root= t.Insert(root,15);
        root= t.Insert(root,30);
        root= t.Insert(root,12);
        root= t.Insert(root,17);
        root=t.Insert(root,8);
        root=t.Insert(root,4);
        root=t.Insert(root,3);

       t.Inorder(root);
      cout<<endl<<"The "<<k<<"th smallest num is: "<<res<<endl;

      return 0;
   }







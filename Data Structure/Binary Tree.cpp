#include<bits/stdc++.h>
using namespace std;

class node
{
   public:
   int data;
   node *left,*right;

   node()
   {
      left=NULL;
      right=NULL;
   }
};
node *root;

class tree
{

   public:
  // node * root;
   tree()
   {
      root=NULL;
   }

   void Insert(int item)
   {
      node *newnode=new node;
      newnode->data=item;

      if(root==NULL)
      {
        root=newnode;
      }

      else
      {
           node *current=root,*parrent;

           while(current!=NULL)
           {
              if(item<current->data)
              {
                   parrent=current;  ///keep track of the parrent node
                   current=current->left;
              }

              else
              {
                  parrent=current;
                  current=current->right;
              }
           }

           if( (newnode->data)< (parrent->data) ) parrent->left=newnode;
           else parrent->right=newnode;
      }
   }

/*
void Insert_recursion(node *root, int item)
{

   if(root==NULL)
   {
      node *newnode=new node;
      newnode->data=item;
      root=newnode;
   }

   if(item<root->data)
   {
      Insert_recursion(root->left,item);
   }
   else
   {
      Insert_recursion(root->left,item);
   }

}*/

 node *Minimum(node *tmp)
 {

     while(tmp->left!=NULL) ///for max ,left will changed to right
     {
        tmp=tmp->left;
     }
    // cout<<tmp->data<<endl;
    return tmp;
 }

 node *Maximum(node *tmp)
 {

     while(tmp->right!=NULL) ///for max ,left will changed to right
     {
        tmp=tmp->right;
     }
     //cout<<root->data<<endl;
     return tmp;
 }


   void print_preorder(node *current)
   {
        if(current==NULL) return;

        cout<<current->data<<endl;

        print_preorder(current->left);

        print_preorder(current->right);
   }

   node * Search(node * tmp,int item)
   {
       if(tmp==NULL) return NULL;
      cout<<tmp->data<<" "; ///path print
      if(tmp->data==item) return tmp;
      else if(item<tmp->data) return (Search(tmp->left,item));
      else return (Search(tmp->right,item));
   }
};

int main()
{

  tree t;

  t.Insert(55);
  t.Insert(40);
  t.Insert(80);
  t.Insert(34);
  t.Insert(28);
  t.Insert(38);
  t.Insert(60);
  t.Insert(90);

 ///root is declared as global node

  t.print_preorder(root);
  cout<<endl;
  ///cout<<(t.Minimum(root))->data<<endl;
  ///cout<<(t.Maximum(root))->data<<endl;

  node * tmp=t.Search(root,28);

  if(tmp==NULL ) cout<<"Data is not found"<<endl;
  else cout<<"Data found"<<endl;


  /* node *tmp=t.findPredecessor(root,40);
  if(tmp==NULL) cout<<"Not exist"<<endl;
  else cout<<"Exist "<<tmp->data<<endl;*/


  return 0;
}

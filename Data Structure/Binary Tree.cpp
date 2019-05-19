#include<bits/stdc++.h>
using namespace std;

class node
{
   public:

   int value;
   int data;
   node *left,*right;
};

class tree
{

   public:
   node * root;
   tree()
   {
      root=NULL;
   }

   void Insert(int item)
   {
      node *newnode=new node;
      if(root==NULL)
      {
        newnode->data=item;
        root=newnode;
      }

      else
      {
           node *current=root,*parrent;
           while(current!=NULL)
           {
              if(item<current->data)
              {
                   parrent=current;
                   current=current->left;
              }

              else
              {
                  parrent=current;
                  current=current->right;
              }

           }
           node *newnode=new node;
           newnode->data=item;

           if(newnode->data<parrent->data)  parrent->left=newnode;
           else parrent->right=newnode;
      }
   }

void Display()
{
   print_preorder(root);

}

   void print_preorder(node *current)
   {
        if(current==NULL) return;

        cout<<current->data<<endl;

        print_preorder(current->left);

        print_preorder(current->right);
   }

};

int main()
{

  tree t;

  t.Insert(10);
  t.Insert(5);
  t.Insert(17);
  t.Insert(10);
  t.Insert(4);
  t.Insert(20);
  t.Insert(7);
  t.Insert(3);


  t.Display();





  return 0;
}

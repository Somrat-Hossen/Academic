#include<bits/stdc++.h>
using namespace std;

class node
{
   public:
   int data;
   node *left,*right;
   node *parent;

   node()
   {
      left=NULL;
      right=NULL;
      parent=NULL;
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

   ///Search node
   node * Search(node * tmp,int item)
   {
       if(tmp==NULL) return NULL;
    //  cout<<tmp->data<<" "; ///path print

      if(tmp->data==item) return tmp;
      else if(item<tmp->data) return (Search(tmp->left,item));
      else return (Search(tmp->right,item));
   }

   ///delete node;
   node* deleteNode(node *root, int key)
   {
       // Base case
       if (root == NULL)
           return root;

       // Recursive calls for ancestors of
       // node to be deleted
       if (root->data > key)
       {
           root->left = deleteNode(root->left, key);
           return root;
       }
       else if (root->data <key)
       {
           root->right = deleteNode(root->right, key);
           return root;
       }

       ///we found the desired node ,now time to delete
   else
   {
       if(root->left==nullptr and root->right==nullptr) ///root has no child
       {
          delete root;
          root=nullptr;
          return root;
       }
      else if (root->left == NULL)  ///root has right child only
       {
           node* temp = root->right;
           delete root;
           return temp;
       }
       else if (root->right == NULL)  ///root has left child only
       {
           node* temp = root->left;
           delete root;
           return temp;
       }

             /// If both children exist
       else
       {
           node* succParent = root->right;

           /// Find successor
           node *succ = root->right;

           while (succ->left != NULL)
           {
               succParent = succ;
               succ = succ->left;
           }

           // Delete successor.  Since successor
           // is always left child of its parent
           // we can safely make successor's right
           // right child as left of its parent.
           succParent->left = succ->right;

           // Copy Successor Data to root
           root->data = succ->data;

           // Delete Successor and return root
           delete succ;
           return root;
       }
     }
   }


};

int main()
{

  tree t;

  t.Insert(47);
  t.Insert(40);
  t.Insert(54);
  t.Insert(38);
  t.Insert(43);
  t.Insert(49);
  t.Insert(39);
  t.Insert(45);
  t.Insert(44);
  t.Insert(30);
  t.Insert(41);
  t.Insert(70);
  t.Insert(46);
  t.Insert(59);

 ///root is declared as global node
  t.print_preorder(root);
  cout<<endl;
  ///cout<<(t.Minimum(root))->data<<endl;
  ///cout<<(t.Maximum(root))->data<<endl;

  //node * tmp=t.Search(root,28);

  //if(tmp==NULL ) cout<<"Data is not found"<<endl;
 // else cout<<"Data found"<<endl;


  root=t.deleteNode(root,30);
  puts("After delating the node,new tree is:");
  t.print_preorder(root);


  return 0;
}

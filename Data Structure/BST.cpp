#include<bits/stdc++.h>
using namespace std;


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

      node *Insert(node *tmp,int item)
      {
         if(tmp==nullptr)
         {
            node *newnode=new node;
            newnode->data=item;
            return newnode;
         }

         if(item<tmp->data)
         {
            node *newnode=Insert(tmp->left,item);
            tmp->left=newnode;
            newnode->parent=tmp;
         }
         else
         {
             node *newnode=Insert(tmp->right,item);
             tmp->right=newnode;
             newnode->parent=tmp;
         }
         return tmp;
      }

      void Inorder(node *root)
      {
         if(root==nullptr) return;

         Inorder(root->left);
         cout<<root->data<<" ";
         Inorder(root->right);
      }

      node *Search(node *root,int item)
      {
         if(root==nullptr) return nullptr;
         if(root->data==item) return root;

         if(item<root->data)  Search(root->left,item);
        else   Search(root->right,item);
      }

      node * Minimum(node *root)
      {
         while(root->left)
         {
            root=root->left;
         }

         return root;
      }

       node * Maximum(node *root)
      {
         while(root->right)
         {
            root=root->right;
         }

         return root;
      }

      node *Successor(node *findd)
      {
         if(findd->right) return Minimum(findd->right);

         node *par=findd->parent;
         while(par!=nullptr && findd==par->right)
         {
            findd=par;
            par=par->parent;

         }
         return par;
      }

      node *Precedessor(node *findd)
      {
         if(findd->left) return Maximum(findd->left);

         node *par=findd->parent;
         while(par!=nullptr && findd==par->left)
         {
            findd=par;
            par=par->parent;

         }
         return par;
      }

   node* Delete(node *root, int key)
   {
       // Base case
       if (root == NULL)
           return root;

       // Recursive calls for ancestors of
       // node to be deleted
       if (root->data > key)
       {
           root->left = Delete(root->left, key);
           return root;
       }
       else if (root->data <key)
       {
           root->right = Delete(root->right, key);
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

    int arr[]={50,30,20,40,60,80,47,35,48,55,75,65};
    int n=sizeof arr/sizeof arr[0];

    BST ob;
    for(int i=0;i<n;i++)
    {
       root=ob.Insert(root,arr[i]);
    }

    ob.Inorder(root);cout<<endl;

    node *tmp=ob.Search(root,60);
    if(tmp==nullptr) puts("Data not found:");
    else cout<<"Data is found "<<tmp->data<<endl;

    cout<<ob.Successor(root->left->left)->data<<endl;

    root=ob.Delete(root,30);
    puts("After delating the node,new tree is:");
    ob.Inorder(root);cout<<endl;

     return 0;
 }

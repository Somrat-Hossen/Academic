#include"bits/stdc++.h"
using namespace std;



class node
{
  public:
  int data;
  node *next;
};

class Stack
{
   node *top;

   public:

   Stack()
   {
     top=NULL;
   }

   void Insert(int item)
   {
      node *newnode=new node;
      newnode->data=item;
      newnode->next=top;
      top=newnode;
   }

   void pop()
   {
     if(top==NULL)
     {
       cout<<"Underflow"<<endl;
     }

     else
     {
       node *tmp=top;
       top=top->next;
       cout<<tmp->data<<" Is poped"<<endl;
        delete tmp;
     }
   }

   void Display()
   {
     if(top==NULL)
     {
       cout<<"Stack is empty"<<endl;
     }

     else
     {
       node *tmp=top;
       while(tmp!=NULL)
       {
         cout<<tmp->data<<" ";
         tmp=tmp->next;
       }
        cout<<endl;
     }

   }

   void Peek()
   {
     cout<<top->data<<endl;
   }
};

int main()
{
  Stack s;
  s.Insert(5);
  s.Insert(15);
  s.Insert(25);
  s.Insert(35);

  s.Display();
  s.pop();
  s.Display();


  return 0;
}

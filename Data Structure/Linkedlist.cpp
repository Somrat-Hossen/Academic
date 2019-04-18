#include<bits/stdc++.h>
using namespace std;

class node
{
   public:
   int data;
   node *next;
};

class Linkedlist
{
  node *head;
  public:

  Linkedlist()
  {
    head=NULL;
  }

  void Insert(int item)
  {
     node *newnode=new node();

     if(head==NULL)
     {
        newnode->data=item;
        newnode->next=NULL;
        head=newnode;
     }

     else
     {
        node *lastnode=head;

        while(lastnode->next !=NULL)
        {
           lastnode=lastnode->next;  ///Find the last node;
        }
        node *newnode=new node;

        lastnode->next=newnode;
        newnode->next=NULL;
        newnode->data=item;
     }
  }

  void Insert_first(int item)
  {
      node *newnode=new node();
      newnode->data=item;
      newnode->next=head;
      head=newnode;
  }

void Insert_before_item(int nod,int item)
{
    node *tmp=head;

    while((tmp->next) && (tmp->next->data!=nod))
    {
           tmp=tmp->next;
    }

   if(tmp->next==NULL)
   {
      cout<<"Item is not found:"<<endl;
      return;
   }

    node *newnode =new node();

    newnode->data=item;
    newnode->next=tmp->next;
    tmp->next=newnode;
}


 void Delete(int key)
 {
    node *tmp=head;

    if(head->data==key)  ///key is the first element
    {
       head=tmp->next;
      // head=head->next;
       delete(tmp);
       return;
    }

    else   /// This is  for last pos and for middle
    {
       while((tmp->next) && (tmp->next->data!=key))  ///Find the node before the last
       {
           tmp=tmp->next;
       }

       if(tmp->next==NULL)
       {
          cout<<"Item is not found:"<<endl; return;
       }
      else
      {
         node *newnode=tmp->next;
         tmp->next=newnode->next;  /// If key is at middle then there can be other node than the key
         delete(newnode);           /// so tmp-next = Null is invalid .
      }
    }
 }

 void Display()
  {
     node *tmp=head;
     cout<<"List is:"<<endl;

     while(tmp !=NULL)
     {
        cout<<tmp->data<<" ";
       tmp=tmp->next;
     }
     cout<<endl;
  }

};




int main()
{

  Linkedlist ob;

  ob.Insert(5);
  ob.Insert(10);
  ob.Insert(15);

  ob.Display();
  ob.Delete(12);  ///Delete respect to key it can be anywhere.
  ob.Display();

  ob.Insert_first(2); ///Insert first
  ob.Insert_before_item(16,12);///first node ,second item

  ob.Display();



  return 0;
}

#include<bits/stdc++.h>
#define size 10

using namespace std;

class node
{
     public:
     int data;
     node *next;
     node *prev;
     node (){next=nullptr;prev=nullptr;}
};

class Dequeue
{
   node *head,*tail;

   public:

   Dequeue()
   {
      head=tail=nullptr;
   }

    void Insert_front(int item)
    {
       node *tmp=new node;
       tmp->data=item;

       if(head==nullptr)
       {
          head=tail=tmp;
       }

       else
       {
           head->prev=tmp;
           tmp->next=head;
           head=tmp;
       }
       cout<<head->data<<" Is inserted"<<endl;
    }

    void Insert_rear(int item)
    {
       node *tmp=new node;
       tmp->data=item;

       if(tail==nullptr)
       {
          head=tail=tmp;
          head->prev=nullptr;
       }

       else
       {
          tmp->prev=tail;
          tail->next=tmp;
          tail=tmp;
       }
        cout<<tail->data<<" Is inserted"<<endl;
    }

    void Delete_front()
    {

        if(head==nullptr)
        {
           puts("Queue is empty");
           return;
        }
        node *newnode =new node;
        newnode=head;
        cout<<head->data<<" Is deleted"<<endl;
        head=head->next;

        if(head==nullptr) tail=nullptr;
         else head->prev=nullptr;
        delete newnode;
    }

    void Delete_rear()
    {
       if(tail==nullptr)
        {
           puts("Queue is empty");
           return;
        }
        node *newnode =new node;
        newnode=tail;
        cout<<tail->data<<" Is deleted"<<endl;
        tail=tail->prev;
        if(tail==nullptr) head=nullptr;
         else  tail->next=nullptr;

        delete newnode;
    }
};


int main()
{
   Dequeue ob;

   ob.Delete_front();
   ob.Insert_front(1);
   ob.Insert_rear(2);
   ob.Insert_front(3);
   ob.Insert_rear(4);

   ob.Delete_front();
   ob.Delete_rear();
   ob.Delete_front();
   ob.Delete_rear();
   ob.Delete_front();
   ob.Delete_rear();


   return 0;
}

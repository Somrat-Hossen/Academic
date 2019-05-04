#include <bits/stdc++.h>
using namespace std;

class node
{
  public:

    int data;
    node *next, *prev;
};

class Doubly_link_list
{
    private:
    node *head, *tail;
    public:

    Doubly_link_list()
    {
      head=NULL;
      tail=NULL;
    }


 void append(int item)
{
    node *newnode=new node();
    newnode->data=item;
    newnode->next=NULL;

	if(head==NULL) //If the list is empty
	{
		head=newnode;
		tail=newnode;
		newnode->prev=NULL;
	}
	else
	{
		newnode->prev=tail;
		tail->next=newnode; //add the new node after tail node
		tail=newnode; //move tail pointer forward
	}
}
void Display()
{
   node *tmp=head;
   while(tmp !=NULL)
   {
      cout<<tmp->data<<" ";
      tmp=tmp->next;
   }
   cout<<endl;
}

void Sort()
{
   node *i=head;
   node *j;
   cout<<"After Sorting : ";

      while(i->next!=NULL)
      {
         j=i->next;

         while(j!=NULL)
         {
           if(i->data > j->data)
           {
              swap(i->data,j->data);
           }
           j=j->next;
         }
         i=i->next;
      }

}


};

int main()
{
    Doubly_link_list ob;

   ob.append(3);
   ob.append(2);
   ob.append(1);
   ob.append(4);
   ob.append(5);
   ob.append(1);


   ob.Display();
   ob.Sort();
   ob.Display();


    return 0;
}



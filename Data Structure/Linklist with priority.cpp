#include <bits/stdc++.h>
using namespace std;

class node
{
  public:

    int data;
    node *next;
    int priority;
};

class linked_list
{
    private:
    node *head;

public:
    linked_list()
    {
        head = NULL;
    }

 void Insert(int item,int pr)
 {
        node *new_node = new node();

        new_node->data=item;
        new_node->priority=pr;
        new_node->next=NULL;

        node *current_node=head;

        if(new_node==NULL)
        {
            cout<<"Creating node is impossible"<<endl;
            exit(0);
        }

        if(head==NULL)
        {
           head=new_node;
           return;

        }
        if(current_node->priority>pr)
        {
           new_node->next=current_node;
           head=new_node;
        }

      else
	  {
	        /// Since i compare with first node before , so i run loop using next(current_node->next->priority)
		while((current_node->next!=NULL) && (pr >current_node->next->priority) ) //Find the exact position 
		{
		    //if(pr< current_node->next->priority) break;

			current_node=current_node->next; //go to next address
		}

		new_node->next=current_node->next;
		current_node->next=new_node; //link the last node with new node
	  }
 }


  void Display()
  {
     node *tmp=head;
     cout<<"Current data is:"<<endl;

     while(tmp!=NULL)
     {
        cout<<tmp->data<<" "<<tmp->priority<<endl;
        tmp=tmp->next;
     }
  }
};

int main()
{
    linked_list a;

    a.Insert(4,2);
    a.Insert(5,5);
    a.Insert(6,3);
    a.Insert(7,1);
    a.Insert(8,4);


    a.Display();
   // a.delete_node(2);
    //a.Display();

    return 0;
}



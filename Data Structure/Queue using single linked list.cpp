#include<bits/stdc++.h>
using namespace std;


class node
{
  public :
  int data;
  node * nxt;

  node()
  {
     nxt=nullptr;///Each node initially null
  }

};

class QUEUE
{
    node *frnt,*rear;
    public:

    QUEUE(){frnt=nullptr;}


    void  Push(int item)
    {
       node *newnode=new node;
       newnode->data=item;

       if(frnt==nullptr)
       {
          frnt=newnode;
          rear=newnode;
       }

       else
       {
          rear->nxt=newnode;
          rear=newnode;
       }

       cout<<item<<" Is pushed in the queue:"<<endl;
    }

    void Pop()
    {
       if(frnt==nullptr){puts("Underflow:");return;}


       cout<<frnt->data<<" Is Popped from the queue:"<<endl;
       frnt=frnt->nxt;
    }

    void Display()
    {
       if(frnt==nullptr) {cout<<"Queue is empty:"<<endl;return;}

       node *tmp=frnt;
       cout<<"Queue element is: ";


       while(tmp!=nullptr)
       {
          cout<<tmp->data<<" ";
          tmp=tmp->nxt;
       }
    }

    void  Getsize()
    {
       if(frnt==nullptr) {cout<<"Size is 0 "<<endl;return;}

       node *tmp=frnt;
       int cnt=0;
       while(tmp!=nullptr)
       {
          cnt++;
          tmp=tmp->nxt;
       }
       cout<<"Queue size is:"<<cnt<<endl;
    }

};




int main()
{
      int arr[]={9,6,8,7,10,5,4};
      int n=sizeof(arr)/sizeof(arr[0]);

      QUEUE obj;

      for(int i=0;i<n;i++)
      {
         obj.Push(arr[i]);
      }
      cout<<endl;

      obj.Pop();
      obj.Pop();
      cout<<endl;

     obj.Display();
     obj.Getsize();



   return 0;
}

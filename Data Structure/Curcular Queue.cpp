#include<bits/stdc++.h>
#define Size 5
using namespace std;

class Queue
{
  int Rear,Front;
  int que[Size];

  public:

  Queue()
  {
     Rear=Front=-1;
  }

    void Enqueue(int item)
    {

            if(Rear==-1 && Front==-1)
            {
              Rear=Front=0;
            }

            else
            {
              Rear=(Rear+1)%Size;
            }

            que[Rear]=item;
            cout<<item <<" is inserted"<<endl;
    }

  void Dequeue()
  {
    int value;

    if(Front==-1 && Rear==-1)
    {
      cout<<"Underflow"<<endl;
    }

  else
  {
      value=que[Front];

      if(Front==Rear)   ///means one element
      {
         Front=Rear=0;
      }

      else
      {

         Front=(Front+1)%Size;
      }
    cout<<value<<" Is Deleted."<<endl;
   }



  }
  void Display()
  {


    if(Front<=Rear)
    {
      for(int i=Front;i<=Rear;i++)
      {
        cout<<que[i]<<" ";
      }
      cout<<endl;
    }

    else
    {
      for(int i=Front;i<Size;i++)
      {
        cout<<que[i]<<" ";
      }
      cout<<endl;

      for(int i=0;i<=Rear;i++)
      {
         cout<<que[i]<<" ";
      }

      cout<<endl;
    }
  }

  void Is_full()
  {
    if((Rear+1)%Size==Front)
    {
      cout<<"Overflow"<<endl;
    }

    else cout<<"Queue is not full"<<endl;
  }

    void Is_empty()
    {
        if(Front==-1 && Rear==-1)
        {
          cout<<"Underflow"<<endl;
        }

         else cout<<"Queue is not empty"<<endl;
    }

};


int main()
{
  Queue ob;

  ob.Dequeue();

  ob.Enqueue(5);
  ob.Enqueue(55);
  ob.Enqueue(52);

  ob.Display();
  ob.Dequeue();
  ob.Display();
  return 0;
}

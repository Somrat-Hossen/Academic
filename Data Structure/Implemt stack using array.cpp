#include<bits/stdc++.h>
#define mx 10
using namespace std;

int stk[mx];


static int cnt=0;

class STACK
{
   int top;

   public:

   STACK (){top=-1;}

   void Push(int item)
   {
      if(top==mx-1) {puts("Stack overflow:");return;}///o index

      stk[++top]=item;   ///Keep track of the size of the stack using top
      cout<<item<<" is pushed in the array:"<<endl;

   }

   void Pop()
   {
      if(top==-1) {puts("Stack underflow:");return;}

      cout<<stk[top]<<" Is popped from the stack:"<<endl;
      --top;   ///size decrease
   }

   void Display()
   {
      cout<<"Stack element is: ";
      for(int i=top;i>=0;i--) cout<<stk[i]<<" ";cout<<endl;
   }

   void Getsize()
   {
      if(top==-1){cout<<"Size is 0 "<<endl;return;}
      cout<<"Stack current Size is: "<<top+1<<endl; ///o indexed so +1
   }

   void Peek()
   {
      if(top==-1){cout<<"No data found in the stack "<<endl;return;}
      cout<<"Stack top element is "<<stk[top]<<endl; ///o indexed so +1
   }

};



 int main()
 {
      int arr[]={9,6,8,7,10,5,4};
      int n=sizeof(arr)/sizeof(arr[0]);

      STACK obj;

      for(int i=0;i<n;i++)
      {
         obj.Push(arr[i]);
      }cout<<endl;

      obj.Pop();
      obj.Pop();
      cout<<endl;

      obj.Display();
      obj.Getsize();
      obj.Peek();
 }

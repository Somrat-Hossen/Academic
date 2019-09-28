#include<bits/stdc++.h>
using namespace std;

class addition
{
    public:
    int a,b,result;
    void sum();
};
   void addition::sum()
  {
      //cout<<"Enter your input:  "<<endl;
     // cin>>a>>b;
      printf("sum is:%d ",a+b);
  }

    int main()
    {
     addition obj;
     obj.a=5;
     obj.b=6;
     obj.sum();

     return 0;
    }


#include<bits/stdc++.h>
using namespace std;

class Secant
{
  double x;
  double error=0.00001;
  int mx_iteration=10,i=1;

  public:
  double Compute(double x)
  {
     return(x*x-4*x-10);
  }

  double Find_root(double x1,double x2)
  {
    cout<<"Iteration     x1   x2    x"<<endl;

     while(i<=mx_iteration)
     {
        x=(x1*Compute(x2)-x2*Compute(x1))/(Compute(x2)-Compute(x1));

        if(Compute(x)==0 || Compute(x)<=error ) break;
        x1=x2;
        x2=x;
        cout<<"  "<<i<<"         "<<x1<<"        "<<x2<<"   "<<x<<  "   "<<Compute(x1)<<"   "<<Compute(x2) <<endl;
        i++;
    }
    cout<<"The root is:"<<x<<endl;
  }
};


int main()
{
   double x1=10,x2=9;
   Secant ob;

   if(ob.Compute(x1)==ob.Compute(x2))
   {
      cout<<"Root is not possible:"<<endl;
   }
   else
   {
      ob.Find_root(x1,x2);
   }

  return 0;
}

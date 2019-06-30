#include<bits/stdc++.h>
using namespace std;

class Secant
{
  double x;
  double error=0.00001;
  int mx_iteration=100;

  public:
  double Compute(double x)
  {
     return double( (x*x)-(4*x)-10);
  }

  void Function(double x1,double x2)
  {
     if( Compute(x1)==Compute(x2) )
     {
       puts("The roots not lies between the given interval:");
       return;
     }
     cout<<"Iteration     x1   x2    x    Compute(x1)    Compute(x2) "<<endl;

     for(int i=1;i<=mx_iteration;i++)
     {
        x=(x1*Compute(x2)-x2*Compute(x1))/(Compute(x2)-Compute(x1));

        x1=x2;
        x2=x;
        cout<<"  "<<i<<"         "<<x1<<"        "<<x2<<"   "<<x<<  "   "<<Compute(x1)<<"   "<<Compute(x2) <<endl;
        if(Compute(x)==fabs(0.0) || (fabs(Compute(x))<=error) ) break;
    }
    cout<<"The root is:  "<<fixed<<setprecision(4)<<x<<endl;
  }
};


int main()
{
   double x1=4,x2=2;
   Secant ob;

  ob.Function(x1,x2);

  return 0;
}

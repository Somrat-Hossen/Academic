/// Find root of the eq x*x-4*x-10

#include<bits/stdc++.h>
#define mx 1000
using namespace std;

double error=0.00001;
int iteration=100000;


double func(double x)
{
   return double( (x*x)-(4*x)-10);
}


void Falsi_method(double a,double b )
{
   if( func(a)*func(b)>=0)
   {
      puts("The roots not lies between the given interval:");
      return;
   }

     double mid;


     for(int i=1;i<=iteration;i++)
     {
        mid= ( a*func(b)-b*func(a) )/( func(b)-func(a));

        if( (func(a)*func(mid))<0)  b=mid;     ///root lies between this interval,so update b by mid value

         else  a=mid;

       /// cout<<a<<"        "<<b<<"     "<<mid<<endl;

        if( (func(mid)==fabs(0.0)) or (fabs(func(mid))<=error)) break;///break the loop ,we found the root or matched error
     }

     cout<<endl<<"Final root is :"<<fixed<<setprecision(4)<<mid<<endl;
}



int main ()
{
  double num1,num2;

  puts("Give two assumed number:");

  cin>>num1>>num2;

  Falsi_method(num1,num2); ///Call the function for processing



   return 0;
}


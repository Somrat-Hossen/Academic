#include<bits/stdc++.h>
#define mx 100
using namespace std;


double res[mx][mx];
double n,error=0.0001;

double f(double x)
{
   return(1.0/x);
}

double Trapezoidal(int n)
{
   double a=1,b=2;  ///Assigning lower limit and upper limit
   double sum=0,h=(b-a)/(double)n;

   for(int i=0;i<=n;i++)
   {
      if(i==0 or i==n)
      {
         sum+=f(a+(double)i*h); ///first and last term doesn't contain any constant value
      }
      else
      {
         sum+=2*f(a+(double)i*h);
      }
   }
   return ((h/2)*sum);
}



double Update()
{
    int n=5;
    double result=0.0,pre_result=0.0;
     cout<<"n      result"<<endl;;
     cout<<"-----------------------"<<endl;

    while(1)
    {
       result=Trapezoidal(n);
       cout<<n<<"     "<< result<<endl;

       if(abs(result-pre_result)<error) break;

       n+=5;
       pre_result=result;
    }

   return result;
}


int main()
{

   cout<<"The final area is:"<< Update()<<endl;   ///Al values are global so do not need to pass as argument

   return 0;
}


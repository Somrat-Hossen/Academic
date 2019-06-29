#include<bits/stdc++.h>
using namespace std;

double a,b,h,n;

double f(double x)
{
   return(sqrt(1-(x*x)));
}


double Trapezoidal(double a,double b,int n)
{
   double sum=0;
   h=(b-a)/n;
   for(int i=0;i<=n;i++)
   {
      if(i==0 or i==n)
      {
         sum+=f(a+i*h); ///first and last term doesn't contain any constant value
      }
      else
      {
         sum+=2*f(a+i*h);
      }
   }
   return ((h/2)*sum);
}



int main()
{
   puts("Enter the num of point ,lower and upper limit:");
   cin>>n>>a>>b;

   cout<<"Trapezoidal area is: "<<Trapezoidal(a,b,n)<<endl;


   return 0;
}


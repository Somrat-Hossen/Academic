#include<bits/stdc++.h>
using namespace std;

double a,b,h,n;

double f(double x)
{
   return(1/x);
}


double Trapezoidal(double a,double b,int n)
{
   double sum=0;
   h=(b-a)/n;
   int tmp=1;

   for(int i=0;i<=n;i++)
   {
      if(i==0 or i==n)
      {
         sum+=f(a+i*h); ///first and last term doesn't contain any constant value
      }
      else
      {
        /* if(tmp==1) sum+=4*f(a+i*h);
         else if(tmp==2) sum+=2*f(a+i*h); ///keep track of the sequence 4 2 4
         else if(tmp==3) sum+=4*f(a+i*h);

         if(tmp==3) tmp=0;
         tmp++;*/

         if(i & 1) sum+=4*f(a+i*h);  ///(Δx​/3)[FIRST+4(sum of ODDs) +2(sum of EVENs)+LAST]
         else sum+=2*f(a+i*h);

      }
   }
   return ((h/3)*sum);
}



int main()
{
   puts("Enter the num of point ,lower and upper limit:");
   cin>>n>>a>>b;

   cout<<"Trapezoidal area is: "<<Trapezoidal(a,b,n)<<endl;


   return 0;
}



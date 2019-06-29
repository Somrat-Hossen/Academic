#include<bits/stdc++.h>
#define mx 100
using namespace std;


double res[mx][mx];
double a=1,b=2,n;

double f(double x)
{
   return(1.0/x);
}

double Trapezoidal(int n)
{
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

void Compute()
{

   for(int i=1;i<=n;i++)
   {
      for(int j=0;j<i;j++)
      {
         if(j==0) res[i][j]=Trapezoidal(pow(2,(i-1))); ///i means number of segment to pass each time
         else  res[i][j]=( (pow(4,j)*res[i][j-1])-(res[i-1][j-1]) )/(pow(4,j)-1);
      }
   }
}

void Display(int n)
{
   cout<<"The final output:"<<endl;
   for(int i=1;i<=n;i++)
   {
      for(int j=0;j<i;j++)
      {
         cout<<fixed<<setprecision(6)<<res[i][j]<<"  ";
      }
      cout<<endl;
   }
}


int main()
{

   puts("Enter the number of point:");
   cin>>n;

   Compute();   ///Al values are global so do not need to pass as argument
   Display(n);


   return 0;
}

#include<bits/stdc++.h>
#define mx 10000
using namespace std;

class data
{
public:
   double x,y;

}arr[mx];

double Compute(int n, double val )
{
   double sum=0,mul;

   for(int i=0;i<=n;i++)
   {
       mul=1;
      for(int j=0;j<=n;j++)
      {
         if(i!=j)
         {
            mul*=(val-arr[j].x)/(arr[i].x-arr[j].x);
         }
      }
      sum+=(arr[i].y*mul);
   }
   return (sum);
}




int main()
{
   int n;
   double val;
   cin>>n>>val;

   for(int i=0;i<=n;i++)
   {
      cin>>arr[i].x>>arr[i].y;
   }

  cout<<fixed<<setprecision(2)<<Compute(n,val)<<endl;

}


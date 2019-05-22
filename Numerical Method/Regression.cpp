#include<bits/stdc++.h>
#define mx 10000
using namespace std;

class data
{
public:
   int x,y;
}arr[mx];

int xi_yi(int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
   {
      sum+=arr[i].x*arr[i].y;
   }
   return (sum);
}
int xi(int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
   {
      sum+=arr[i].x;
   }
   return (sum);
}
int yi(int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
   {
      sum+=arr[i].y;
   }
   return (sum);
}
int xi_sq(int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
   {
      sum+=(arr[i].x*arr[i].x);
   }
   return (sum);
}
int xi_whole(int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
   {
      sum+=arr[i].x;
   }
   return (sum*sum);
}



int main()
{
   int n,x;
   double a,b;
   cin>>n;

   for(int i=0;i<n;i++)
   {
      cin>>arr[i].x>>arr[i].y;
   }

   b=(n*xi_yi(n)-(xi(n)*yi(n)))/(double)(n*xi_sq(n)-xi_whole(n));
   a=( yi(n)-(b*xi(n)) )/double(n);

   cout<<fixed<<setprecision(4)<<a<<"   "<<fixed<<setprecision(4)<<b<<endl;

}

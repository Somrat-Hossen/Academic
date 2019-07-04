#include<bits/stdc++.h>
#define mx 1000
using namespace std;

int n,m;

   class data
   {
       public:
       double x,y;

   }arr[mx]; ///array of pointer for x and f(x) as for input

   double fun(int r,int l) ///start and end
   {
        if(r==l) return arr[r].y;

        if(r+1==l)
        {
                return ((arr[l].y-arr[r].y)/(arr[l].x-arr[r].x));
        }
        return (fun(r+1,l)-fun(r,l-1) )/(arr[l].x-arr[r].x);
   }

   double fun2(int i,double x)
   {
        double tmp=1;

        for(int j=0;j<i;j++)
        {
                tmp*=(x-arr[j].x);
        }
        return tmp;
   }

int main()
{
     int i,j;

     cin>>n;
     for(i=0;i<n;i++)
     {
             cin>>arr[i].x>>arr[i].y;  ///x and f(x) as input
     }

     double x,f_of_x=0;
     cin>>x;

     for(i=1;i<=n;i++)
     {
       f_of_x+=(fun(0,i)*fun2(i,x));
     }

     cout<<f_of_x+arr[0].y<<endl;

	return 0;
}








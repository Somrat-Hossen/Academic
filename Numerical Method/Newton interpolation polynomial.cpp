#include<bits/stdc++.h>
#define mx 1000
using namespace std;

int n,m;

   class data
   {
       public:
       double x,y;

   }arr[mx]; ///array of pointer for x and f(x) as for input

   double fun(int l,int r) ///start and end
   {
        if(r==l) return arr[l].y;

        if(l+1==r)
        {
                return ((arr[r].y-arr[l].y)/(arr[r].x-arr[l].x));  ///calculation of a0,a1,a2
        }
        return (fun(l+1,r)-fun(l,r-1) )/(arr[r].x-arr[l].x);
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

     cout<<f_of_x+arr[0].y<<endl;///we skip a0(f0)

	return 0;
}








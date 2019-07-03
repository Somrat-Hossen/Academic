/***************** Newtons interpolation **************/
#include<bits/stdc++.h>
#define mx 1000
using namespace std;


class data
{
   public:
   double x,y;

}arr[mx];


void Compute(int n,double a)
{
     double sum=0,mult;
     int i,j;

    for(j=0;j<n-1;j++)///find a0,a1,a2
    {
        for(i=n-1;i>j;i--)
        {
            arr[i].y =( (arr[i].y)- (arr[i-1].y))/( (arr[i].x)-(arr[i-j-1].x ));
        }
    }

    for(i=n-1;i>=0;i--) //multiply and sum
    {
        mult=1;
        for(j=0;j<i;j++)
        {
            mult*=(a-arr[j].x);

        }

        mult*=arr[j].y;
        sum+=mult;
    }
    cout<<"The result is: "<<setprecision(6)<<sum;
}


int main()
{

   /// freopen("in.txt","r",stdin);
    int n,i,j;
    double a;

   puts("Give the number of point: with their functional value");
    cin>>n;
    for(i=0;i<n;i++)
    {
     cin>>arr[i].x>>arr[i].y;
    }

    puts("Give the point to find the value");
    cin>>a;
   /* for(i=0;i<n;i++)
    {
     cout<<arr[i].x<<" "<<arr[i].y<<endl;
    }*/

     Compute(n,a);


    return 0;
}

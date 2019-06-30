#include<bits/stdc++.h>
#define mx 100
using namespace std;

double arr[mx][mx], x[mx]; ///global array contains 0 as garbage value
double error=0.0001,relative_err,mx_err;

void Compute(int n)
{
   for(int t=1;t<=50;t++)
    {
       mx_err=0.0;
        for(int i=1;i<=n;i++ )
        {
            double sum=0;
            for(int j =1; j <= n; j++ )
            {
                if(i!=j ) ///ramained  unchange the ith and jth cell
                {
                    sum += (arr[i][j] * x[j]);
                }
            }
            sum = ( arr[i][n+1] - sum);
            sum = sum / arr[i][i];

            relative_err=fabs((x[i]-sum)/sum);///This error finding part is advanced
            if(relative_err>mx_err)
            {
               mx_err=relative_err;
            }

            x[i] = sum;
        }
    }

    if(mx_err>error)
    {
       puts("Error is not compatible with the given error:");
       return;
    }
    else
    {
       for(int i = 1; i <= n; i++)
       {
         cout<<fixed<<setprecision(4)<<x[i]<<" ";
       }
    }
}
int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
    {
        for( int j =1;j <=n+1;j++ )
        {
            cin>>arr[i][j];
        }
    }

    Compute(n);


   return 0;
}


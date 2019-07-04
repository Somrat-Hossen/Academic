#include<bits/stdc++.h>
#define mx 100
using namespace std;

double arr[mx][mx], res[mx],tmp[mx]; ///global array contains 0 as garbage value
double error=0.0001,relative_err,mx_err;

void Compute(int n)
{
   int i,k,j;

   for(int it=1;it<=4;it++) ///keep track of the num of iteration
   {
        for(i=0;i<n;i++ )
        {
            double sum=0;
            for( j =0;j<n;j++ )
            {
                if(i!=j ) ///ramained  unchange the ith and jth cell
                {
                    sum += (arr[i][j] * res[j]);
                }
            }
            tmp[i]=(arr[i][n]-sum)/arr[i][i];  ///Store the present result in a temporary array.
        }

        /*As the method describe that the previous computed result will be used in the next state ,so i did not change the
        initial result in this step ,after computed one step i assign the result in the final array.
        */
      for( k=0;k<n;k++) res[k]=tmp[k]; ///Replace the present result in our res array.

      cout<<"Iteration "<<it<<":  ";
      for( k=0;k<n;k++) cout<<"X"<<k+1<<"="<<res[k]<<", ";
      cout<<endl;
    }

    /*if(mx_err>error)
    {
       puts("Error is not compatible with the given error between this iteration:");
       return;
    }
    else
    {
       for(int i = 1; i <= n; i++)
       {
         cout<<fixed<<setprecision(4)<<x[i]<<" ";
       }
    }*/
}
int main()
{
    ///freopen("in.txt","r",stdin);

    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
    {
        for( int j=0;j<=n;j++ )
        {
            cin>>arr[i][j];
        }
    }

    Compute(n);


   return 0;
}



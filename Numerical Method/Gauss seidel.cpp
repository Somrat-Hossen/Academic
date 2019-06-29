 #include<bits/stdc++.h>
 using namespace std;

double arr[100][100] , x[100] = {0};


void Compute(int n)
{
   for(int t=1;t<=50;t++)
    {
        for(int i=1;i<=n;i++ )
        {
            double sum=0;
            for(int j =1; j <= n; j++ )
            {
                if( i != j ) ///ramained  unchange the ith and jth cell
                {
                    sum +=  ( arr[i][j] * x[j] );
                }
            }
            sum = ( arr[i][n+1] - sum );
            sum = sum / arr[i][i];
            x[i] = sum;
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

    for(int i = 1; i <= n; i++)
    {
      cout<<x[i]<<" ";
    }


   return 0;
}

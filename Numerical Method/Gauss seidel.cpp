 include<bits/stdc++.h>
using namespace std;

int main()
{
    double arr[100][100] , x[100] = {0};
    int n,i,j,t=1;
    cin>>n;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n+1; j++ )
        {
            cin>>arr[i][j];
        }
    }
    for( t=1; t<=50; t++)
    {
        for( i = 1; i <= n; i++ )
        {
            double sum = 0;
            for( j = 1; j <= n; j++ )
            {
                if( i != j ) ///ramaining unchange the ith and jth row-col
                {
                    sum +=  ( arr[i][j] * x[j] );
                }
            }
            sum = ( arr[i][n+1] - sum );
            sum = sum / arr[i][i];
            x[i] = sum;
        }
    }

    cout<<endl;

    for( i = 1; i <= n; i++)
    {
                                                                                                  cout<<x[i]<<" ";
    }
    return 0;
}

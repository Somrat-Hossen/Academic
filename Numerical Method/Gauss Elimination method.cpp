#include<bits/stdc++.h>
using namespace std;

int n;
double matrix[50][51];
double res[500];

void Display(int n)
{
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<=n;j++)
        {
          cout<<fixed<<setprecision(2)<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void gauss_solve()
{
	int i,j,k;
  	double t;

  for (i=0;i<n-1;i++)
  {                    ///Pivotisation
        for (j=i+1;j<n;j++)
        {
            if (fabs(matrix[i][i])<fabs(matrix[j][i]))
            {
                for (k=0;k<=n;k++)
                {
                   swap(matrix[i][k],matrix[j][k]);
                }
             }
         }
    }

     cout<<"After Pivoting the Matrix is:"<<endl;
     Display(n);

    for (i=0;i<n-1;i++)
    {                           /// gauss elimination to remove coefficient zero
        for (j=i+1;j<n;j++)
        {
           double t=matrix[j][i]/matrix[i][i];
            for (k=i;k<=n;k++)
            {
                 matrix[j][k]=matrix[j][k]-(t*matrix[i][k]);
                 ///Mainly :matrix[j][k]-= (matrix[i][k]/matrix[i][i])*matrix[j][i]
                 ///but matrix[j][i]/matrix[i][i] common for all col in a row so
                 /// the statement written as above....

            }
        }

        Display(n);  ///print output each time after deleting the co  efficient
        cout<<endl;
    }


      cout<<"After Eliminating the Coefficient:"<<endl<<endl;
      Display(n);

  	/// Do the back substitution

    double sum=0;

    res[n-1]=matrix[n-1][n]/matrix[n-1][n-1];   ///last num with one coefficient devided by the rightside value

    for(i=n-2; i>=0; i--)
    {
        sum=0;
        for(j=i+1;j<=n;j++)
        {
            sum=sum+matrix[i][j]*res[j];
        }
        res[i]=(matrix[i][n]-sum)/matrix[i][i];
    }

    cout<<endl;

    ///print the final output

    for (i=0;i<n;i++)
    {
        cout<<"X"<<i+1<<" = "<<res[i]<<endl;
    }
    cout<<endl;
}

int main()
{
  	int i, j;

  	freopen("in.txt","r",stdin);
  	cin>>n;

  	for (i=0;i<n;++i)
  	{
		for (j=0;j<n+1;++j)
		{
			cin>>matrix[i][j];
		}
	}

  	gauss_solve();

  	return 0;
}

#include<bits/stdc++.h>
using namespace std;

// ====================================================================
int n,m;
double xx[100],yy[100],a[100];
double dp[100][100]={0};

/*
double funtion(int tmp)
{
        double a=tmp;
        return pow(a,5)+(6*pow(a,4))-(2*pow(a,3))+ 4;
}
int main()
{
        freopen("in.txt","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        int i,j,t,tcs(0),len,tmp,k,u,v,cnt(0),mx=INT_MIN,mn=INT_MAX;

        cout<<5<<endl;
        for(i=0;i<=8;i++)
        {
                tmp=rand()%10;
                cout<<tmp<<' '<<precise(5)<<fun(tmp)<<endl;
        }
        tmp=5;
cout<<tmp<<' '<<precise(5)<<fun(tmp)<<endl;
	return 0;
}
*/



double fun(int start,int endd)
{
        if(start==endd) return yy[start];
        if(start+1==endd)
        {
                return ((yy[endd]-yy[start])/(xx[endd]-xx[start]));
        }
        return (fun(start+1,endd)-fun(start,endd-1) )/(xx[endd]-xx[start]);
}

double fun2(int i,double x)
{
        double tmp=1;
        for(int j=0;j<i;j++)
        {
                tmp*=(x-xx[j]);
        }
        return tmp;
}

int main()
{
        int i,j;

        cin>>n;
        for(i=0;i<n;i++)
        {
                cin>>xx[i]>>yy[i];
        }

        double x,f_of_x=0;
        cin>>x;
        for(i=1;i<=n;i++)
        {
                //DEBUG(f_of_x,fun(0,i),fun2(i,x));
                f_of_x+=(fun(0,i)*fun2(i,x));
        }

        cout<<f_of_x+yy[0]<<endl;

	return 0;
}








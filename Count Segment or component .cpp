#include<bits/stdc++.h>
using namespace std;
int vis[1000],ver, eg, u,v,src,i,tmp,s,cnt=0;
vector<int> vec[100];
queue<int> que;

void Bicolorable(int src)
{
  que.push(src); vis[src]=1;
    while(!que.empty())
    {
        tmp= que.front();que.pop();
            for(i=0; i<vec[tmp].size(); i++)
            {
            s=vec[tmp][i];
            if(vis[s]==0)
             {
               que.push(s);
               vis[s]=1;
             }
            }
    }
}

    int main()
     {
        freopen("in.txt","r",stdin);
        cin>>eg>>ver;

        for(i=0;i<eg;i++ )
         {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
         }
        for(i=1;i<=ver;i++)
         {
         if(vis[i]==0)
           {
          cnt++;
          Bicolorable(i);
           }
         }
        cout<<endl<<"Total segment :"<<cnt<<endl;

        return 0;
    }

#include<bits/stdc++.h>
#define mx 10005
using namespace std;

typedef pair<int,int> pr;
vector<int>edge[mx];
int u,v,src;

stack<int>path;
bool vis[mx];


void dfs(int src)
{
   if(vis[src]) return;
   vis[src]=1;

   for(int i=0;i<edge[src].size();i++)
   {
      dfs(edge[src][i]);
   }

   path.push(src);///Push the vertex when all the child of the vertex is visited.
}

void Topsort(int n)
{

    for(int i=1;i<=n;i++)
    {
       if(!vis[i])
       {
          dfs(i);
       }
    }

    cout<<"Topological order is : ";

    while(!path.empty())
    {
       cout<<path.top()<<" ";
       path.pop();
    }
    cout<<endl;

}


int main()
{
   freopen("in.txt","r",stdin);

   int ed,node;
   cin>>node>>ed;

   for(int i=1;i<=ed;i++)
   {
      cin>>u>>v;
      edge[u].push_back(v);
   }

  /* for(int i=1;i<=node;i++)
   {
      cout<<i<<": ";
      for(int j=0;j<edge[i].size();j++)
      {
         cout<<edge[i][j]<<" ";
      }
      cout<<endl;
   }*/

   Topsort(node);


   return 0;
}

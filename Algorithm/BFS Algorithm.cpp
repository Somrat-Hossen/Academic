#include <bits/stdc++.h>
#define mx 200005
#define white 0
#define gray 1
#define black 2
typedef long long ll;
using namespace std;

int color[mx];
vector<int>adj[mx];
int dis[mx],parent[mx];


void BFS_traverse(int src, int node)
{

   queue<int>que;

   que.push(src);
   cout<<"Traversing order :"<<endl;

   while( ! que.empty() ) ///if queue is empty then returns 1 ,else 0
   {
         int u=que.front();
         cout<<u<<" ";
         que.pop();

         for(int i=0;i<adj[u].size();i++)
         {
            int v=adj[u][i];

            if(color[v]==white)
            {
               color[v]=gray;
               dis[v]=dis[u]+1;
               parent[v]=u;
               que.push(v);
            }
         }

         color[u]=black;  ///all of u's child are visited
   }

}


int main()
{

 freopen("in.txt","r",stdin);


   int node,edge;
   int u,v;

   cin>>node>>edge;

   for(int i=1;i<=edge;i++)
   {
      cin>>u>>v;

      adj[u].push_back(v);
      adj[v].push_back(u);
   }


   BFS_traverse(1,node);

    return 0;
}


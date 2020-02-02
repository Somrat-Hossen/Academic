#include<bits/stdc++.h>
#define mx 100000
using namespace std;

class edge
{
     public:
     int u,v,w; ///source ,des ,cost respectively
};

vector<edge>adj,path;
int parent[mx],mstvalue;

bool cmp(edge a,edge b)
{
   return (a.w<b.w);     ///if condition is not true then it swap
}

void Initialize(int n)
{
   for(int i=1;i<=n;i++)
   {
      parent[i]=i;///initially all node's parent is that node;
   }
}

int Find(int x)          ///check the representative
{
   if(parent[x]==x) return x;
   return parent[x]=Find(parent[x]); ///path compression
}

void Kruskal(int n,int e)
{
    Initialize(n);

    sort(adj.begin(),adj.end(),cmp); ///sort the adj vector in increasing order

   cout<<endl<<"Src  Des  Cost"<<endl;
   cout<<"---------------------------------------"<<endl;

    for(int i=0;i<e;i++)
    {
       cout<<adj[i].u<<"   "<<adj[i].v<<"   "<<adj[i].w<<endl;  ///print after increasing order (cost)
    }

    int cnt=0;
    for(int i=0;i<adj.size();i++)
    {
       int upr=Find(adj[i].u);
       int vpr=Find(adj[i].v);

       if(upr ==vpr) continue;      ///if the upr==vpr then it makes cycle

       else
       {
          if(cnt==n-1) break;
          path.push_back(adj[i]);  ///taken in the mst
          mstvalue+=adj[i].w;     ///add the cost
          parent[vpr]=upr;        ///it has been taken so parent updated
          cnt++;                  ///keep track of the taken node
       }
    }

}



int main()
{

   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

   freopen("in.txt","r",stdin);

   int a,b,wet,n,e;

   cin>>n>>e;

   for(int i=0;i<e;i++)
   {
      cin>>a>>b>>wet; ///a node con to b with cost wet

      edge input;

      input.u=a;
      input.v=b;
      input.w=wet;

      adj.push_back(input);
   }

   Kruskal(n ,e);

   cout<<"Minimum cost is :"<<mstvalue<<endl;

   cout<<endl<<"Final MST is: "<<endl;
   for(int i=0;i<path.size();i++)
   {
      cout<<path[i].u<<"   "<<path[i].v<<"  "<<path[i].w<<endl;
   }

   return 0;
}

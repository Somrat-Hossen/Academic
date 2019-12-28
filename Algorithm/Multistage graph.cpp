#include <bits/stdc++.h>
#define mx 200005
#define inf INT_MAX;

typedef long long ll;
using namespace std;

struct graph
{
   int src,des,wet;
};

vector<graph>adj[mx];
int child[mx],dis[mx],cost[mx];
int k;
vector<int>path;

void Multistage(int n)
{
      cost[n]=0;///destination has no cost for backtraverse
      child[n]=0;///null

   for(int i=n-1;i>=1;i--) ///backtraverse during computation
   {
       cost[i]=inf;
       int minchild=INT_MAX;///max value of int range

       for(int j=0;j<adj[i].size();j++)
       {
          int u=adj[i][j].src;
          int v=adj[i][j].des;
          int w=adj[i][j].wet;

          if(cost[i]>w+cost[v])
          {
              ///cost[v] ,child cost
              cost[i]=min(w+cost[v],cost[i]); ///formula : minimumchild cost with its child cost
              minchild=v;///keep track of the minimumcost child of each node
          }
       }
       child[i]=minchild;
   }
  /// for(int i=1;i<=n;i++) cout<<cost[i]<<" ";cout<<endl;
  /// for(int i=1;i<=n;i++) cout<<i<<" "<<child[i]<<endl;;cout<<endl;

   cout<<"Minimum cost is : "<<cost[1]<<endl;

   int source=1;
   path.push_back(1);

///for path
   while( source!=n)
   {
     /// cout<<child[source]<<" ";
      if(child[source]!=0) path.push_back(child[source]);///ignore 0 for destination node child;
      source=child[source];
   }

   cout<<"Path from source to destination : ";
   for(auto x:path) cout<<x<<"-->";cout<<endl;///Print path from the child table

}

int main()
{

   freopen("in.txt","r",stdin);
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);


	int u,v,w,n,k,e;

	cin>>n>>e>>k;

	for(int i=0;i<e;i++)
   {
      cin>>u>>v>>w;

      graph input;
      input.src=u;
      input.des=v;
      input.wet=w;

      adj[u].push_back(input);///create adjacency list first
      ///Each vector element contains three 3 field,(source,destination,weight)

   }

/*
   for(int i=1;i<=n;i++)
   {
      cout<<i<<": ";
      for(int j=0;j<adj[i].size();j++)
      {
         cout<<adj[i][j].src<<" "<<adj[i][j].des<<" "<<adj[i][j].wet<<endl;
      }
   }
   */
   Multistage(n);


    return 0;
}


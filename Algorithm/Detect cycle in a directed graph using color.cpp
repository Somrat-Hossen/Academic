#include <bits/stdc++.h>
#define mx 100005
#define white 0
#define gray 1
#define black 2

typedef long long ll;
using namespace std;

int color[mx];
vector<int>adj[mx];
int node,edge;

bool BFS_visit(int src)
{
    ///if(color[src]==gray || color[src]==black) return;
    ///cout<<src<<" ";

    color[src]=gray;

    for(int i=0;i<(int)adj[src].size();i++)
    {
       if( color[adj[src][i]]==gray) return 1; ///true means found cycle
        if(color[adj[src][i]]==white && BFS_visit(adj[src][i]) )return 1;
    }
   // cout<<src<<" ";
    color[src]=black;
    return false;
}


bool Cycle()
{
    for(int i=0;i<node;i++)
    {
        if(color[i]==white)
        {
          if( BFS_visit(i) ) return 1;

        }
    }
    return 0;

}

int main()
{

   freopen("in.txt","r",stdin);
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

  cin>>node>>edge;

  int u,v,src;

  for(int i=0;i<edge;i++)
  {
      cin>>u>>v;
      adj[u].push_back(v);
      //adj[v].push_back(u);
  }

   if( Cycle()) cout<<"Cycle is detected:"<<endl;
   else cout<<"Cycle is not detected:"<<endl;



    return 0;
}

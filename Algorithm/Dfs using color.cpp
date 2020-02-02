#include <bits/stdc++.h>
#define mx 100005
#define white 0
#define gray 1
#define black 2

///white means unvisited,gray means being visited not finished,black means finished.

typedef long long ll;
using namespace std;

int color[mx];
vector<int>adj[mx];
int node,edge,component;

void DFS_visit(int src)
{
    //if(color[src]==gray || color[src]==black) return;
    cout<<src<<" ";
    color[src]=gray;

    for(int i=0;i<(int)adj[src].size();i++)
    {
       int v=adj[src][i];

       if(color[v]==white)
       {

         DFS_visit(v);
       }
    }
    //cout<<src<<" ";
    color[src]=black;
}


void DFS(int src)
{
    for(int i=1;i<=node;i++)
    {
        if(color[i]==white)
        {
            DFS_visit(i);
            component++;
        }
    }

    cout<<endl<<"Number of component is: "<<component<<endl;
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
      adj[v].push_back(u);
  }

  cin>>src;
  DFS(src);



    return 0;
}

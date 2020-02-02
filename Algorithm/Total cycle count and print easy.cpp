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
int node,edge;
int parent[mx],tmp;
int st,fis;

void Print(int des,int st)
{
    cout<<"Cycle "<<tmp<<" is : ";
    while(st!=des)
    {
       cout<<des<<" ";
       des=parent[des];
    }
    cout<<des<<" ";
    cout<<endl;
}

void BFS_visit(int src)
{
    ///if(color[src]==gray || color[src]==black) return;
    color[src]=gray;

    for(int i=0;i<(int)adj[src].size();i++)
    {
       ///if same vertex is in the gray set or in gray color ,this found a cycle
      // if( color[adj[src][i]]==white) parent[adj[src][i]]=src;
       if( color[adj[src][i]]==gray)  ///gray means found cycle,backage
       {
           tmp++;
           Print(src,adj[src][i]); continue;
       }

        if( (color[adj[src][i]]==white))
        {
           parent[adj[src][i]]=src;
           BFS_visit(adj[src][i]);
        }
    }
   // cout<<src<<" ";
    color[src]=black;
}


void Cycle()
{
    for(int i=0;i<node;i++)
    {
        if(color[i]==white)
        {
           parent[i]=-1;
           BFS_visit(i);
        }
    }
}

void Initialize(int node)
{
   for(int i=1;i<=node;i++)
   {
      parent[i]=-1;
      color[i]=white;
   }
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

  Initialize(node);


  Cycle();

 // for(int i=1;i<=node;i++) cout<<i<<": "<<parent[i]<<endl;

  cout<<"Total cycle is: "<<tmp<<endl;

    return 0;
}


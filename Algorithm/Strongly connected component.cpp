#include <bits/stdc++.h>
#define mx 100005
#define white 0
#define gray 1
#define black 2

typedef long long ll;
using namespace std;

int color[mx],start[mx],finis[mx],cnt=1;
vector<int>adj[mx];
vector<int>Transpose[mx];
vector<int>component;
stack<int>topsort;
int node,edge,total_comp;

void DFS_visit(int src)
{
   /// if(color[src]==gray || color[src]==black) return;
    ///cout<<src<<" ";

    color[src]=gray;
   /// start[src]=cnt;cnt++;

    for(auto v: adj[src]) ///all child of the node
    {
       if(color[v]==white) DFS_visit(v);
    }
   /// finis[src]=cnt;cnt++;
    ///cout<<src<<" ";
    color[src]=black;
    ///topsort stack contains the topological order .
    topsort.push(src);///Push the vertex when all the child of the vertex is visited.
}

void DFS_Transpose(int src)
{

    component.push_back(src);///current element of the current component;
    color[src]=gray;

    for(auto v: Transpose[src]) ///all child of the node
    {
       if(color[v]==white) DFS_Transpose(v);
    }
    color[src]=black;
}


void DFS()
{
    for(int i=1;i<=node;i++) ///node start with 1,2,3,
    {
        if(color[i]==white)
        {
            DFS_visit(i);
        }
    }
}
void DFS2()
{
   for(int i=1;i<=node;i++) color[i]=white;///initialize the color again

     int flag=1;

      while( !topsort.empty()) ///while the stack is not empty ,extract the topsorted element and call the transpose dfs
      {                         ///Stack top element is the highest finishing time.
            int x=topsort.top();
             topsort.pop();

            if(color[x]==white)
            {
               DFS_Transpose(x);
               total_comp++;

               cout<<"Component "<<flag<<": ";
               for(auto it: component) cout<<it<<"---->";cout<<endl;///print the component one by one
               component.clear();  ///clear the first component element
               flag++;
            }
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

  int u,v;

  for(int i=0;i<edge;i++)
  {
      cin>>u>>v;
      adj[u].push_back(v);///for adjacency list
      Transpose[v].push_back(u); ///for transpose list
  }

  DFS(); ///first dfs call for creating topological sort

  DFS2();///call for the transpose adjacency list and print each component
  cout<<"Total component is: "<<total_comp<<endl;

 /// for(int i=1;i<=node;i++) cout<<i<<":"<<start[i]<<"/"<<finis[i]<<endl;



    return 0;
}

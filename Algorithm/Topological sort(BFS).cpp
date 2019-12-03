#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int n,e,i,u,v,w,ch;
int indeg[mx];
vector<int>edge[mx];
queue<int>que;
vector<int>path;
vector<string>paths;

map<string ,int>mps;
map<int ,string >mpi;
int flug=0;


void Topological(int n)
{
   for(int i=1;i<=n;i++)
   {
      if(indeg[i]==0) que.push(i);
   }

     while(!que.empty())
     {
        int pa=que.front();
        que.pop();
        paths.push_back(mpi[pa]); ///push string in a vector of string type

        for(int i=0;i<edge[pa].size();i++)
        {
           ch=edge[pa][i];
           indeg[ch]--;
           if(indeg[ch]==0) que.push(ch);
        }
           flug++;
     }

     if(flug==n) cout<<"Cycle is Not found"<<endl;
     else cout<<"Cycle is Found"<<endl;
}


int main()
{
   freopen("in.txt","r",stdin);

   cin>>n;

   ///Without mapping
  /* for(int i=0;i<n;i++)
   {
      cin>>u>>v;
      indeg[v]++;
      edge[u].push_back(v);
   }
   Topological(n);

   for(int i=0;i<path.size();i++)
   {
      cout<<path[i]<<" "<<endl;
   }*/

   int cnt=0;///node will be mapped from 1
   int u,v;
   string s1,s2;
   int node=0;

   for(int i=1;i<=n;i++)
   {
      cin>>s1>>s2;
      if(mps.find(s1)!=mps.end())
      {
         u=mps[s1];
         mpi[u]=s1;///If we want to print the path,so int hold string
      }
      else
      {
         mps[s1]= ++cnt;
         u=cnt;
         mpi[u]=s1;
         node++;

      }

      if(mps.find(s2)!=mps.end())
      {
         v=mps[s2];
          mpi[v]=s2;
      }
      else
      {
         mps[s2]=++cnt;
         v=cnt;
          mpi[v]=s2;
          node++;
      }

      indeg[v]++;           ///count indegree of each node
      edge[u].push_back(v);     ///Directed graph
   }

 /* for(int i=1;i<=node;i++) cout<<indeg[i]<<" "; ///print indegree
   cout<<endl;

   for(int i=1;i<=node;i++)
   {
      cout<<mpi[i]<<": ";
      for(int j=0;j<edge[i].size();j++)
      {
         cout<<mpi[edge[i][j] ]<<" ";  ///print the adjacency list
      }
      cout<<endl;
   }
   */

   Topological(node);///node is no of total node in the graph

   for(int i=0;i<paths.size();i++)
   {
     cout<<paths[i] <<" ";
   }

   ///if graph contains cycle then topological sort is not possible


   return 0;
}

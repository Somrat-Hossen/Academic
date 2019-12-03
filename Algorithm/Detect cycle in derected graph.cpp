#include<bits/stdc++.h>
#define mx 100000
using namespace std;

int n,e,i,u,v,w;
int indeg[mx];
vector<int>edge[mx];
queue<int>que;
vector<int>path;
vector<string>paths;

map<string ,int>mps;
map<int ,string >mpi;
int no_of_node=0;


int Topological(int n)
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
           int ch=edge[pa][i];
           indeg[ch]--;
           if(indeg[ch]==0) que.push(ch);
        }
       no_of_node++;
     }
    // cout<<no_of_node<<n<<endl;
     return(no_of_node==n);
}


int main()
{
   freopen("in.txt","r",stdin);

   cin>>n;   ///no of edge


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


  if(Topological(node)) cout<<"Cycle is not found"<<endl;
  else cout<<"Cycle is found:"<<endl;

   return 0;
}


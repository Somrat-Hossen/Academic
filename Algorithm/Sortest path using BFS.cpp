#include<bits/stdc++.h>
#define pb push_back
#define mx 1000
using namespace std;

bool vis[mx];
vector<int>path;
vector<int>Adj[mx];
int parent[mx],dist[mx];

int findSpath(int src,int des)
{
    queue<int> q;

    q.push(src); vis[src]=1; dist[src]=0;

    while(!q.empty())
    {
        int father = q.front();
        q.pop();

        for(int i=0,len = Adj[father].size();i<len;i++)
        {
            if(vis[Adj[father][i]]==0)
            {
                int child = Adj[father][i];
                q.push(child);
                vis[child]  = 1;
                parent[child] = father;  ///We came node child from the node parrent
                dist[child] = dist[father]+1;  ///Distance of child from the starting node
            }
        }
    }
    if(vis[des]==0)  return -1;      ///not visited,no relation

    int tmp = des;
    path.push_back(des);
    while(tmp !=src)
    {
        tmp = parent[tmp];
        path.push_back(tmp);
    }
    reverse(path.begin(),path.end());

    return dist[des];
}
int main()
{
    ///freopen("in.in","r",stdin);
    int edge, u, v,src,des,node;
    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        Adj[u].pb(v);
        Adj[v].pb(u);
    }
    cin>>src>>des;
    int dis = findSpath(src,des);

    if(dis==-1)
        cout<<"There are not any path"<<endl;
    else
    {
        cout<<"The Minimum cost is : "<<dis<<endl;
        cout<<"Direction is:  ";

        for(auto x: path) cout<<x<<"----->";
        cout<<endl;
    }


    return 0;
}


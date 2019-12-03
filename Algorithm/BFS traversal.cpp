#include<bits/stdc++.h>
#include<iomanip>
#define PI acos(-1)
bool visited[1000];

int function(int n)
{

}
using namespace std;

int main()
{
   freopen("in.txt","r",stdin);
   queue<int>que;

   int u,v,edg,ver,src;//node means edge

  cout<<"Enter node and vertices "<<endl;
  cin >>ver>>edg;
  vector<int>vec[ver+1];
  for(int i=0;i<edg;i++)
  {
    cin>>u>>v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  for(int i=1;i<=ver;i++)
  {
    cout<<i<<" : ";
    for(int j=0;j<(int)vec[i].size();j++)
    {
    cout<<vec[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  /*for(int i=0;i<node;i++)
  {
      cout<<"[ "<<i<<" ] "<<" : ";
      for(int j=0;j<(int)vec[i].size();j++)
      {
        cout<<vec[i][j]<<"..>";
      }
      cout<<"NULL"<<endl;
  }*/




  cout<<"Enter  src vertix :"<<endl;
  cin>>src;
  que.push(src);
  cout<<"Traversal are: ";

  while(!que.empty())
  {
    int frnt=que.front(),s;
    if(visited[frnt]!=1)
    {
     visited[frnt]=1; cout<<frnt<<" ";
     for(int i=0;i<vec[frnt].size();i++)
     {
        s=vec[frnt][i];
         if(visited[s]!=1)
         {
           que.push(s);
         }
     }
    }
    que.pop();
   }

cout<<endl;
    return 0;
}



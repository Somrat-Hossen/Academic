#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class node ///node contains the node information
{
  public:
     int des,wet;
     node *next;

     node(int v,int w)
     {
        des=v;
        wet=w;
        next=nullptr;
     }
     node(){}///when only call,sometimes we create simple node
};


class Adjancy
{

  public:

   node *head;

     Adjancy()
     {
        head=nullptr;  ///All head of the list array will be initialized by null
     }


     void Addnode(int v, int w, node **tmp) ///tmp also is a pointer
     {
        node *newnode = new node(v,w);

        if(*tmp==NULL)
        {
           *tmp=newnode;///when head is null then ....
        }

        else
        {
           node *lastnode=*tmp;///keep track of the head node ,unchanged after first node

           while(lastnode->next !=NULL)
           {
              lastnode=lastnode->next;  ///Find the last node;
           }

           lastnode->next=newnode;
        }
   }

     void Display(node *tmp) ///show the list
     {
           while(tmp)
           {
              cout<<tmp->des<<"/"<<tmp->wet<<" ";
              tmp=tmp->next;
           }
         cout<<endl;
     }
};

Adjancy List[MAX];
int Matrix[MAX][MAX];///create list and array for edge

int main()
{
   freopen("in.txt","r",stdin);///Read the whole data from the input file

   string derection,weight;
   int vertex,u,v,w;

   cin>>derection>>weight>>vertex;

   if(weight=="Weighted") ///when the graph is  weighted
   {
      while(cin>>u>>v>>w)///while input is available
      {
          List[u].Addnode(v ,w, &List[u].head);///send the address of the ptr
          Matrix[u][v]=w;

          if(derection=="Undirected") ///if the graph is bidirectional
          {
             List[v].Addnode(u ,w, &List[v].head);
             Matrix[v][u]=w;
          }
      }


         cout<<"Adjacency list is: "<<endl;
         for(int i=1;i<=vertex;i++)
         {
             cout<<i<<": ";
            List[i].Display(List[i].head);
         }

        cout<<endl<<"Adjacency matrix is: "<<endl;
        for(int i=1;i<=vertex;i++)
        {
           cout<<i<<": ";
           for(int j=1;j<=vertex;j++)
           {
              cout<<Matrix[i][j]<<" ";
           }
           cout<<endl;
        }
   }

   else ///when the graph is  unweighted
   {
      while(cin>>u>>v)
      {
          List[u].Addnode(v ,0, &List[u].head);
          Matrix[u][v]=1;

          if(derection=="Undirected")
          {
             List[v].Addnode(u ,0, &List[v].head);
             Matrix[v][u]=1;
          }
      }

       ///print the list and matrix
        cout<<"Adjacency list is: "<<endl;
         for(int i=1;i<=vertex;i++)
         {
              cout<<i<<": ";
            List[i].Display(List[i].head);
         }

        cout<<endl<<"Adjacency matrix is: "<<endl;
        for(int i=1;i<=vertex;i++)
        {
            cout<<i<<": ";
           for(int j=1;j<=vertex;j++)
           {
              cout<<Matrix[i][j]<<" ";
           }
           cout<<endl;
        }
   }

   return 0;
}


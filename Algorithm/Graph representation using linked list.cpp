#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class node
{
  public:
     int des,wet;
     node *next;

     node(int v,int w)
     {
        des=v;
        wet=w;
        next=NULL;
     }
};


class adj_list
{

  public:

   node *head;

     adj_list()
     {
        head=NULL;  ///All head of the edge array will be initialized by null
     }


     void Addnode(int v, int w, node **tmp)
     {
        node *newnode = new node(v,w);

        if(*tmp==NULL)
        {
           *tmp=newnode;///when head is null then ....
        }

        else
        {
           node *lastnode=*tmp;///keep track of the head node

           while(lastnode->next !=NULL)
           {
              lastnode=lastnode->next;  ///Find the last node;
           }

           lastnode->next=newnode;
        }
   }

     void Display(node *tmp)
     {
           while(tmp!=NULL)
           {
              cout<<tmp->des<<"/"<<tmp->wet<<" ";
              tmp=tmp->next;
           }
         cout<<endl;
     }
};


int main()
{
   freopen("in.txt","r",stdin);
   ///freopen("out.txt","w",stdout);

   int vertex,ed,u,v,w;
    adj_list edge[MAX];

   cin>>vertex>>ed;

   for(int i=1;i<=ed;i++)
   {
      cin>>u>>v>>w;
      edge[u].Addnode(v ,w, &edge[u].head);
      edge[v].Addnode(u ,w, &edge[v].head);
   }

   for(int i=1;i<=vertex;i++)
   {
      cout<<i<<"---->";
      edge[i].Display(edge[i].head);
   }


   return 0;
}

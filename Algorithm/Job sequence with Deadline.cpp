#include <bits/stdc++.h>
#define mx 200005
typedef long long ll;
using namespace std;

struct Job
{
   int cost;
   int deadline;
}arr[mx];

int n;
int profit;
int taken[mx];
int slot[mx];

bool cmp(Job A , Job B)
{
   ///if first unit_price is greater than second one then not swap ,else swap
   return A.cost>B.cost;
   //return ((A.price)/(A.weight))<((B.price)/(B.weight));
}
bool Find_slot(int day)
{
   int i=day-1;

   ///0 means empty slot

   while(i>=0)
   {
      if( !slot[i])
      {
         slot[i]=1;///allocate slot
         return 1;
      }
      i--;
   }
   return 0;
}

void Max_profit()
{
   int i;
   for( i=0;i<n;i++)
   {
      int value=arr[i].cost;///considering all price and wet are integer value.if not then save in that data types
      int day=arr[i].deadline;

      int pos=Find_slot(day);
      if(pos) profit+=value;

   }
}

int main()
{

   freopen("int.txt","r",stdin);
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++)
    {
       cin>>arr[i].cost>>arr[i].deadline;
    }

    sort(arr,arr+n,cmp);

  /*  cout<<"After sorting according to the cost:"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<arr[i].cost<<" "<<arr[i].deadline<<endl;
    }*/

    Max_profit(); ///call the function to solve

    cout<<"Total Profit is: "<<profit<<endl;


    return 0;
}



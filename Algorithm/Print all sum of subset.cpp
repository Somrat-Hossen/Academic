#include <bits/stdc++.h>
#define mx 100005
typedef long long ll;
using namespace std;

int arr[mx];

int solution[mx];

void Display(int n)
{
  for(int i=0;i<n;i++)
  {
     if(solution[i])
     cout<<arr[i]<<" ";
  }
  cout<<endl;
}



void Subset_sum(int i,int target,int taken,int n, int total)
{
   ///if(i==n) return;

    solution[i]=1;

   if(taken+arr[i]==target)
   {
      Display(i+1);  /// because we have taken the present element
   }

   else if( ( taken+arr[i]+arr[i+1])<=target )
   {
      Subset_sum( i+1,target, taken+arr[i] ,n, total-arr[i]);  ///left subtree generate,taken the present element
   }

   if( (taken+total-arr[i]>=target) && (taken+arr[i+1] <=target )) /// skiping the present element
   {
      solution[i]=0;
      Subset_sum(i+1,target, taken, n, total-arr[i]);
   }
}

int main()
{

   freopen("in.txt","r",stdin);

	int target,n,total=0;

   cin>>n>>target;
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
      total+=arr[i];
   }

   Subset_sum(0, target ,0, n ,total);///starting index,targeted sum,taken sum initially



    return 0;
}


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



 void Max_heap(int arr[],int parent,int n) ///o(lon n)
 {
    ///parent means just index of parent node
    int left=2*parent;///left node
    int right=left+1;///right node
    int mx=parent;

    if(arr[left]>arr[parent] && left<=n) mx=left;
    else mx=parent;

    if(arr[right]>arr[mx] && right<=n) mx=right;

    if(mx!=parent)
    {
       swap(arr[parent],arr[mx]);
       Max_heap(arr,mx,n);
    }
 }
void Built(int arr[],int n)
{
   for(int i=n/2;i>=1;i--)
   {
      Max_heap(arr,i,n);
   }
}

int main()
{

   ///freopen("in.txt","r",stdin);
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

   int arr[]={0,1,4,3,7,8,9,10};///except first element 0
	int n=sizeof arr/sizeof arr[0];

   Built(arr,n-1);
	for(int i=1;i<=n-1;i++) cout<<arr[i]<<" ";






    return 0;
}


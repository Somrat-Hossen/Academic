#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

///We know that n/2th node is the last n/2 internal node so we started from n/2 in our loop

 void Max_heap(int arr[],int parent,int n) ///o(lon n)
 {
    ///parent means just index of parent node
    int left=2*parent;///left node
    int right=left+1;///right node
    int mx=parent;

    if(arr[left]>arr[parent] && left<=n) mx=left; ///for minheap change the greater operator to left
    else mx=parent;

    if(arr[right]>arr[mx] && right<=n) mx=right; ///for minheap change the greater operator to left

    if(mx!=parent)
    {
       swap(arr[parent],arr[mx]); ///if parent node is not the max one then swap
       Max_heap(arr,mx,n);       /// after swapping the current max parent can violate the properties,so call again
     }
 }
void Built(int arr[],int n)
{
   for(int i=n/2;i>=1;i--)
   {
      Max_heap(arr,i,n);
   }
}

void Heapsort(int arr[],int n)
{
   int len=n;

   Built(arr,n);

   for(int i=n;i>=2;i--) ///first element is sorted so except
   {
      swap(arr[1],arr[i]);
      len--;
      Max_heap(arr,1,len);
   }
}

int main()
{

   ///freopen("in.txt","r",stdin);
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

   int arr[]={0,7,4,3,7,8,2,9,10};///except first element 0
	int n=sizeof arr/sizeof arr[0];

   Heapsort(arr,n-1); ///except first one
	for(int i=1;i<=n-1;i++) cout<<arr[i]<<" ";  ///print the array after built max heap






    return 0;
}



#include<bits/stdc++.h>
#define mx 10000
using namespace std;


void Merge(int arr[],int l,int mid,int r)
{
  cout<<l<<" "<<r<<" "<<mid<<endl;
   int i,j,k,index=0;
   int tmp[mx];

   /* Merge the temp arrays back into arr[l..r]*/
    i = l; // Initial index of first subarray
    j = mid+1; // Initial index of second subarray
    while (i <=mid && j <=r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[index] = arr[i];
            i++;
        }
        else
        {
            tmp[index] = arr[j];
            j++;
        }
        index++; ///for both condition
    }

    /// Copy the remaining elements of Left arr, if thereare any
    while (i <=mid)
    {
        tmp[index] = arr[i];
        i++;
        index++;
    }

    /// Copy the remaining elements of right arr, if thereare any
    while (j <=r)
    {
        tmp[index] = arr[j];
        j++;
        index++;
    }

    for(i=l,k=0;i<=r;i++,k++)
    {
       arr[i]=tmp[k];
    }
}

void Merge_sort(int arr[], int lb, int ub)
{
   if(lb>=ub) return;
   int mid=(lb+ub)/2;

   Merge_sort(arr,lb,mid);///leftpart
   Merge_sort(arr,mid+1,ub);///right part

   Merge(arr,lb,mid,ub);  ///call the merge function
}








int main()
{

   int arr[]={8,15,42,79,86,121,5};
   int n=sizeof arr/sizeof arr[0];

   Merge_sort(arr,0,n-1);

   for(int i=0;i<n;i++) cout<<arr[i]<<" ";

  return 0;
}

#include<bits/stdc++.h>
using namespace std;

int arr[10000],tmp[10000];
int n;

void Merge(int arr[],int l,int mid,int r)
{
   int i,j,k;
   int len1=mid-l+1;
   int  len2=r-mid;

   int left[len1],right[len2];

   /// store in the left and right array.
   for(i=0;i<len1;i++)
   {
     left[i]=arr[i+l];
   }

   for(i=0;i<len2;i++)
   {
      right[i]=arr[mid+1+i];
   }

   /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < len1 && j <len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++; ///for both condition
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < len1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < len2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void Merge_sort( int lb, int ub)
{
   if(lb>=ub) return;
   int mid=(lb+ub)/2;

   Merge_sort(lb,mid);///leftpart
   Merge_sort(mid+1,ub);///right part

   Merge(arr,lb,mid,ub);  ///call the merge function
}








int main()
{
   freopen("in.txt","r",stdin);

   cin>>n;

   for(int i=0;i<n;i++) cin>>arr[i];

   Merge_sort(0,n-1);

   for(int i=0;i<n;i++) cout<<arr[i]<<" ";

  return 0;
}

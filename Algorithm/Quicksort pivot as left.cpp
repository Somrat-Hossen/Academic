#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[],int left,int right )
{
        int pivot ,i,j;
        pivot=arr[left];
        i=left+1;///because left element is pivot
        j=right;

      while(i<=j && j>left)
      {
         if(arr[i]>pivot)
         {
           swap(arr[i],arr[j]);
            j--;
         }
        else i++;
      }
      swap(arr[left],arr[j]); ///
      return (j);///same as arr [i-1] out of while loop
}


void Quicksort(int arr[],int lb,int ub)
{

   if(lb>=ub)
   {
      return;
   }

   int pos=Partition(arr,lb,ub);

   Quicksort(arr,lb,pos-1);
   Quicksort(arr,pos+1,ub);

}




int main()
{
   freopen("in.txt","r",stdin);
   int arr[100],n;

   cin>>n;
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }


   Quicksort(arr,0,n-1);

   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }

   return 0;
}


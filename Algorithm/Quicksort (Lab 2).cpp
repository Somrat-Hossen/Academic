
///Given an unsorted array of list.sort the array using quick sort
///at first choose the first element as pivot ,it this element is
///even the choose right as pivot ,else choose left as pivot


#include<bits/stdc++.h>
#define Max 10000
using namespace std;

int Partition(int arr[],int left,int right )
{
   int pivot,i,j,k;

   pivot=arr[left]; /// selecting last element as pivot

   if(pivot %2==0)///if the pivot is even then choose right as pivot
   {
         i=left; /// index of smaller element
         pivot=arr[right];

         for(j=left;j<right;j++)
         {
            if(arr[j]<=pivot) /// If current element is smaller than or equal to pivot
            {
               swap(arr[j],arr[i]);
               i++;   /// increment index of smaller element
            }
         }
       swap(arr[right],arr[i]);
       return i;
   }

   else
   {
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
   //int arr[]={3 ,44 ,38 ,5 ,47 ,15 ,36 ,26 ,27, 2, 46, 4 ,19 ,50, 48};
  // int n=sizeof arr/sizeof arr[0];
    freopen("in.txt","r",stdin);

    int n;
    int arr[Max];
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];

   Quicksort(arr,0,n-1);

   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }

   return 0;
}


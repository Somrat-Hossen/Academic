#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[],int left,int right )
{


   int pivot,i,j,k;

   pivot=arr[right]; /// selecting last element as pivot
   i=left;          /// index of smaller element
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
   int arr[]={1,6,7,4,8,5,3,2};
   int n=sizeof arr/sizeof arr[0];
   cout<<n<<endl;

   Quicksort(arr,0,n-1);

   for(int i=0;i<n;i++)
   {
      cout<<arr[i]<<" ";
   }

   return 0;
}


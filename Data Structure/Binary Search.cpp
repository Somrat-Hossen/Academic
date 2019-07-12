#include<bits/stdc++.h>
using namespace std;


void Sort(int arr[],int n)
{
   ///Bubble sort
    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<n-i-1;j++)
       {
          if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
       }
    }

}


int Binary_Search(int arr[],int n,int item)
{

   Sort(arr,n);
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

   int lb=0,ub=n-1,mid;

       while(lb<=ub)
       {
          mid=(ub+lb)/2;

          if(arr[mid]==item) return mid;

          if(arr[mid]<item) lb=mid+1;
          else ub=mid-1;
       }
       return -1;
}










int main()
{
   int arr[]={7,9,8,3,4,2,1,5,6};

   int n=sizeof(arr)/sizeof(arr[0]);

   int item;
   cin>>item;

  int pos= Binary_Search(arr,n,item);

   if(pos==-1) puts("Data is not present in the array:");
  else cout<<"Data is present in the array and index is:"<<pos+1<<endl;


   return 0;

}

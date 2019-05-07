#include<bits/stdc++.h>
using namespace std;


void Selectionsort(int arr[],int n)
{

   for(int i=0;i<n-1;i++)
   {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
      {
        swap(arr[i],arr[j]);
      }
    }

   }
}




int main()
{
  int arr[]={8,15,42,79,86,121,5};
  int n=sizeof arr/sizeof arr[0];

  Selectionsort(arr,n);

  for(int i=0;i<n;i++) cout<<arr[i]<<" ";

 return 0;
}


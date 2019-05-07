#include<bits/stdc++.h>
using namespace std;


void Bubblesort(int arr[],int n)
{

   for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
    }

   }
}




int main()
{
  int arr[]={8,15,42,79,86,121,5};
  int n=sizeof arr/sizeof arr[0];

  Bubblesort(arr,n);

  for(int i=0;i<n;i++) cout<<arr[i]<<" ";

 return 0;
}

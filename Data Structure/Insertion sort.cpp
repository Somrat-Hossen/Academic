#include<bits/stdc++.h>
using namespace std;

void Insert_sort(int arr[],int n)
{

   for(int i=1;i<n;i++)
   {
        int item=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>item)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=item;
   }

   for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}

int main()
{
  int arr[]={3,2,6,4,8,7,9,5};
  int n=sizeof arr/sizeof arr[0];

  Insert_sort(arr,n);

  return 0;
}

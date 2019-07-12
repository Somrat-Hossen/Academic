#include<bits/stdc++.h>
using namespace std;


int Linear_Search(int arr[],int n,int item)
{
   ///Bubble sort
    for(int i=0;i<n;i++)
    {
       if(arr[i]==item) return(i);
    }
    return -1;

}


int main()
{
   int arr[]={7,9,8,3,4,2,1,5,6};

   int n=sizeof(arr)/sizeof(arr[0]);

   int item;
   cin>>item;

  int pos= Linear_Search(arr,n,item);

   if(pos==-1) puts("Data is not present in the array:");
  else cout<<"Data is present in the array and index is:"<<pos+1<<endl;


   return 0;

}


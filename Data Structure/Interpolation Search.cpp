#include<bits/stdc++.h>
using namespace std;

int Interpolation(int arr[],int n,int item)
{

   int lbl=0,ubl=n-1,pos;


    while(lbl<=ubl && item>=arr[lbl] && item<=arr[ubl])
    {

      if(lbl==ubl)
      {
         if(arr[lbl]==item) return lbl;
         return -1;
      }
       pos=lbl+((ubl-lbl)*(item-arr[lbl]))/(arr[ubl]-arr[lbl]);

       if(arr[pos]==item) return pos;
       if(arr[pos]<item) lbl=pos+1;
       else ubl=pos-1;

    }
    return -1;

}

int main()
{
  int arr[]={5,6,10,12,15,17};
  int n=sizeof(arr)/sizeof (arr[0]);

  int Find=Interpolation(arr,n,18);

  if(Find==-1) cout<<"Not found"<<endl;
  else cout<<"Found element and in position:"<<Find<<endl;



 return 0;
}

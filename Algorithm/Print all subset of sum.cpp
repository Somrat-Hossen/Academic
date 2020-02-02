 #include<bits/stdc++.h>
 #define mx 1000

using namespace std;

int solution[100];
int arr[mx];

void Print(int n)
{
   for(int i=0;i<n;i++)
   {
      cout<<solution[i]<<" ";
   }
   cout<<endl;
}

  void Subset_sum(int arr[] , int pos, int target, int taken, int n)
  {
      if (target==taken) Print(n);

          // generate nodes along the breadth
      for (int i = pos; i <n; i++)
      {
          if (taken + arr[i] <= target)
          {
               solution[i]=1;
               taken += arr[i];
               // consider next level node (along depth)
               Subset_sum(arr, i + 1, target, taken, n);
               solution[i]=0;   ///without taking the current element
               taken -= arr[i];  /// so subtract the taken element
          }
      }
  }


 int main()
 {
    freopen("in.txt","r",stdin);

     int i, n, target;

     cin>>n>>target;

     for(i=0;i<n;i++) cin>>arr[i];

    Subset_sum(arr, 0, target, 0, n);

     return 0;
 }

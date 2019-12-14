#include <bits/stdc++.h>
#define mx 200005
typedef long long ll;
using namespace std;

struct Greedy
{
   double price;
   double weight;
   double unit_price;
}arr[mx];

int n,capasity;
double profit;
int taken[mx];

bool cmp(Greedy A , Greedy B)
{
   ///if first unit_price is greater than second one then not swap ,else swap
   return A.unit_price>B.unit_price;
   //return ((A.price)/(A.weight))<((B.price)/(B.weight));
}

void fractional_Knapsack()
{
  int i;
   for( i=0;i<n;i++)
   {
      int value=arr[i].price;///considering all price and wet are integer value.if not then save in that data types
      int wet=arr[i].weight;
      double unit=arr[i].unit_price;

      if(wet>capasity) ///if remain capasity is less than the current wet ,then take remain amount
      {
         profit+= double(capasity*unit);
         taken[i]=capasity;///taken array contains ,which  thing we taken ,and amount
         capasity=0;
         break;
      }
      else
      {
         profit+=value;
         taken[i]=wet;
         capasity-=wet;
      }
   }
}


int main()
{

   freopen("int.txt","r",stdin);
   ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);

    cin>>n>>capasity;

    for(int i=0;i<n;i++)
    {
       cin>>arr[i].price>>arr[i].weight;
       arr[i].unit_price=arr[i].price/arr[i].weight;
    }

    sort(arr,arr+n,cmp);

    cout<<"After sorting according to the unit price:"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<arr[i].price<<" "<<arr[i].weight<<" "<<arr[i].unit_price<<endl;
    }

    fractional_Knapsack(); ///call the function to solve

    cout<<"Total Profit is: "<<profit<<endl;


    return 0;
}


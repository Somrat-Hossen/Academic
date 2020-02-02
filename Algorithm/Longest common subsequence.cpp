#include<bits/stdc++.h>
#define mx 10000
using namespace std;

int dp[mx+1][mx+1];	/// dp table stores solution to already computed sub-problems
string str1,str2;
string longest="";   ///For actual subsequence

///Bottom up  manner

int find_LCS(int i, int j)
{
      if(str1[i]=='\0' or str2[j]=='\0') return 0;

      if(dp[i][j]) return dp[i][j]; ///if already computed,dp[i][j] not zero means computed .

      if(str1[i]==str2[j]) ///two char same so try to take the next char of the two string
      {
         return dp[i][j]=1+find_LCS(i+1,j+1);
      }
      else
      {
            ///two char are not same so try to take first char of first str1,secondly first char
            /// of second str2 and return the maximum length between them

         return dp[i][j]=max(find_LCS(i+1,j) ,find_LCS(i,j+1));
      }
}

void Print_LCS(int i,int j)
{
      if(str1[i]=='\0' or str2[j]=='\0')
      {
         cout<<longest<<endl;
         return;  ///back to main function
      }

      if(str1[i]==str2[j])
      {
          longest+=str1[i];
          Print_LCS(i+1,j+1);
      }

      else
      {
           if(dp[i+1][j]>dp[i][j+1]) Print_LCS(i+1,j);
           else Print_LCS(i,j+1);
      }
}

string ans="";
int total=0;

void print_All_sequence(int i,int j)
{
      if(str1[i]=='\0' or str2[j]=='\0')
      {
         cout<<ans<<endl;
         total++;
         return;
      }
      if(str1[i]==str2[j])
      {
         ans+=str1[i];
         print_All_sequence(i+1,j+1);
         ans.erase(ans.end()-1); ///Delete last character from the taken string
      }
      else
      {
         if(dp[i+1][j]>dp[i][j+1]) print_All_sequence(i+1,j);
         else if(dp[i+1][j]<dp[i][j+1]) print_All_sequence(i,j+1);

         else /// if length is equal from the two part ,then we consider both two
         {
            print_All_sequence(i+1,j);
            print_All_sequence(i,j+1);
         }
      }
}


int main()
{


   cin>>str1>>str2;


    cout<<"Length of the longest common subsequence is: "<<(find_LCS(0, 0))<<endl;
    cout<<"Longest string of the longest common subsequence is: ";Print_LCS(0,0);cout<<endl;

    ///for all subsequence whose length is same
    ///string X = "ABCBDAB", Y = "BDCABA"; four different subsequence

    cout<<"All subsequence are :"<<endl;
    print_All_sequence(0, 0);
    cout<<"Total subsequence is : "<<total<<endl;


   return 0;
}

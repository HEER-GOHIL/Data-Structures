#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a>b)?a:b;
}
int lcs(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}
int main() 
{ 
    string s1 = "AGGTAB"; 
    string s2 = "GXTXAYB"; 
    cout << "Length of LCS is " 
         << lcs(s1,s2);
      
    return 0; 
} 
 

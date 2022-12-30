#include<bits/stdc++.h>
using namespace std;

int ed(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }  
    for(int j=0;j<=n;j++)
    {
        dp[j][0]=j;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1 + min((dp[i-1][j]),min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    } 
    return dp[m][n];
}

int main()
{
    string s1="SATURDAY";
    string s2="SUNDAY";
    int m=3,n=3;
    cout<<ed(s1,s2,m,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int f(int n,int m,string &s,string &t)
{
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int j=1;j<=m;j++) dp[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});               
            }
        }
    }
    return dp[n][m];
    
}
int main()
{
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    
    cout<<f(n,m,s,t);
}
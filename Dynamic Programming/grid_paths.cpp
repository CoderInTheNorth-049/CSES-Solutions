#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<char>> &grid,int n)
{
    if(grid[1][1]=='*' || grid[n][n]=='*') return 0;
    int mod=1e9+7;
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(grid[i][j]=='.')
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%mod;
                
            }
        }
    }
    return dp[n][n];
}
int main()
{
    int n;cin>>n;
    vector<vector<char>> grid(n+1,vector<char>(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<f(grid,n)<<endl;

}
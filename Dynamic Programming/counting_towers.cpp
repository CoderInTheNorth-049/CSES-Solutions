#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int maxn=1e6+1;
vector<vector<int>> dp(maxn,vector<int>(2));
vector<int> ans(maxn);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<maxn;i++)
    {
        dp[i][0]=(2ll*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1]=(4ll*dp[i-1][1] + dp[i-1][0])%mod;
        ans[i] = (dp[i-1][0]+dp[i-1][1])%mod;
    }
    
    int t;cin>>t;
    while(t--)
    {
    int n;cin>>n;
    cout<<ans[n]<<endl;
    }
    return 0;
}
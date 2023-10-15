#include<bits/stdc++.h>
using namespace std;

int f(int n,int x,vector<int> &coins)
{
    int mod=1e9+7;
    vector<long long> dp(x+1);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if((j-coins[i-1]>=0)) dp[j]+=dp[j-coins[i-1]];
            dp[j]%=mod;
        }
    }
    return dp[x];
}
int main()
{
    int n,x;cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    cout<<f(n,x,coins)<<endl;
}
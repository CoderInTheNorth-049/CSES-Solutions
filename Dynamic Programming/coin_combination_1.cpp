#include<bits/stdc++.h>
using namespace std;

int f(int n,int x,vector<int> &coins)
{
    int mod=1e9+7;
    vector<long long> dp(x+1);
    for(auto &it:coins)
    {
       if(it<=x) dp[it]=1;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i-coins[j]>=0)) dp[i]+=dp[i-coins[j]];
            dp[i]%=mod;
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
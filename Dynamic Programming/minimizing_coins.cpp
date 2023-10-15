#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &coins,int sum)
{
    vector<long long> dp(sum+1,1e9);
    int n=coins.size();
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=sum)dp[coins[i]]=1;
    }

    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>=0)dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
    }
    return dp[sum]>=1e9?-1:dp[sum];
}
int main()
{
    int n,k;cin>>n>>k;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    cout<<f(coins,k)<<endl;

}
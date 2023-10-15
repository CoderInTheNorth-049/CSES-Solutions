#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    int mod=1e9+7;

    vector<long long> dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j<0) continue;
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
    return dp[n];
}
int main()
{
    int n;cin>>n;
    cout<<f(n)<<endl;
}
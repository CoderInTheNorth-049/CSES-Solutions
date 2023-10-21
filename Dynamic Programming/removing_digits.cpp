#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    fill(dp.begin()+1,dp.begin()+min(10,n+1),1);
    for(int i=10;i<=n;i++)
    {
        string s=to_string(i);
        for(int j=0;j<s.size();j++)
        {
            dp[i]=min(dp[i],1+dp[i-(s[j]-'0')]);
        }
    }
    return dp[n];
}
int main()
{
    int n;cin>>n;
    cout<<f(n)<<endl;
}
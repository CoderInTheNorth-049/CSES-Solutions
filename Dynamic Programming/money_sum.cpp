#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int m=accumulate(v.begin(),v.end(),0);
    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=0;i<n;i++) dp[i][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j-v[i]>=0) dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    vector<int> ans;
    for(int i=1;i<=m;i++)
    {
        if(dp[n][i]==1) ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for(auto &it:ans) cout<<it<<" ";
    cout<<endl;
}
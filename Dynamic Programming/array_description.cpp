#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int f(int n, int m, vector<int> &v)
{
    vector<vector<long long>> dp(n+1,vector<long long>(m+2));

   if(v[0]==0)
   {
    for(int i=1;i<=m;i++) dp[1][i]=1;
   }
   else{
    dp[1][v[0]]=1;
   }

   for(int i=2;i<=n;i++)
   {
    for(int j=1;j<=m;j++)
    {
        if(v[i-1]!=0 && v[i-1]!=j) dp[i][j]=0;
        else if(v[i-1]==0){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        }
        else{
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
            continue;
        }
    }
   }

   long long ans=0ll;
   for(int i=1;i<=m;i++) ans+=dp[n][i],ans%=mod;
   return ans;

}
int main()
{
    int n,m;cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<f(n,m,v)<<endl;
    return 0;
}
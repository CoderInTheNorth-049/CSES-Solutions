#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int mod=1e9+7;

void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> dp(1<<n,vector<ll>(2));
    dp[0][0]=1;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            for(int mask=0;mask<(1<<n);mask++){
                dp[mask][1]=dp[mask^(1<<i)][0];
                if(i && !(mask&(1<<i)) && !(mask&(1<<(i-1)))){
                    dp[mask][1]+=dp[mask^(1<<(i-1))][0];
                }
                dp[mask][1]%=mod;
            }
            for(int mask=0;mask<(1<<n);mask++){
                dp[mask][0]=dp[mask][1];
            }
        }
    }
    cout<<dp[0][0]<<'\n';
}

int32_t main(){
    solve();
}

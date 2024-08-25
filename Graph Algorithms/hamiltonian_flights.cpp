#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int mod=1e9+7;

void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<ll>> g(n+1);
    ll x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
    }
    g[0].push_back(1);
    vector<vector<ll>> dp(n+1,vector<ll>(1<<n,-1));

    function<ll(ll,ll)> f=[&](ll node,ll mask){
        if(mask==((1<<(n))-1)){
            if(node==n) return 1ll;
            else return 0ll;
        }
        if(node==n) return 0ll;
        if(dp[node][mask]!=-1) return dp[node][mask];
        ll ans=0;
        for(auto &it:g[node]){
            
            if(mask&(1<<(it-1))) continue;
            ans+=f(it,mask|(1<<(it-1)));
            ans%=mod;
        }
        return dp[node][mask]=ans;

    };
    cout<<f(0,0)<<'\n';
}

int32_t main(){
    solve();
}
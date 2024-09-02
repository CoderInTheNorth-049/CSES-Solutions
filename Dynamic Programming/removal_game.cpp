#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    ll sum=0;
    for(int i=0;i<n;i++) cin>>v[i],sum+=v[i];
    vector<vector<ll>> dp(n,vector<ll>(n,-1));

    function<ll(ll,ll)> f=[&](ll l, ll r){
        if(l==r) return v[l];
        if(dp[l][r]!=-1) return dp[l][r];
        ll ans=0;
        ans=v[l]-f(l+1,r);
        ans=max(ans,v[r]-f(l,r-1));
        return dp[l][r]=ans;
    };
    cout<<(sum+f(0,n-1))/2<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
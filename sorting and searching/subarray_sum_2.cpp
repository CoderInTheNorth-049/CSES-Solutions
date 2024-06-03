#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> v(n);
    for(auto &it:v) cin>>it;
    map<ll,ll> mp;
    mp[0]=1;
    ll sum=0,ans=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        ans+=mp[sum-x];
        mp[sum]+=1;
    }
    cout<<ans<<'\n';
}

int32_t main(){
    solve();
}
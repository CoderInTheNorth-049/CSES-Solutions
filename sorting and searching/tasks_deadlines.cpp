#include<bits/stdc++.h>
using namespace std;

using ll=long long;

#define ff first
#define ss second

void solve(){
    ll n;cin>>n;
    vector<ll> a(n),d(n);
    for(int i=0;i<n;i++) cin>>a[i]>>d[i];
    sort(a.rbegin(),a.rend());
    ll ans=accumulate(d.begin(),d.end(),0ll);
    for(int i=0;i<n;i++){
        ans-=(i+1)*a[i];
    }
    cout<<ans<<'\n';
}

int32_t main(){
    solve();
}
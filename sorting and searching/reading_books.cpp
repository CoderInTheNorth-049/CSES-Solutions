#include<bits/stdc++.h>
using namespace std;

using ll=long long;

#define ff first
#define ss second

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(auto &it:v) cin>>it;
    sort(v.begin(),v.end());
    ll sum=accumulate(v.begin(),v.begin()+n-1,0ll);
    ll lg=v[n-1];
    if(lg>sum) cout<<2*lg<<'\n';
    else cout<<lg+sum<<'\n';
}

int32_t main(){
    solve();
}
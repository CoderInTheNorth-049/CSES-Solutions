#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]^=v[i-1];
    }
    ll l,r;
    while(q--){
        cin>>l>>r;
        cout<<(ll)(v[r]^v[l-1])<<'\n';
    }
}

int32_t main(){
    solve();
}
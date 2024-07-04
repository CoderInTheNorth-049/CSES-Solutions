#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
using ll=long long;

ll power(ll base, ll idx){
    ll res=1;
    base=base%M;
    if(base==0) return 0;
    while(idx){
        if(idx&1) res=(res*base)%M;
        idx>>=1;
        base=(base*base)%M;
    }
    return res;
}

vector<ll> fact(1e6+1);
void solve(){
    ll a,b;cin>>a>>b;
    ll ans=(fact[a]*power(fact[b],M-2))%M * power(fact[a-b],M-2);
    cout<<ans%M<<'\n';
}

int main(){
    ll t=1;
    cin>>t;
    fact[0]=fact[1]=1;
    for(ll i=2;i<=1e6;i++){
        fact[i]=(fact[i-1]*i)%M;
    }
    while(t--){
        solve();
    }
}
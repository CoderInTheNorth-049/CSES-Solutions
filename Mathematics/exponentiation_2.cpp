#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll power(ll base, ll idx,ll M=1e9+7){
    if(base==0 && idx==0) return 1;
    ll res=1;
    base=base%M;
    if(base==0) return 0;
    while(idx){
        if(idx&1) res=(res*base)%M;
        idx>>=1;
        base=(base*base)%M;
    }
    return res%M;
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll powbc=power(b,c,1e9+6);
    cout<<power(a,powbc)<<endl;
}

int main(){
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
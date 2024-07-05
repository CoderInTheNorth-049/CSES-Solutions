#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=1e9+7;

#define ff first
#define ss second
vector<ll> fact(2e6+1,0);

ll power(ll base, ll idx){
    ll res=1;
    base%=M;
    if(base==0) return 0;
    while(idx){
        if(idx&1) res=(res*base)%M;
        base=(base*base)%M;
        idx>>=1;
    }
    return res;
}

ll nCr(ll n,ll r){
    ll num=fact[n];
    ll den=(fact[r]*fact[n-r])%M;
    return (num*power(den,M-2))%M;
}

void solve(){
    fact[0]=fact[1]=1;
    for(ll i=1;i<=2e6;i++) fact[i]=(fact[i-1]*i)%M;
    ll n,m;cin>>n>>m;
    cout<<nCr(m+n-1,n-1)<<endl;
   
}

int main(){
    solve();
}
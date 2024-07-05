#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=1e9+7;

#define ff first
#define ss second
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

void solve(){
    vector<ll> fact(1e6+1,0);
    fact[0]=fact[1]=1;
    for(ll i=1;i<=1e6;i++) fact[i]=(fact[i-1]*i)%M;
    string s;cin>>s;
    ll n=s.size();
    map<char,ll> mp;
    for(auto &it:s) mp[it]+=1;

    ll num=fact[n];
    ll den=1;
    for(auto &it:mp) den=(den*fact[it.ss])%M;
    cout<<(num*power(den,M-2))%M<<endl;
}

int main(){
    solve();
}
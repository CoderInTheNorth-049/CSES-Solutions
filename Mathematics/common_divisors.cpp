#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    vector<ll> v(n),seen(1e6+1,0);
    for(ll i=0;i<n;i++) cin>>v[i],seen[v[i]]++;
    
    for(ll i=1e6;i>0;i--){
        ll cnt=0;
        for(ll j=i;j<=1e6;j+=i){
            cnt+=seen[j];
        }
        if(cnt>1){
            cout<<i<<endl;
            return;
        }
    }
}

int main(){
    solve();
}
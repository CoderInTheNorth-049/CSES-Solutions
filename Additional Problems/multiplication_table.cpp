#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve(){
    ll n;cin>>n;
    ll l=1,r=n*n;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        ll ct=0;
        for(int i=1;i<=n;i++){
            ct+=min(n,mid/i);
        }
        if(ct>=(n*n+1)/2){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans<<'\n';
}

int32_t main(){
    solve();
}
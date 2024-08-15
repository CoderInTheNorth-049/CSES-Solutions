#include<bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll l=0,r=0,ans=0,distinct=0;
    map<ll,ll> mp;

    while(r<n){
        if(mp[v[r]]==0){
            distinct+=1;
        }
        mp[v[r]]+=1;
        while(distinct>k){
            mp[v[l]]-=1;
            if(mp[v[l]]==0) distinct-=1;
            l+=1;
        }
        ans+=r-l+1;
        r+=1;
    }
    cout<<ans<<'\n';
}
 
int32_t main(){
    solve();
}
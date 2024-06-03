#include<bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
void solve(){
    ll n,x;cin>>n;
    map<ll,ll> mp;
    ll sum=0,ans=0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        cin>>x;
        sum=((sum+x)%n+n)%n;
        ans+=mp[sum];
        mp[sum]+=1;
        
    }
    cout<<ans<<'\n';
}
 
int32_t main(){
    solve();
}
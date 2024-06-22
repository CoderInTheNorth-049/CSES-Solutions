#include<bits/stdc++.h>
using namespace std;

using ll=long long;

#define ff first
#define ss second

void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<ll,set<pair<ll,ll>>> mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mp[v[i]+v[j]].insert({i+1,j+1});
        }
    }
    for(auto &it:mp){
        ll req=x-it.ff;
        if(!mp.count(req)) continue;
        for(auto &i:it.ss){
            auto itr=upper_bound(mp[req].begin(),mp[req].end(),make_pair(i.ss+1,i.ss));
            if(itr==mp[req].end()) continue;
            else{
                cout<<i.ff<<" "<<i.ss<<" "<<(*itr).ff<<" "<<(*itr).ss<<endl;
                return;
            }
        }
        
    }
    cout<<"IMPOSSIBLE\n";
}

int32_t main(){
    solve();
}
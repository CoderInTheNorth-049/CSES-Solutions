#include<bits/stdc++.h>
using namespace std;

using ll=long long;

#define ff first
#define ss second

void solve(){
    ll n;cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].ff>>v[i].ss;
    ll ans=0,ct=0,req;
    vector<pair<pair<ll,ll>,ll>> mst;
    for(int i=0;i<n;i++){
        mst.push_back(make_pair(make_pair(v[i].ff,-1),i));
        mst.push_back(make_pair(make_pair(v[i].ss,1),i));
    }
    sort(mst.begin(),mst.end());
    for(int i=0;i<mst.size();i++){
        ct+=-1*mst[i].ff.ss;
        ans=max(ans,ct);
    }
    vector<ll> room(n);
    set<ll> avail,inuse;
    for(int i=1;i<=ans;i++) avail.insert(i);

    for(int i=0;i<2*n;i++){
        if(mst[i].ff.ss==-1){
            req=*avail.begin();
            room[mst[i].ss]=req;
            inuse.insert(req);
            avail.erase(req);
        }else{
            req=room[mst[i].ss];
            inuse.erase(req);
            avail.insert(req);
        }
    }
    cout<<ans<<'\n';
    for(auto &it:room) cout<<it<<" ";
    cout<<'\n';
}

int32_t main(){
    solve();
}
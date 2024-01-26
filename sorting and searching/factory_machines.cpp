#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,t;cin>>n>>t;
    vector<ll> v(n);
    ll mn=1e10;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mn=min(mn,v[i]);
    }

    auto f=[&](ll mid){
        ll ct=0;
        for(int i=0;i<n;i++){
            ct+=(mid/v[i]);
        }
        if(ct>=t) return true;
        else return false;
    };

    ll l=1,r=mn*t;
    ll ans=1e18;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(f(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void solve()
{
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    auto f=[&](ll mid)->bool{
        ll sum=0,ct=0;
        for(int i=0;i<n;i++){
            if(sum+v[i] > mid){
                ct+=1;
                sum=v[i];
            }else{
                sum+=v[i];
            }
        }
        ct+=1;
        if(ct>k) return false;
        else return true;

    };

    ll l=*max_element(v.begin(),v.end()), r=1e17;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    solve();
    return 0;
}
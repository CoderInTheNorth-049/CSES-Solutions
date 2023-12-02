#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll ans=1e9;
void f(int idx,ll curr_sum,ll sum,vector<ll> &v,int n)
{
    if(idx==n) return;
    f(idx+1,curr_sum,sum,v,n);
    ans = min(ans,abs(sum-2*curr_sum));
    f(idx+1,curr_sum+v[idx],sum,v,n);
    ans = min(ans,abs(sum-2*curr_sum));
}

int main()
{
    int n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll sum=accumulate(v.begin(),v.end(),0ll);
    f(0,0,sum,v,n);
    cout<<ans<<endl;
}
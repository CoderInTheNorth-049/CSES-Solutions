#include<bits/stdc++.h>
using namespace std;
using ll=long long;

class Solution{
    int n;
    vector<ll> arr,seg;
public:
    Solution(vector<ll>& v,int n){
        this->n=n;
        this->arr=v;
        seg.resize(n);
    }
    void pre(){
        ll fact=sqrt(n);
        for(int i=0;i<=n-fact;i+=fact){
            ll mn=1e18;
            for(int j=i;j<i+fact && j<n;j++){
                mn=min(mn,arr[j]);
            }
            seg[i]=mn;
        }
    }
    ll RMQ(ll l,ll r){
        ll fact=sqrt(n);
        ll i=l,itr=0;
        ll ans=1e18;
        while(i<=r){
            ans=min(ans,arr[i]);
            i++;
            if(seg[i]) break;
        }
        ll temp=i;
        for(itr=i;itr<=r;itr+=fact){
            if(itr+fact-1>r) break;
            ans=min(ans,seg[itr]);
            temp=itr;
        }
        for(itr=temp;itr<=r;itr++){
            ans=min(ans,arr[itr]);
        }
        return ans;
    }
};

int32_t main(){
    ll n,q;cin>>n>>q;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    Solution s(v,n);
    s.pre();
    while(q--){
        ll l,r;cin>>l>>r;
        cout<<s.RMQ(l-1,r-1)<<'\n';
    }
}
#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
using ll=long long;

void solve(){
   ll n,x;cin>>n>>x;
   vector<ll> v(n);
   for(int i=0;i<n;i++) cin>>v[i];

   auto f=[&](ll l, ll r){
    ll sz=r-l+1;
    vector<ll> ans;

    for(int i=0;i<(1<<sz);i++){
        ll sum=0;
        for(int j=0;j<sz;j++){
            if(i&(1<<j)) sum+=v[l+j];
        }
        ans.push_back(sum);
    }
    return ans;
   };

   vector<ll> left = f(0,n/2-1);
   vector<ll> right = f(n/2,n-1);
   sort(left.begin(),left.end());
   sort(right.begin(),right.end());

   ll ans=0;
   for(int i=0;i<left.size();i++){
    int idx1=lower_bound(right.begin(),right.end(),x-left[i])-right.begin();
    int idx2=upper_bound(right.begin(),right.end(),x-left[i])-right.begin();
    ans+=idx2-idx1;
   }
   cout<<ans<<'\n';
}

int main(){
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
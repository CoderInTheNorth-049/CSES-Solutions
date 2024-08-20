#include<bits/stdc++.h>
using namespace std;

using ll=long long;

#define ff first
#define ss second

void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pair<ll,ll>> dp(1<<n);
    dp[0]={1,0};

    for(int i=1;i<(1<<n);i++){
        dp[i]={21,0};

        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                pair<ll,ll> temp = dp[i^(1<<j)];

                if(temp.ss+v[j] > x){
                    temp.ff+=1;
                    temp.ss=min(temp.ss,v[j]);
                }else temp.ss+=v[j];
                dp[i] = min(dp[i],temp);
            }
        }
    }
    cout<<dp.back().ff<<'\n';
}

int32_t main(){
    solve();
}
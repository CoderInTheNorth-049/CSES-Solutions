#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
    ll n,q;cin>>n>>q;
    vector<vector<ll>> grid(n+1,vector<ll>(n+1));
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if(c=='*') grid[i][j]=1;
            else grid[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
        }
    }
    ll x1,y1,x2,y2;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        cout<<grid[x2][y2]-grid[x2][y1-1]-grid[x1-1][y2]+grid[x1-1][y1-1]<<'\n';
    }
}

int32_t main(){
    solve();
}
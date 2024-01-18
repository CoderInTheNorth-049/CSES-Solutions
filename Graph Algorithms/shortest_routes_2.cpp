#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> grid(n,vector<ll>(n,1e18));
    int x,y;
    ll w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        x--;y--;
        grid[x][x]=0,grid[y][y]=0;
        grid[x][y]=min(grid[x][y],w);
        grid[y][x]=min(grid[y][x],w);
    } 

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][k]!=1e18 && grid[k][j]!=1e18){
                    if(grid[i][j]>grid[i][k]+grid[k][j]){
                        grid[i][j]=grid[i][k]+grid[k][j];
                    }
                }
            }
        }
    }
    while(q--){
        cin>>x>>y;
        x--;y--;
        if(grid[x][y]==1e18) cout<<-1<<'\n';
        else cout<<grid[x][y]<<'\n';
    }
}
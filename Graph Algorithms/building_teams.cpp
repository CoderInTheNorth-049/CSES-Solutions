#include<bits/stdc++.h>
using namespace std;

bool dfs(int parent,int node,vector<vector<int>> &gp,vector<int> &vis,int team){
    vis[node]=team;
    for(auto &it:gp[node]){
        if(vis[it]==0){
            bool poss=dfs(node,it,gp,vis,3-team);
            if(!poss) return false;
        }
        else if(it!=parent  && vis[it]==team) return false;
    }
    return true;
}

int main(){
    int n,m,x,y;cin>>n>>m;
    vector<vector<int>> gp(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    vector<int> vis(n+1);
    bool poss=false;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
            poss=dfs(0,i,gp,vis,1);
        }
        if(!poss){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    
        for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
        cout<<endl;
    
}
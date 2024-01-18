#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &gp, vector<bool> &vis){
    vis[node]=true;
    for(auto &it:gp[node]){
        if(!vis[it]){
            dfs(it,gp,vis);
        }
    }
}

int main(){
    int n,m,x,y;cin>>n>>m;
    vector<vector<int>> gp(n+1);
    vector<bool> vis(n+1);
    vector<int> ans;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i,gp,vis);
        }
    }

    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" "<<ans[i-1]<<endl;
    }
}
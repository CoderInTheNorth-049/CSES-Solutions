#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gp;
vector<bool> vis,recstack,v;
vector<int> ans;

bool dfs(int node){
    vis[node]=recstack[node]=true;
    for(auto &it:gp[node]){
        if(!vis[it]){
            if(dfs(it)) return true;
        }
        else if(recstack[it]) return true;
    }
    recstack[node]=false;
    return false;
}

void f(int node){
    v[node]=true;
    for(auto &it:gp[node]){
        if(!v[it]) f(it);
    }
    ans.push_back(node);
}
int main(){
    int n,m,x,y;cin>>n>>m;
    gp.resize(n+1);
    vis.resize(n+1);
    recstack.resize(n+1);
    v.resize(n+1);
    
    for(int i=0;i<m;i++){
        cin>>x>>y;
        gp[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
        if(!v[i]){
            f(i);
        }
    }
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    cout<<endl;
}
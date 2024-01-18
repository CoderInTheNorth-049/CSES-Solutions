#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n,vector<vector<int>> &gp){
    vector<int> dist(n+1,1e9),par(n+1);

    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &it:gp[x]){
            if(dist[it]==1e9){
                dist[it]=1+dist[x];
                par[it]=x;
                q.push(it);
            }
        }
    }
    vector<int> ans;
    if(dist[n]==1e9) return ans;
    int curr=n;
    while(1){
        ans.push_back(curr);
        if(curr==1) break;
        curr=par[curr];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n,m,x,y;cin>>n>>m;
    vector<vector<int>> gp(n+1);
    
    for(int i=0;i<m;i++){
        cin>>x>>y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    vector<int> ans=bfs(n,gp);
    if(ans.empty()){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<ans.size()<<endl;
        for(auto &it:ans) cout<<it<<" ";
        cout<<endl;
    }
}
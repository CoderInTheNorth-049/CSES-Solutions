#include<bits/stdc++.h>
using namespace std;

void dijkstra(int n,vector<vector<pair<int,int>>> &gp){
    priority_queue<pair<long long,int>> pq;
    vector<long long> dist(n+1,1e16);
    vector<bool> vis(n+1);
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(auto &it:gp[x]){
            int node=it.first;
            int w=it.second;

            if(dist[node]>dist[x]+1ll*w){
                dist[node]=dist[x]+1ll*w;
                pq.push({-1*dist[node],node});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>> gp(n+1);
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        gp[x].push_back({y,w});
        //gp[y].push_back({x,w});
    }
    dijkstra(n,gp);
}
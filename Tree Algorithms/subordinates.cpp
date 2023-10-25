#include<bits/stdc++.h>
using namespace std;

void dfs(int child,int parent,vector<vector<int>> &tree,vector<int> &depth)
{
    for(auto &it:tree[child])
    {
        if(it==parent) continue;
        dfs(it,child,tree,depth);
        depth[child]+=(depth[it]+1);
        
    }
}
int main()
{
    int n;cin>>n;
    vector<vector<int>> tree(n);
    vector<int> depth(n);
    int x;
    for(int i=1;i<n;i++)
    {
        cin>>x;x--;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    dfs(0,-1,tree,depth);
    
    for(auto &it:depth) cout<<it<<" ";
    cout<<endl;
}
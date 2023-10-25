#include<bits/stdc++.h>
using namespace std;

void dfs(int child,int parent,vector<vector<int>> &tree,vector<int> &done,int &ans)
{
    for(auto &it:tree[child])
    {
        if(it==parent) continue;
        dfs(it,child,tree,done,ans);
        if(done[it]==0 && done[child]==0)
        {
            done[it]=done[child]=1;
            ans+=1;
        }
    }
}
int main()
{
    int n;cin>>n;
    vector<vector<int>> tree(n);
    vector<int> done(n);
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        x-=1;y-=1;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int ans=0;
    dfs(0,-1,tree,done,ans);
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> depth(200000);

void dfs(int child,int parent,vector<vector<int>> &tree)
{
    for(auto &it:tree[child])
    {
        if(it==parent) continue;
        depth[it]=1+depth[child];
        dfs(it,child,tree);
    }
}
int main()
{
    int n;cin>>n;
    vector<vector<int>> tree(n);
    int x,y;
   for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        x--;y--;
        tree[y].push_back(x);
        tree[x].push_back(y);
    }
    dfs(0,-1,tree);

    int mx_depth=-1,mx_node;
    for(int i=0;i<n;i++)
    {
        if(depth[i]>mx_depth)
        {
            mx_depth=depth[i];
            mx_node=i;
        }
    }
    fill(depth.begin(),depth.end(),0);
    dfs(mx_node,-1,tree);
    cout<<*max_element(depth.begin(),depth.begin()+n)<<endl;
}
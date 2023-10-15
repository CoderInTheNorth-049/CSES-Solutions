#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<string> &grid,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m) return;
    if(grid[i][j]=='#') return;
    grid[i][j]='#';
    dfs(i-1,j,grid,n,m);
    dfs(i+1,j,grid,n,m);
    dfs(i,j-1,grid,n,m);
    dfs(i,j+1,grid,n,m);

}
int main()
{
    int n,m;cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='#') continue;
            else
            {
                dfs(i,j,grid,n,m);
                ans+=1;
            }
        }
    }
    cout<<ans<<endl;
}
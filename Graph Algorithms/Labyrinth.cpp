#include<bits/stdc++.h>
using namespace std;

bool bfs(pair<int,int> strt,vector<string> &grid,int n,int m,string &ans,vector<vector<bool>> &vis)
{
    auto isvalid=[&](int x,int y)->bool
    {
        if(x<0 || y<0 ||x>=n || y>=m) return false;
        if(grid[x][y]=='#' || vis[x][y]==true) return false;
        return true;
    };

    queue<pair<int,int>> q;
    q.push(strt);
    vis[strt.first][strt.second]=true;
    vector<vector<char>> br(n,vector<char>(m));

    

    while(!q.empty())
    {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        if(grid[a][b]=='B')
        {
            while(1)
            {
                ans+=br[a][b];
                if(ans.back()=='L')b++;
                if(ans.back()=='R')b--;
                if(ans.back()=='U')a++;
                if(ans.back()=='D')a--;
                if(a==strt.first && b==strt.second) break;
            }
            return true;
        }
        if(isvalid(a,b-1)) br[a][b-1]='L',q.push({a,b-1}),vis[a][b-1]=true;
        if(isvalid(a,b+1)) br[a][b+1]='R',q.push({a,b+1}),vis[a][b+1]=true;
        if(isvalid(a-1,b)) br[a-1][b]='U',q.push({a-1,b}),vis[a-1][b]=true;
        if(isvalid(a+1,b)) br[a+1][b]='D',q.push({a+1,b}),vis[a+1][b]=true;
    }
    return false;

}
int main()
{
    int n,m;cin>>n>>m;
    vector<string> grid(n);
    pair<int,int> strt;
    vector<vector<bool>> vis(n,vector<bool>(m));

    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='A') strt={i,j};
        }
    }
    string ans="";
    
    if(bfs(strt,grid,n,m,ans,vis))
    {
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    else cout<<"NO"<<endl;
    
}
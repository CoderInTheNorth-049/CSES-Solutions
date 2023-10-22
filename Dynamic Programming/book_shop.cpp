#include<bits/stdc++.h>
using namespace std;

int f(int n,int x,vector<int> &price,vector<int> &pages)
{
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            int take=0,notake=0;
            if(price[i-1]<=j) take=max(dp[i-1][j],pages[i-1]+dp[i-1][j-price[i-1]]);
            notake=dp[i-1][j];
            dp[i][j]=max(take,notake);
        }
    }
    return dp[n][x];

}
int main()
{
    int n,x;cin>>n>>x;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    cout<<f(n,x,price,pages)<<endl;
}
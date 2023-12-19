#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int f(int n){
    if(n*(n+1)%4) return 0;
    int target = n*(n+1)/4;
    vector<vector<long long>> dp(n+1,vector<long long>(target + 1));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            dp[i][j]=dp[i-1][j];
            int left = j-i;
            if(left>=0)
            {
                (dp[i][j]+=dp[i-1][left]) %= mod;
            }
        }
    }
    return dp[n][target];
}
int main(){
    int n;cin>>n;
    cout<<f(n)<<endl;
}
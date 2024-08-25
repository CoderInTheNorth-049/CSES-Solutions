#include<bits/stdc++.h>
using namespace std;

#define int long long
int dp[20][10][2][2];

int solve(string &num,int n,int prev_digit,int idx,int leading_zeros,int tight){
    if(idx==n) return 1;
    if(prev_digit!=-1 && dp[idx][prev_digit][leading_zeros][tight]!=-1) return dp[idx][prev_digit][leading_zeros][tight];

    int lb=0;
    int ub=9;
    if(tight) ub=num[idx]-'0';
    int ans=0;

    for(int i=lb;i<=ub;i++){
        if(i==prev_digit && i!=0) continue;
        if(i==prev_digit && i==0 && leading_zeros==0) continue;
        ans+=solve(num,n,i,idx+1,leading_zeros&i==0,tight&(i==ub));
    }
    return dp[idx][prev_digit][leading_zeros][tight]=ans;
}
int32_t main(){
    string a,b;cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    int ans=solve(b,b.size(),-1,0,1,1);
    memset(dp,-1,sizeof(dp));
    ans-=solve(a,a.size(),-1,0,1,1);

    auto f=[&](string &s){
        for(int i=1;i<s.size();i++) if(s[i]==s[i-1]) return false;
        return true;
    };

    if(f(a)) ans+=1;
    cout<<ans<<'\n';
}
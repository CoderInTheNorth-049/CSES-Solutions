#include<bits/stdc++.h>
using namespace std;

void toh(int n,int from,int aux,int to,vector<pair<int,int>> &ans)
{
    if(n==0) return;

    toh(n-1,from,to,aux,ans);
    ans.push_back({from,to});
    toh(n-1,aux,from,to,ans);
}
int main(){

int n;cin>>n;

vector<pair<int,int>> ans;
toh(n,1,2,3,ans);
cout<<ans.size()<<endl;
for(auto &it:ans) cout<<it.first<<" "<<it.second<<endl;
}
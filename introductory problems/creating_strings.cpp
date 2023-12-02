#include<bits/stdc++.h>
using namespace std;

void permute(string &s,int l,int r,vector<string> &ans)
{
    if(l==r) ans.push_back(s);
    else{
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permute(s,l+1,r,ans);
            swap(s[l],s[i]);
        }
    }
    
}

int main()
{
    string s;cin>>s;
    vector<string> ans;
    permute(s,0,s.size()-1,ans);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout<<ans.size()<<endl;
    for(auto &it:ans) cout<<it<<endl;
}
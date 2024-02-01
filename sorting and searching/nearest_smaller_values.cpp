#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<int> &v){
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push({v[i],i});
            continue;
        } 
        int temp=st.top().first;
        while(!st.empty() && temp>v[i]){
            ans[st.top().second]=i+1;
            st.pop();
            if(st.empty()) break;
            temp=st.top().first;
        }
        st.push({v[i],i});
    }
    for(auto &it:ans) cout<<it<<" ";
    cout<<endl;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(auto &it:v) cin>>it;
    solve(n,v);
    return 0;
}
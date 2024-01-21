#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<vector<int>> gp;
vector<bool> vis,recstack;

bool dfs(int node){
    vis[node]=recstack[node]=true;
    st.push(node);
    for(auto &it:gp[node]){
        if(!vis[it]){
            bool poss=dfs(it);
            if(poss){
                return true;
            }
        }
        else if(recstack[it]){
            st.push(it);
            return true;
        }
    }
    recstack[node]=false;
    st.pop();
    return false;
}

void extract(){
    stack<int> ans;
    ans.push(st.top());
    int stop=st.top();
    st.pop();
    while(1){
        ans.push(st.top());
        if(st.top()==stop) break;
        st.pop();
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
}

int main(){
    int n,m,x,y;cin>>n>>m;
    gp.resize(n+1);
    vis.resize(n+1);
    recstack.resize(n+1);

    for(int i=0;i<m;i++){
        cin>>x>>y;
        gp[x].push_back(y);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i)){
                extract();
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";


}
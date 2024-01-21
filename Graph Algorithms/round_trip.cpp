#include<bits/stdc++.h>
using namespace std;

stack<int> st;
vector<vector<int>> gp;
vector<bool> vis;

bool dfs(int parent, int node){
    vis[node]=true;
    for(auto &it:gp[node]){
        if(!vis[it]){
            st.push(it);
            bool poss=dfs(node,it);
            if(poss) return true;
            st.pop();
        }
        else if(it!=parent){
            st.push(it);
            return true;
        }
    }
    return false;
}

int main(){
    int n,m,x,y;cin>>n>>m;
    gp.resize(n+1);
    vis.resize(n+1);

    for(int i=0;i<m;i++){
        cin>>x>>y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            st.push(i);
            bool poss=dfs(-1,i);
            if(poss){
                vector<int> ans;
                int stop = st.top();
                ans.push_back(st.top());
                st.pop();
                while(1){
                    ans.push_back(st.top());
                    if(st.top()==stop)
                    {
                        cout<<ans.size()<<endl;
                        for(auto &it:ans){
                            cout<<it<<" ";
                        }
                        cout<<endl;
                        return 0;
                    }
                    st.pop();
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";


}
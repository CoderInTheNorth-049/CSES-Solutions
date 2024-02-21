#include<bits/stdc++.h>
using namespace std;


class DSU{
    int n;
    vector<int> par,rank;
public:
    DSU(int n){
        this->n=n;
        par.resize(n,-1);
        rank.resize(n,1);
    }
    int find(int i){
        if(par[i]==-1) return i;
        return par[i]=find(par[i]);
    }
    bool add(int x,int y){
        int a=find(x);
        int b=find(y);
        if(a==b) return false;
        if(rank[a]>rank[b]){
            par[b]=a;
            rank[a]+=rank[b];
        }
        else{
            par[a]=b;
            rank[b]+=rank[a];
        }
        return true;
    }
    int crank(int x){
        return rank[find(x)];
    }
};

int main(){
    int n,m;cin>>n>>m;
    DSU d(n+1);
    int x,y;
    int comp=n,mx=2;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        bool ret=d.add(x,y);
        if(ret) comp-=1;
        mx=max(mx,d.crank(x));
        cout<<comp<<" "<<mx<<endl;
    }

}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class SegTree{
private:
    int n;
    vector<ll> arr,sgt;
public:
    SegTree(vector<ll> &v){
        this->n=v.size();
        this->arr=v;
        sgt.resize(4*n+40);
    }
    int left(int index){
        return 2*index;
    }
    int right(int index){
        return 2*index+1;
    }
    void updateCurrNode(int index){
        sgt[index]=sgt[left(index)]+sgt[right(index)];
    }
    void buildTree(int index,int start,int end){
        if(start==end){
            sgt[index]=arr[start];
            return;
        }
        int mid=(start+end)/2;
        buildTree(left(index),start,mid);
        buildTree(right(index),mid+1,end);
        updateCurrNode(index);
    }
    void update(int index,int start,int end,int tIndex,int tValue){
        if(start==end){
            arr[start]=tValue;
            sgt[index]=tValue;
            return;
        }
        int mid=(start+end)/2;
        if(mid>=tIndex){
            update(left(index),start,mid,tIndex,tValue);
        }else{
            update(right(index),mid+1,end,tIndex,tValue);
        }
        updateCurrNode(index);
    }
    ll query(int index,int start,int end,int qL,int qR){
        if(start>=qL && end<=qR) return sgt[index];
        if(start>qR || end<qL) return 0ll;

        int mid=(start+end)/2;
        ll ansL=query(left(index),start,mid,qL,qR);
        ll ansR=query(right(index),mid+1,end,qL,qR);
        return ansL+ansR;
    }
};

int32_t main(){
    ll n,q;cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    SegTree sg(v);
    sg.buildTree(1,1,n);
    while(q--){
        ll type;cin>>type;
        if(type==1){
            ll k,u;cin>>k>>u;
            sg.update(1,1,n,k,u);
        }else{
            ll l,r;cin>>l>>r;
            cout<<sg.query(1,1,n,l,r)<<'\n';
        }
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>> v;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x<(k-1)){
            v.push_back({x,i});
        }
    }
    sort(v.begin(),v.end());
    n=v.size();

    auto bs=[&](int l,int r,int val){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid].first==val) return v[mid].second;
            else if(v[mid].first > val) r=mid-1;
            else l=mid+1;
        }
        return -1;
    };

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(k-v[i].first-v[j].first <=0) continue;
            int pos=bs(j+1,n-1,k-v[i].first-v[j].first);
            if(pos==-1) continue;
            else{
                cout<<v[i].second<<" "<<v[j].second<<" "<<pos<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
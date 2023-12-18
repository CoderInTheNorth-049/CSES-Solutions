#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int it1=0,it2=-1;
    int sum=0,ans=0;
    while(it1<n && it2<n){
        if(sum>k){
            sum-=v[it1];
            it1+=1;
        }
        else{
            if(sum==k) ans+=1;
            it2+=1;
            sum+=v[it2];
        }
    }
    cout<<ans<<endl;
}
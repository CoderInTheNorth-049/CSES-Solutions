#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int x,n;cin>>x>>n;

    set<int> pos{0,x};
    multiset<int> dist{x};
    int l;
    for(int i=0;i<n;i++)
    {
        cin>>l;
        auto itr1=pos.upper_bound(l);
        auto itr2=itr1;
        itr1--;
        dist.erase(dist.find(*itr2 - *itr1));
        dist.insert(l - *itr1);
        dist.insert(*itr2 - l);
        pos.insert(l);
        auto ans=dist.end();
        ans--;
        cout<<*ans<<" ";
    }
    cout<<endl;
}
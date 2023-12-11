#include<bits/stdc++.h>
using namespace std;

char f(long long n){
    long long len=1,p=9,pw=1;

    while((n-p)>0){
        n-=p;
        len+=1;
        pw*=10ll;
        p=9*pw*len;
    }
    n-=1;
    long long x=n/len;
    long long y=n%len;
    long long ans=pw+x;
    string res=to_string(ans);
    return res[y];
}


int main(){
    int t;cin>>t;
    long long n;
    while(t--)
    {
        cin>>n;
        cout<<f(n)<<endl;
    }
}
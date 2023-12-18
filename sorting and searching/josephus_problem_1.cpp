#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    while(q.size()!=1){
        int j=1;
        while(j<2){
            q.push(q.front());
            q.pop();
            j+=1;
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<q.front()<<endl;

}
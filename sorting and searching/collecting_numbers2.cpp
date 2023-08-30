#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define BUG
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

class solution
{
    public:
    solution()
    {

    }

    void solve()
    {
        int n,q;cin>>n>>q;
        vector<int> num(n+1),loc(n+1);
        map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            loc[num[i]]=i;
        }
        int og=1;
        for(int i=1;i<n;i++)
        {
            if(loc[i]>loc[i+1]) og+=1;
        }
        //bug(og);
        int x,y;
        while(q--)
        {
            cin>>x>>y;
            if(x==y)
            {
                cout<<og<<endl;
                continue;
            }
            
            if(num[x]-1>=1) mp[num[x]-1]=num[x];
            if(num[x]+1<=n) mp[num[x]]=num[x]+1;
            if(num[y]-1>=1) mp[num[y]-1]=num[y];
            if(num[y]+1<=n) mp[num[y]]=num[y]+1;

            for(auto it:mp) if(loc[it.first]>loc[it.second]) og-=1;

            swap(num[x],num[y]);
            loc[num[x]]=x;
            loc[num[y]]=y;

            for(auto it:mp) if(loc[it.first]>loc[it.second]) og+=1;
            cout<<og<<endl;
            mp.clear();
        }
    }
};

int32_t main()
{

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solution test;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto start = chrono::high_resolution_clock::now();
    long long t;
    t = 1;

    //cin >> t;

    cout << fixed << setprecision(9);
    // primes=siuu();
    while (t-- > 0)
    {
        test.solve();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

#ifndef WAQT
    bug(time_taken);
#endif

    return 0;
}
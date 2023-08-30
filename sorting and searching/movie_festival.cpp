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
        int n;cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].second>>v[i].first;
        }
        sort(v.begin(),v.end());
        int ans=1;
        int it1=0,it2=1;
        while(it2<n && it1<n)
        {
            if(v[it1].first<=v[it2].second)
            {
                ans+=1;
                it1=it2;
                it2+=1;
            }
            else{
                it2+=1;
            }
        }
        // for(int i=0;i<n-1;i++)
        // {
        //     if(v[i].first<=v[i+1].second) ans+=1;
        // }
        cout<<ans<<endl;
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
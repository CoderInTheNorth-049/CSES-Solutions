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
        long long n;cin>>n;
        if(((n&1) && ((n+1)/2)%2==1) || (!(n&1) && (n/2)%2==1))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            long long sum=(n*(n+1))/2;
            sum/=2;
            set<long long> s1,s2;
            for(long long i=1;i<=n;i++) s1.insert(i);
            for(long long i=n;i>=1;i--)
            {
                if(sum-i>=0)
                {
                    s2.insert(i);
                    s1.erase(i);
                    sum-=i;
                }
            }
            cout<<s1.size()<<endl;
            for(auto &it:s1) cout<<it<<" ";
            cout<<endl;
            cout<<s2.size()<<endl;
            for(auto &it:s2) cout<<it<<" ";
            cout<<endl;
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
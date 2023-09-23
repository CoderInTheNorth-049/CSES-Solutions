#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//--------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll=long long;
#define ff first
#define ss second
//------------------------------------------------------
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

// *(o_set.find_by_order(1)) -> 2nd smallest num
//  o_set.order_of_key(4) -> idx of 4 or no. of elements less than 4
//  o_set.erase(o_set.find(2));
//  multi.erase(multi.upper_bound(val))
//======================================================================
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
//======================================================================


struct HASH
{
    size_t operator()(const pair<ll,ll> &x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};



class solution
{
    
    public:
    solution()
    {
        
    }

    void solve()
    {
     ll n,a,b;cin>>n>>a>>b;
     vector<ll> v(n);
     for(int i=0;i<n;i++) cin>>v[i];

     vector<ll> prefix(n+1);
     for(int i=1;i<=n;i++)
     {
        prefix[i]=prefix[i-1]+v[i-1];
     }
    ll ans=-1e18;
    multiset<ll> mst;
    for(int i=a;i<=n;i++)
    {
        if(i>b)
        {
            mst.erase(mst.find(prefix[i-b-1]));
        }
        mst.insert(prefix[i-a]);
        ans=max(ans,prefix[i]-*mst.begin());
    }
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